// PageData.cpp: implementation of the CPageData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PageData.h"
#include "table.h"
#include "basefun.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPageData::CPageData()
{
	m_Border = 0.3;//线宽
	m_BorderColor = RGB(0,0,0);
	m_FontSize = FONTSIZE;
	m_FontName = "宋体";
}

CPageData::~CPageData()
{
	for(short i=0;i<m_TableDataArray.size();i++)
		delete m_TableDataArray[i];
	m_TableDataArray.clear();
}
void CPageData::Draw(HDC hDC)
{
	double Unit = nLogPixelX;//屏幕上10个点一个毫米
	HPEN hPen=::CreatePen(PS_SOLID,m_Border*Unit,m_BorderColor); 
	HPEN hOldpen = (HPEN)::SelectObject(hDC,hPen); 

	char *fontname = (char*)m_FontName.c_str();
	HFONT hFont,hOldFont;
	hFont = CreateDispFont(hDC, fontname, m_FontSize*Unit, 0, 0, TRUE);
	hOldFont = (HFONT)::SelectObject(hDC, hFont);
	int OldMode = ::SetBkMode(hDC,TRANSPARENT);

	for(short i=0;i<m_TableDataArray.size();i++)
	{
		CTable* pTable = m_TableDataArray[i];
		pTable->Draw(hDC);
	}

	::SelectObject(hDC, hOldFont);
	::DeleteObject(hFont);
	::SetBkMode(hDC,OldMode);
	::SelectObject(hDC,hOldpen);
	::DeleteObject(hPen);
}
long CPageData::Read(const char* buffer)
{
	long offset = 0;
	if ( NULL == buffer ) return 0;
	
	const char* pbuf=buffer;
	char ch;
	CPropertys propertys; 

	long len;
	char name[48];
	string content;
	int i=0;

	while(*pbuf!=0)
	{
		ch = *pbuf;
		if( '<' == ch && *(pbuf+1)!='/')
		{	
			propertys.clear();
			len = ReadItem(pbuf,name, propertys);
			if (len < 0) return -1;		
			pbuf += len;
			ToLowerCase(name);//换成小写
			if( strcmp(name,"table")==0)
			{			
			
				len = ReadContent(pbuf,name,content);
				if (len < 0) return -1;
				string property;
				CTable* table = new CTable();
				table->SetProperty(propertys);
				pbuf += len;				
				table->Read(content.c_str());
				m_TableDataArray.push_back(table);
				len = ReadItemEnd(pbuf,"table");
				pbuf += len;			
			}						
		}	
		else
		{
			pbuf++;
			continue;
		}
	}
	return offset;
}
void CPageData::SetProperty(const CPropertys& propertys)
{
	string property;
	if ( GetProperty(propertys, "fontname", property) != -1)//字体名
		m_FontName = property;
	if ( GetProperty(propertys, "fontsize", property) != -1)//字体大小
		m_FontSize = atoi(property.c_str());
	if ( GetProperty(propertys, "border", property) != -1)//线宽
		m_Border = atof(property.c_str());	
	if ( GetProperty(propertys, "bordercolor", property) != -1)//颜色
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
}