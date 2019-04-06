// PrintData.h: interface for the CPrintData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRINTDATA_H__E88B1E3D_BD97_48E9_AF98_43A1F7781D87__INCLUDED_)
#define AFX_PRINTDATA_H__E88B1E3D_BD97_48E9_AF98_43A1F7781D87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CPageData;
class CPrintData  
{
public:
	void Print(HDC hdc, UINT iPageMode);
	CPrintData();
	virtual ~CPrintData();
	void Clear();
	long Read(const char* buffer);
	vector<CPageData*> m_PageDataArray;	
};

#endif // !defined(AFX_PRINTDATA_H__E88B1E3D_BD97_48E9_AF98_43A1F7781D87__INCLUDED_)
