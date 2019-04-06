// PageData.h: interface for the CPageData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PAGEDATA_H__CF417978_D6F1_4E3F_9726_90BE8EB06028__INCLUDED_)
#define AFX_PAGEDATA_H__CF417978_D6F1_4E3F_9726_90BE8EB06028__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "basefun.h"
class CTable;
class CPageData  
{
public:
	CPageData();
	virtual ~CPageData();
	long Read(const char* buffer);
	void Draw(HDC hDC);
	void SetProperty(const CPropertys& propertys);
protected:
	vector<CTable*> m_TableDataArray;
	string m_FontName;
	WORD m_FontSize;
	float m_Border;
	DWORD m_BorderColor;
};

#endif // !defined(AFX_PAGEDATA_H__CF417978_D6F1_4E3F_9726_90BE8EB06028__INCLUDED_)
