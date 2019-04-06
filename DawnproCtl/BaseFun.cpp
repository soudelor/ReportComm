// BaseFun.cpp: implementation of the BaseFun class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BaseFun.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const char ROWHEIGHT[] = "100";
const char COLWIDTH[] = "200";
short FONTSIZE = 25;
double nLogPixelX = 10;//每毫米的逻辑点数
double nLogPixelY = 10;
double MM = 10.0; //屏幕上10个点一个毫米
int xPhysicalOffset = 0;
int yPhysicalOffset = 0;
int nPhysicalWidth = 1970;
int nPhysicalHeight = 2900;

//long ReadItem(const char* buf,char* name, char proname[][], char provalue[],int& num)
long ReadItem(const char* buf,char* name, CPropertys& propertys)//读取标签的属性
{
	if (NULL==buf) return 0;

	const char* pbuf = buf;
	short i=0;
	BYTE flag=0;

	BYTE NBUF = 16;
	char str1[128],str2[128];
	while ( *pbuf != '<' && *pbuf!=0)
	{
		pbuf ++ ;continue;
	}
	try
	{
		while (*pbuf!='>')
		{		 
			if(*pbuf ==' ' || *pbuf == '<' )//去掉NAME前面的空格,引号,<
			{
				*pbuf++;		
				continue;//去掉空格	
			}
			if ( 0 == flag ) //读NAME内容
			{
				while(*pbuf !=' ' && *pbuf !='>')
				{
					name[i++] = *pbuf++;				
				}
				name[i] = 0;
				flag = 1;
				continue;
			}
			
			if ( 1 == flag ) //读属性
			{
				i = 0;
				str1[i] = 0;
				
				while( '>' != *pbuf && '=' != *pbuf ) //去掉PROPERTY前面的空格
				{				
					str1[i++] = *(pbuf++);					
				}
				str1[i] = 0;
				flag = 2; //读属性的值				
				continue;
			}

			if ( 2 == flag ) //读属性的值
			{
				pbuf++; //去掉等号
				i = 0;
				str2[i] = 0;
				if ( 0x22 == *pbuf ) //等于" 
				{
					pbuf++;
					while( 0x22 != *pbuf && i<NBUF ) //引号开始，引号结束
					{
						str2[i++] = *pbuf++;						
					}			
					pbuf++;//去掉引号
				}
				else
				{
					while(*pbuf==' ') 
					{ pbuf++;continue;	}//去掉空格
					while( ' ' != *pbuf && '>' != *pbuf && i<NBUF) //空格结束
					{
						str2[i++] = *pbuf++;
					}
				}
				str2[i]=0;				
				flag = 1;	
				if( 0 != str1[0] || 0 != str2 )
				{
					Property property;
					sscanf(str1,"%s",str1);
					sscanf(str2,"%s",str2);
					ToLowerCase(str1);//换成小写
					ToLowerCase(str2);//换成小写
					property.name = str1;
					property.value = str2;
					propertys.push_back(property);
				}
			}		
		}
	}
	catch(...)
	{
		return -1;
	}
	return pbuf - buf + 1;
}
long ReadContent(const char* buf,string name,string& content) //读取标签的内容
{
	const char* pbuf = buf;
	const long BUFSIZE = 5000;//初始分配10k内存，当超出时重新分配
	char* tmpbuf = new char[BUFSIZE+1];
	int i = 0,j=0;
	int buflen=BUFSIZE;
	char str[16];
	
	try
	{
		while (1)
		{			
			if( '<' == *pbuf && '/'==*(pbuf+1))
			{
				BYTE start = 2;
				j = start;
				while('>' != *(pbuf+j))
				{				
					if ( *(pbuf+j) != ' ') 
						str[j-start] = *(pbuf+j);
					j++;				
				}
				str[j-start] = 0;
				ToLowerCase(str);//换成小写
				if ( name == str || strcmp("head",str) == 0 || strcmp("body",str) == 0 )
					break;
			}	
			
			if (i<buflen)
				tmpbuf[i++] = *pbuf++;
			else 
			{
				char* newbuf = new char[buflen+BUFSIZE+1];//2006-04-26 申请内存时需要+1。
				memcpy(newbuf,tmpbuf,buflen);
				delete[] tmpbuf;
				tmpbuf = newbuf;			
				tmpbuf[i++] = *pbuf++;
				buflen += BUFSIZE;
			}
		}
		tmpbuf[i] = 0;					
		content = tmpbuf;	
	}
	catch(...)
	{
		tmpbuf[buflen] = 0;	
		delete []tmpbuf;
		return -1;
	}
	delete []tmpbuf;
	return pbuf - buf + 1;	
}

long ReadItemEnd(const char* buf,string name)
{
	const char* pbuf = buf;
	char str[128];
	WORD i = 0;
	while ('>' != *pbuf++&& i<128)
	{
		str[i++] = *pbuf;
	}
	str[i-1] = 0;
	ToLowerCase(str);//换成小写
	if ( name == str )
		return pbuf-buf;
	return 0;
}
long GetProperty(CPropertys propertys, const string&  name, string& property)
{
	for(short i=0;i<propertys.size();i++)
	{
		if ( name == propertys[i].name )
		{
			property = propertys[i].value;
			return i;
		}
	}
	property = "";
	return -1;	
}
// CReport
// 创建用于显示的字体
#define FONT_ATTR_BOLD				1
#define FONT_ATTR_ITALIC			2
#define FONT_ATTR_UNDERLINE			4
#define FONT_ATTR_STRIKEOUT			8
string GetChineseFromNum(short Num)
{
	string text[]={"零","壹","贰","叁","肆","伍","陆","柒","捌","玖","拾"};
	if(Num>=0&&Num<=10)
		return text[Num];
	return "零";
}
long ToLowerCase(char* str)
{
	if (NULL == str) return 0;
	short leng = strlen(str);
	for(short i=0;i<leng;i++)
		str[i] = tolower(str[i]);
	return leng;
}

double fabs(double dnum)
{
	if (dnum<0) return dnum;
	return dnum;
}
/*
****************************************************************************
Function:		GetFontXY
Description:    取得文字的高和宽
Calls:          无
Table Accessed: 无
Table Updated:  无
Input:			hDC 绘图DC
Output:         nXChar 文字宽
				nYChar 文字高
Return:         无
*****************************************************************************
*/
void GetFontXY(HDC hDC, int &nXChar, int &nYChar)
{
	TEXTMETRIC tm;
	::GetTextMetrics(hDC, &tm);
	nXChar = tm.tmAveCharWidth;
	nYChar = tm.tmHeight + tm.tmExternalLeading;
}
/*
****************************************************************************
Function:		CreateDispFont
Description:    创建字体
Calls:          无
Table Accessed: 无
Table Updated:  无
Input:			hDC 绘图DC
Output:         szFaceName 字体名
				iDeciPtHeight 文字高
Return:         无
*****************************************************************************
*/
HFONT CreateDispFont(HDC hdc, char* szFaceName, int iDeciPtHeight, 
										int iDeciPtWidth, int iAttributes, BOOL fLogRes)
{
	LOGFONT    lf;
	lf.lfHeight         = 0-iDeciPtHeight;
	lf.lfWidth          = 0;
	lf.lfEscapement     = 0;
	lf.lfOrientation    = 0;
	lf.lfWeight         = iAttributes & FONT_ATTR_BOLD      ? 700 : 0;
	lf.lfItalic         = iAttributes & FONT_ATTR_ITALIC    ?   1 : 0;
	lf.lfUnderline      = iAttributes & FONT_ATTR_UNDERLINE ?   1 : 0;
	lf.lfStrikeOut      = iAttributes & FONT_ATTR_STRIKEOUT ?   1 : 0;
	lf.lfCharSet        = DEFAULT_CHARSET;
	lf.lfOutPrecision   = OUT_DEFAULT_PRECIS;
	lf.lfClipPrecision  = CLIP_DEFAULT_PRECIS;
	lf.lfQuality        = DEFAULT_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH|FF_MODERN;
	
	strcpy(lf.lfFaceName, szFaceName);
	
	return CreateFontIndirect(&lf);
/*
	return CreateFont(0-iDeciPtHeight,0,0,0,0,FALSE,FALSE,0, DEFAULT_CHARSET,
					OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,
					DEFAULT_PITCH|FF_MODERN,szFaceName);

	FLOAT      cxDpi, cyDpi;
	HFONT      hFont;
	LOGFONT    lf;
	POINT      pt;
	TEXTMETRIC tm;
	
	SaveDC(hdc);
	
	SetGraphicsMode(hdc, GM_ADVANCED);
	ModifyWorldTransform(hdc, NULL, MWT_IDENTITY);
	SetViewportOrgEx(hdc, 0, 0, NULL);
	SetWindowOrgEx(hdc, 0, 0, NULL);
	
	if (fLogRes)
	{
		cxDpi = (FLOAT)GetDeviceCaps(hdc, LOGPIXELSX);
		cyDpi = (FLOAT)GetDeviceCaps(hdc, LOGPIXELSY);
	}
	else
	{
		cxDpi = (FLOAT)(25.4 * GetDeviceCaps(hdc, HORZRES) /
			GetDeviceCaps(hdc, HORZSIZE));
		
		cyDpi = (FLOAT)(25.4 * GetDeviceCaps(hdc, VERTRES) /
			GetDeviceCaps(hdc, VERTSIZE));
	}
	
	pt.x = (int)(iDeciPtWidth  * cxDpi / 72.0);
	pt.y = (int)(iDeciPtHeight * cyDpi / 72.0);
	
	DPtoLP (hdc, &pt, 1) ;
	
	lf.lfHeight         = - (int) (fabs (pt.y) / 10.0 + 0.5);
	lf.lfWidth          = 0;
	lf.lfEscapement     = 0;
	lf.lfOrientation    = 0;
	lf.lfWeight         = iAttributes & FONT_ATTR_BOLD      ? 700 : 0;
	lf.lfItalic         = iAttributes & FONT_ATTR_ITALIC    ?   1 : 0;
	lf.lfUnderline      = iAttributes & FONT_ATTR_UNDERLINE ?   1 : 0;
	lf.lfStrikeOut      = iAttributes & FONT_ATTR_STRIKEOUT ?   1 : 0;
	lf.lfCharSet        = 0;
	lf.lfOutPrecision   = 0;
	lf.lfClipPrecision  = 0;
	lf.lfQuality        = 0;
	lf.lfPitchAndFamily = 0;
	
	strcpy(lf.lfFaceName, szFaceName);
	
	hFont = CreateFontIndirect(&lf);
	
	if (iDeciPtWidth != 0)
	{
		hFont = (HFONT)SelectObject(hdc, hFont);
		
		GetTextMetrics(hdc, &tm);
		
		DeleteObject(SelectObject (hdc, hFont));
		
		lf.lfWidth = (int)(tm.tmAveCharWidth *
			fabs(pt.x) / fabs(pt.y) + 0.5);
		
		hFont = CreateFontIndirect(&lf);
	}
	
	RestoreDC(hdc, -1);
	
	return hFont ;
	*/
}

BOOL ExtMoveTo(HDC hdc,int x,int y,LPPOINT lp)
{
	//考虑偏移量,坐标转换
	return ::MoveToEx(hdc,x-xPhysicalOffset,y-yPhysicalOffset,lp);
}
BOOL ExtLineTo(HDC hdc,int x,int y)
{
	//考虑偏移量,坐标转换
	return ::LineTo(hdc,x-xPhysicalOffset,y-yPhysicalOffset);
}
int ExtDrawText(HDC hdc, LPSTR text, int length, LPRECT txrc, UINT alignflag, LPDRAWTEXTPARAMS drparam)
{
	//考虑偏移量,坐标转换
	RECT rc;
	rc.left = txrc->left-xPhysicalOffset;
	rc.top = txrc->top-yPhysicalOffset;
	rc.right = txrc->right-xPhysicalOffset;
	rc.bottom = txrc->bottom-yPhysicalOffset;
	int rtn=::DrawTextEx(hdc,text,length,&rc,alignflag,drparam);
	txrc->left = rc.left+xPhysicalOffset;
	txrc->top = rc.top+yPhysicalOffset;
	txrc->right = rc.right+xPhysicalOffset;
	txrc->bottom =rc.bottom + yPhysicalOffset;
	return rtn;
}
int ExTextOut(HDC hdc, int x, int y, LPCSTR text,int cbString)
{	
	//考虑偏移量,坐标转换
	return ::TextOutA(hdc, x-xPhysicalOffset, y-yPhysicalOffset, text, cbString);
}
BOOL ExRectangle( HDC hdc, int nLeftRect, int nTopRect, int nRightRect, int nBottomRect)
{
	//考虑偏移量,坐标转换
	return ::Rectangle(hdc,nLeftRect-xPhysicalOffset,nTopRect-yPhysicalOffset,nRightRect-xPhysicalOffset,nBottomRect-yPhysicalOffset);
}