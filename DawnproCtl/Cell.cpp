// Cell.cpp: implementation of the CCell class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Cell.h"
#include "BarcodeObj.h"
#include "basefun.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCell::CCell()
{
	Initial();
}

CCell::CCell(POINT topleft ,POINT rightbottom,string text)
{
	Initial();	
	m_Text = text;
	m_TopLeft = topleft;
	m_BottomRight = rightbottom;	
	m_BarType = "BARCODE_128";
}
void CCell::Initial()
{
	m_FontName = "";
	m_FontColor=RGB(0,0,0);
	m_FontSize = 0;
	m_FontAttributes=0;
	m_Border = 0;
	m_BorderFlag = BF_LEFT|BF_TOP|BF_RIGHT|BF_BOTTOM;
	m_AlignFlag = DT_CENTER|DT_SINGLELINE|DT_VCENTER;//|DT_WORDBREAK; //|DT_VCENTER;
	m_TopLeft.x = m_TopLeft.y = m_BottomRight.x = m_BottomRight.y=0;
	m_BarHeight = 80;
	m_BarPrecision = 2.5;
	m_BarFontSize=20;
	m_BarTextAlign=BF_TOP;
	m_CellParam = 1;
}

CCell::~CCell()
{

}
POINT CCell::GetTopLeft()
{
	return m_TopLeft;
}
POINT CCell::GetBottomRight()
{
	return m_BottomRight;
}
void CCell::SetProperty(const CPropertys& propertys)
{
	string property;
	if ( GetProperty(propertys, "fontname", property) != -1)//字体名
		m_FontName = property;
	if ( GetProperty(propertys, "fontsize", property) != -1)//字体大小
		m_FontSize = atoi(property.c_str());
	if ( GetProperty(propertys,"fontatt",property) != -1) //字体 粗细 下划线
		m_FontAttributes = atoi(property.c_str());
	if ( GetProperty(propertys,"color",property) != -1) //字体颜色
	{
		char R[3],G[3],B[3];
		WORD r,g,b;
		strncpy(R,property.c_str()+1,2);R[3]=0;
		strncpy(G,property.c_str()+3,2);G[3]=0;
		strncpy(B,property.c_str()+5,2);B[3]=0;
		sscanf(R,"%x",&r);
		sscanf(G,"%x",&g);
		sscanf(B,"%x",&b);
		m_FontColor = RGB(r,g,b);	
	}
	if ( GetProperty(propertys, "borderflag", property) != -1)//边框风格
		m_BorderFlag = atoi(property.c_str());
	if ( GetProperty(propertys, "border", property) != -1)//线宽
		m_Border = atof(property.c_str());	
	if ( GetProperty(propertys, "bordercolor", property) != -1)//线颜色
	{	
		char R[3],G[3],B[3];
		WORD r,g,b;
		strncpy(R,property.c_str()+1,2);R[3]=0;
		strncpy(G,property.c_str()+3,2);G[3]=0;
		strncpy(B,property.c_str()+5,2);B[3]=0;
		sscanf(R,"%x",&r);
		sscanf(G,"%x",&g);
		sscanf(B,"%x",&b);
		m_BorderColor = RGB(r,g,b);	
	}
	if ( GetProperty(propertys, "align", property) != -1)//文本对齐方式
		m_AlignFlag = atoi(property.c_str()); //对齐
	if ( GetProperty(propertys, "bartype", property) != -1)//条码类型
	{
		m_BarType = property.c_str();	
		
	}
	if ( GetProperty(propertys, "barheight", property) != -1)//条码高度
		m_BarHeight = atof(property.c_str());	
	if ( GetProperty(propertys, "barprecision", property) != -1)//条码精度
		m_BarPrecision = atof(property.c_str());
	if ( GetProperty(propertys, "barfontsize", property) != -1)//条码字体大小
		m_BarFontSize = atof(property.c_str());
	if ( GetProperty(propertys, "bartextalign", property) != -1)//条码文字位置
		m_BarTextAlign = atof(property.c_str());	
	if ( GetProperty(propertys, "cellparam", property) != -1)//单元格参数,可以让文字不显示
		m_CellParam = atoi(property.c_str());	
	
}
void CCell::Draw(HDC hDC,WORD param)
{	
	HFONT hFont,hOldFont;
	HPEN hPen,hOldPen;

	int OldMode=0;
	double Unit = nLogPixelX;//屏幕上10个点一个毫米
	WORD BARHEIGHT=m_BarHeight*Unit;
	double BARPRECISIAN=m_BarPrecision*Unit;
	
	char* text = (char*)m_Text.c_str();
	WORD length = m_Text.size();

	if (m_FontName!= ""&&m_FontSize>0||m_FontAttributes!=0)
	{
		char* fontname = (char*)m_FontName.c_str();
		hFont = CreateDispFont(hDC, fontname, m_FontSize*Unit, 0, m_FontAttributes, TRUE);
		hOldFont = (HFONT)::SelectObject(hDC, hFont);
		OldMode = ::SetBkMode(hDC,TRANSPARENT);
	}
	DWORD OldTextColor = RGB(0,0,0);
	if (m_FontColor!=OldTextColor)
		OldTextColor=SetTextColor(hDC,m_FontColor);

	if (m_FontSize>0)
		BARHEIGHT = m_FontSize*Unit;
		
	if ( m_Border != 0&&m_BorderColor!=RGB(0,0,0))
	{
		hPen=::CreatePen(PS_SOLID,m_Border*Unit,RGB(0,0,0)); 
		hOldPen = (HPEN)::SelectObject(hDC,hPen); 
	}

	RECT rc = m_Region;
	rc.left = m_Region.left*Unit;
	rc.right = m_Region.right*Unit;
	rc.top = m_Region.top*Unit;
	rc.bottom = m_Region.bottom*Unit;
	if ( param&LN_ALL )
	{
		if ( m_BorderFlag&BF_LEFT) 
		{
		::ExtMoveTo(hDC,rc.left,rc.top,NULL);
		::ExtLineTo(hDC,rc.left,rc.bottom);
		}
		if (m_BorderFlag&BF_TOP)
		{
			::ExtMoveTo(hDC,rc.left,rc.bottom,NULL);
			::ExtLineTo(hDC,rc.right,rc.bottom);
		}
		if (m_BorderFlag&BF_RIGHT)
		{
			::ExtMoveTo(hDC,rc.right,rc.bottom,NULL);
			::ExtLineTo(hDC,rc.right,rc.top);
		}
		if (m_BorderFlag&BF_BOTTOM)
		{
			::ExtMoveTo(hDC,rc.right,rc.top,NULL);
			::ExtLineTo(hDC,rc.left,rc.top);
		}
	}
	if ( length>0 && m_CellParam!=0)
	{	
		if (text[0] == '^')
		{//以后需要加入条码的对齐方式
			short top = (rc.top + rc.bottom)/2 - BARHEIGHT/2;//DT_TOP
			short barfh=short(m_BarFontSize*Unit+0.5);
			if (m_BarTextAlign&BF_TOP) //文字在条码上面显示
			{
				if( m_AlignFlag&DT_VCENTER) //显示居中
					top = short ( (rc.top + rc.bottom)/2.0 - (BARHEIGHT+barfh)/2.0 + barfh + 0.5 );
				else if(m_AlignFlag&DT_BOTTOM)
					top = rc.bottom - BARHEIGHT;
				else 
					top = rc.top + BARHEIGHT;
			}
			else if (m_BarTextAlign&BF_BOTTOM) //文字在条码下面显示
			{
				if( m_AlignFlag&DT_VCENTER ) //显示居中
					top = short ( (rc.top + rc.bottom)/2.0 - (BARHEIGHT+barfh)/2.0 + 0.5 );
				else if(m_AlignFlag&DT_BOTTOM)
					top = rc.bottom - BARHEIGHT - barfh;
				else 
					top = rc.top ;
			}

			CBarcodeObj bobj;
			bobj.Create(text+1);
			bobj.Encode(0,FromBarcodeStringToID(m_BarType.c_str()));
			bobj.SetPosition(0,BARHEIGHT,rc.left+BARHEIGHT,top,BARPRECISIAN);
			bobj.SetTextProperty(barfh,m_BarTextAlign);			
			bobj.Draw(hDC);	
		}
		else if (length>2 && text[0] == '~' && text[0] == '!') //上标
		{
			string str1;
			int size = strlen(text);			
			if(text[0]=='$'&&size>1)
				str1 = GetChineseFromNum(atoi(text+2));			
			else 
				str1 = text;

			if ( !(m_AlignFlag&(DT_WORDBREAK|DT_VCENTER)) )//不转行书写文字
				::ExtDrawText(hDC,(char*)str1.c_str(),length,&rc,m_AlignFlag,NULL);
			else
			{
				//m_AlignFlag
				RECT trc=rc;				
				::ExtDrawText(hDC,(char*)str1.c_str(),length,&trc,m_AlignFlag|DT_CALCRECT,NULL);
				int height=trc.bottom-trc.top;
				rc.top = int((rc.bottom+rc.top)/2.0-height/2.0+0.5);
				rc.bottom=rc.top+height;
				::ExtDrawText(hDC,(char*)str1.c_str(),length,&rc,m_AlignFlag,NULL);
			}
		}
		else if (length>2 && text[0] == '~' && text[0] == '&') //下标
		{
		}
		else 
		{
			string str1;
			int size = strlen(text);			
			if(text[0]=='$'&&size>1)
				str1 = GetChineseFromNum(atoi(text+1));			
			else 
				str1 = text;

			if ( !(m_AlignFlag&(DT_WORDBREAK|DT_VCENTER)) )//不转行书写文字
				::ExtDrawText(hDC,(char*)str1.c_str(),length,&rc,m_AlignFlag,NULL);
			else
			{
				//m_AlignFlag
				RECT trc=rc;				
				::ExtDrawText(hDC,(char*)str1.c_str(),length,&trc,m_AlignFlag|DT_CALCRECT,NULL);
				int height=trc.bottom-trc.top;
				rc.top = int((rc.bottom+rc.top)/2.0-height/2.0+0.5);
				rc.bottom=rc.top+height;
				::ExtDrawText(hDC,(char*)str1.c_str(),length,&rc,m_AlignFlag,NULL);
			/*	hPen=::CreatePen(PS_SOLID,3*Unit,RGB(255,0,0)); 
				hOldPen = (HPEN)::SelectObject(hDC,hPen); 				
				::ExtMoveTo(hDC,rc.left,trc.top,NULL);
				::ExtLineTo(hDC,rc.left,trc.bottom);
				::ExtLineTo(hDC,rc.right,trc.bottom);
				::ExtLineTo(hDC,rc.right,trc.top);
				::ExtLineTo(hDC,rc.left,trc.top);
				::SelectObject(hDC,hOldPen);
				::DeleteObject(hPen);
			*/
			}
		}
	}
	if (m_FontColor!=OldTextColor)
		SetTextColor(hDC,OldTextColor);

	if (m_FontName!= ""&&m_FontSize>0)
	{
		::SelectObject(hDC, hOldFont);
		::DeleteObject(hFont);
	}	
	if ( m_Border != 0&&m_BorderColor!=RGB(0,0,0))
	{
		::SelectObject(hDC,hOldPen);
		::DeleteObject(hPen);
	}
}