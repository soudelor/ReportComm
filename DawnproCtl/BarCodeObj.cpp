// BarCodeObj.cpp: implementation of the BarCodeObj class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BarCodeObj.h"
#include "basefun.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const int bcNoAscii      = 0x00000100;  /* avoid text in output */
const float SHRINK_AMOUNT = 0.05;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
BOOL isdigit(char ch)
{
	if ( ch <='9' && ch>='0' )
		return TRUE;
  return  FALSE;
}
BOOL islower(char ch)
{
	if ( ch <='z' && ch>='a' )
		return TRUE;
  return  FALSE;
}
BOOL isuper(char ch)
{
	if ( ch <='Z' && ch>='A' )
		return TRUE;
  return  FALSE;
}

int DigitOrdinal( char ch )
{
   return int(ch)-int('0');
}
int AlphaOrdinal( char ch ) 
{
	int result=-1;
    if ( isupper(ch) )
        result = ch-'A';
    else if ( islower(ch) )
        result = ch-'a';
    return result;
}
int iff( BOOL istrue, int val1, int val2)
{
	int rtn = 0;
    if (istrue) rtn = val1;
    else rtn = val2;
	return rtn;
}

int Parse_CharPos( char* start,double& f1, double& f2,char& ch)
{
    char part[10];
    char *s=NULL,*e=NULL;
    int i=0,loop=1;
    double f=0.0;
	
    s = start;
    e = s;
    i =1;
    while( loop && *e != 0)
    {
		switch(*e)
		{			
        case (0):
		case (' '):
            {
                ch = *(e-1);
                i++;			
                break;
            }
		case (':'):
            {
				memset(part,0,10);
                strncpy(part, s, e-s);
                f = atof(part);
				if(i==1)
                   f1 = f;
				else
                   f2 = f;
                
                s = e+1;
                i++;
                if ( 3 == i )
                {
                    ch = *s;
                    i++;
					loop = 0;
                    break;
                }
            }
		}
        e++;
    }
    return i-1;

}

CBarcodeObj::CBarcodeObj()
{
	pBC = NULL;
	Initial();
}
CBarcodeObj::CBarcodeObj(char* text)
{
	Create(text);
	Initial();
}
void CBarcodeObj::Initial()
{
	m_BarFontSize = 20;
	m_BarTextAlign = 0;
}
CBarcodeObj::~CBarcodeObj()
{
	Destory();
}

void CBarcodeObj::Create(char* text)
{
	if (pBC != NULL)
		Destory();
	pBC = ::Barcode_Create(text);
	if (pBC)
		pBC->margin = 0;
}

void CBarcodeObj::Destory()
{
	if(pBC)
		::Barcode_Delete(pBC);
	pBC = NULL;
}

int CBarcodeObj::Draw(HDC hDC)
{
	int i, j, barlen, delta ;
	double f1, f2, fsav, t1,t2;
    char mode ; // text below bars
    double scalef, xpos, x0, y0, yr ;
    char* ptr;
    char c,ch;

	fsav = 0;
    scalef = 1;
    mode = '-';
	
	if ( NULL == pBC->partial || NULL == pBC->textinfo) 
    {
        pBC->error = -1;        
        return -1;
    }

	// 计算条码长度
	
    barlen = DigitOrdinal(pBC->partial[0]);

    ptr = pBC->partial+1;
	while ( *ptr != 0 ) 
    {
        ch = *ptr;
        if (isdigit( ch ) )
            barlen += DigitOrdinal(ch);
		else if ( islower(ch) ) // ch in ['a'..'z','A'..'Z'] //
            barlen += (AlphaOrdinal(ch) +1);
        ptr++;
    } 
   
	if ( 0 == pBC->scalef )
	{
        if (0 == pBC->width) pBC->width = barlen; /* default */

        t1 = pBC->width;
        t2 = barlen;
        pBC->scalef = t1 / t2;        
	}
	scalef = pBC->scalef;

    if (0 == pBC->width) 
		pBC->width = int(barlen * scalef +1);
	if (0 == pBC->height) 
		pBC->height = int(80 * scalef);

	xpos = pBC->margin + DigitOrdinal(pBC->partial[0]) * scalef;

	ptr = pBC->partial+1;
    i=1;
    while ( *ptr != 0 )
    {
        /* special cases: '+' and '-' */
        ch = *ptr;
        if ( ( ch == '+' ) ||( ch == '-') )
		{
            mode = ch;
            /* don't count it */ i++;
            ptr++;
            continue;
        }
        /* j is the width of this bar/space */
        if (isdigit (ch)) 
			j = DigitOrdinal(ch);
        else
			j = AlphaOrdinal(ch)+1;
        if ( i % 2 != 0 )
		{
			/* bar */
            x0 = pBC->xoff + xpos + (j*scalef)/2;
            y0 = pBC->yoff + pBC->margin;
            yr = pBC->height;
            if ( 0 == (pBC->flags & bcNoAscii) )
            { /* leave space for text */
                if (mode = '-') 
				{
                    /* text below bars: 10 points or five points */
					/*
                    delta = int(iff(isdigit(ch) , 10 , 5) * scalef);
                    y0 = y0 + delta;
                    yr = yr - delta;
					*/
                }
                else /* '+' */
                {					
                    /* text above bars: 10 or 0 from bottom, and 10 from top */
					/*
                    y0 = y0 + int(iff( isdigit(ch),10, 0) * scalef);
                    yr = yr - int(iff( isdigit(ch),20,10) * scalef);
					*/
                }
            }			
			HPEN hPen=::CreatePen(PS_INSIDEFRAME,1,RGB(0,0,0)); 
			LOGBRUSH logbrush;
			logbrush.lbStyle = BS_SOLID;
			logbrush.lbColor = RGB(j,j,i);
			logbrush.lbHatch = 5 ;
			HBRUSH hBrush = ::CreateBrushIndirect(&logbrush);
			HPEN hOldpen = (HPEN)::SelectObject(hDC,hPen); 
  			HBRUSH hbrush = (HBRUSH)::SelectObject(hDC,GetStockObject(BLACK_BRUSH)); 
			//HBRUSH hbrush = (HBRUSH)::SelectObject(hDC,&logbrush); 
			::ExRectangle(hDC,pBC->xoff+xpos,y0,pBC->xoff+xpos+j*scalef,y0+yr); 

			::SelectObject(hDC,hbrush);			
			::SelectObject(hDC,hOldpen);
			::DeleteObject(hBrush);
			::DeleteObject(hPen);
		}
        xpos = xpos + (j * scalef);
        ptr++;
        i++;
    }

	int fh = this->m_BarFontSize;

	HFONT hFont=CreateFont(0-fh,0,0,0,0,FALSE,FALSE,0, ANSI_CHARSET,
					OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,
					DEFAULT_PITCH|FF_MODERN,"宋体");
	HFONT hOldFont = (HFONT)SelectObject( hDC, hFont );
	fsav = fh; /* 保留下次字体使用 */

	/*显示文字*/
	/*如果是显示在文字的左右，则绘制出文字*/
	int ftop =  int ( (y0 + y0 + yr)/2.0 - fh/2.0 +0.5);
	ptr = pBC->ascii;
	int tlen = strlen(ptr);
	RECT rc; //取文字的长度，便于计算文字位置	
	rc.bottom=rc.left=rc.right=rc.top=0;
	::DrawTextEx(hDC,ptr,strlen(ptr),&rc,DT_NOCLIP|DT_SINGLELINE|DT_CALCRECT,NULL);
	int textwidth = rc.right - rc.left;

	if(m_BarTextAlign&BF_LEFT)
		::ExTextOut(hDC, pBC->xoff-textwidth-textwidth/tlen,ftop, ptr, strlen(ptr));	
	else if(m_BarTextAlign&BF_RIGHT)
		::ExTextOut(hDC, pBC->xoff+xpos+textwidth/tlen,ftop,ptr,strlen(ptr));
    mode = '-'; /* 缺省显示在上方 */
    if ( 0 == (pBC->flags & bcNoAscii)  )
	{    
       // k:=0; // k is the "previous font size"         
        ptr = pBC->textinfo;
        while (1)
        {
            if (NULL == ptr) break;

            while ( *ptr == ' ') ptr++;

            ch = *ptr;

            if (0==ch)  break;

            if (ch == '+' || ch =='-') 
			{
                mode = ch;
                continue;
			}
			if (Parse_CharPos( ptr, f1,f2,c) != 3 )
				continue;
			
			f2 = this->m_BarFontSize;//字体的大小
            if (fsav != f2) 
            {                
				::SelectObject(hDC,hOldFont);
				DeleteObject( hFont );
				hFont = CreateFont(-f2,0,0,0,0,FALSE,FALSE,0, ANSI_CHARSET,
					OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,
					DEFAULT_PITCH|FF_MODERN,"宋体");
				hOldFont = (HFONT)SelectObject( hDC, hFont );						
            }
			
			fsav = f2; /* 保留下次字体使用 */
			
			if (m_BarTextAlign&BF_TOP)/*文字的位置*/
				::ExTextOut(hDC, pBC->xoff + f1 * scalef + pBC->margin,pBC->yoff + pBC->margin -f2, &c ,1);
			else if(m_BarTextAlign&BF_BOTTOM)
				::ExTextOut(hDC, pBC->xoff + f1 * scalef + pBC->margin,pBC->yoff + pBC->margin + pBC->height, &c , 1);		
            ptr = strchr( ptr, ' ');
			
		}
	}



	::SelectObject(hDC,hOldFont);
	::DeleteObject( hFont );
	return 0;
}
int CBarcodeObj::Encode(int CodeType,int flags)
{
	//int rtn = Barcode_Encode( pBC, (Ord(CodeType)- Ord(bcAny)) || flags);
	int rtn = 0;
	if ( NULL == pBC ) 
		return NULL;
	rtn = ::Barcode_Encode( pBC, flags);
    pBC->flags = flags;	
	return rtn;
}
int CBarcodeObj::IntVersion()
{
	return 0;
}
int CBarcodeObj::SetPosition(int Width,int Height,int XOffset,int YOffset,double ScaleFactor)
{
	return Barcode_Position(pBC, Width,Height, XOffset, YOffset, ScaleFactor);;
}
void CBarcodeObj::SetText(char* text)
{
	Create(text);
}
char* CBarcodeObj::GetVersion()
{
	return NULL;
}
