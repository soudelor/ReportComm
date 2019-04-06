// PrintData.cpp: implementation of the CPrintData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PrintData.h"
#include "barcodeobj.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#include "pagedata.h"
#include "basefun.h"
CPrintData::CPrintData()
{	

}

CPrintData::~CPrintData()
{
	Clear();
}
void CPrintData::Clear()
{
	for(short i=0;i<m_PageDataArray.size();i++)
		delete m_PageDataArray[i];
	m_PageDataArray.clear();
}
void CPrintData::Print(HDC hdc, UINT iPageMode)
{
	bool bSuccess = true;	
	static DOCINFO di = { sizeof(DOCINFO), "LVN" } ; 
		
	if (hdc == NULL) return ;
	
//	int height = GetDeviceCaps(hdc, VERTRES);//��ȡ��ӡ���ĸ߶ȺͿ��
//	int width  = GetDeviceCaps(hdc, HORZRES);		
	
	nLogPixelX = GetDeviceCaps(hdc,LOGPIXELSX)/25.4;//ÿ���׵��߼�����
	nLogPixelY = GetDeviceCaps(hdc,LOGPIXELSY)/25.4;

	//���ļ���������10�����Ӧ1���ף�������nLogPixelX����10.0,ʵ�����ʱ�����ļ��е�ֱֵ�ӳ��Ը�ֵ
	nLogPixelX = nLogPixelX/MM;
	nLogPixelY = nLogPixelY/MM;

	//ASSERT(nLogPixelX == nLogPixelY);
	xPhysicalOffset = GetDeviceCaps(hdc,PHYSICALOFFSETX);
	yPhysicalOffset = GetDeviceCaps(hdc,PHYSICALOFFSETY);
	
//	nPhysicalWidth = pDC->GetDeviceCaps(PHYSICALWIDTH);
//	nPhysicalHeight = pDC->GetDeviceCaps(PHYSICALHEIGHT);
//	HFONT hFont = CreateDispFont(hdc, "����", 90, 0, 0, TRUE);
//	::SelectObject(hdc, hFont);
	int pages = m_PageDataArray.size();
	if (::StartDoc(hdc, &di) > 0)
	{		
		for(int j = 0; j < pages; j++)
		{
			if (::StartPage(hdc) < 0)
			{
				bSuccess = false;
			}				
			CPageData* page = m_PageDataArray[j];
			page->Draw(hdc);
			
			if (::EndPage(hdc) < 0)
			{
				bSuccess = false;			
			}
		}
	}
	else
	{
		::MessageBox(NULL, "��ӡʧ�ܣ������ӡ���Ƿ�����������", "��ӡ��", MB_OK + 16);
	}
	if (bSuccess)
	{
		::EndDoc(hdc);
	}

//	::DeleteObject(hFont);			
}

long CPrintData::Read(const char* buffer)
{
	long offset = 0;
	if ( NULL == buffer ) return 0;
	Clear();
	const char* pbuf=buffer;
	char ch;
	CPropertys propertys; 
	int i=0;
	long len=0;
	char name[16];
	string content;
	try
	{
		while(*pbuf!=0)
		{
			ch = *pbuf;
			if( '<' == ch && *(pbuf+1)!='/' && *(pbuf+1)!='%')
			{	
				propertys.clear();
				len = ReadItem(pbuf,name, propertys);
				if (len < 0) return -1;

				pbuf += len;
				ToLowerCase(name);//����Сд
				if( strcmp(name,"page")==0)
				{			
					len = ReadContent(pbuf,name,content);
					if (len < 0) return -1;
					CPageData* page= new CPageData();
					page->SetProperty(propertys);
					pbuf += len;
					page->Read(content.c_str());	
					m_PageDataArray.push_back(page);
					len = ReadItemEnd(pbuf,"page");
					pbuf += len;	
				}			
			}	
			else
			{
				pbuf++;
				continue;
			}
		}
	}
	catch(...)
	{
		return offset;
	}
	return offset;
}