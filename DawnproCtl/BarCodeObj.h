// BarCodeObj.h: interface for the BarCodeObj class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BARCODEOBJ_H__2BAAE33D_7F24_4D0B_BED5_29880FE0CB0A__INCLUDED_)
#define AFX_BARCODEOBJ_H__2BAAE33D_7F24_4D0B_BED5_29880FE0CB0A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

extern  "C" { 
#include "barcode.h"
}
class CBarcodeObj  
{
public:
	CBarcodeObj();
	CBarcodeObj(char* text);
	virtual ~CBarcodeObj();
	void Create(char* text);
	void Destory();
	int Draw(HDC hDC);
	int Encode(int CodeType,int flags);	
	int IntVersion();
	int SetPosition(int Width,int Height,int XOffset,int YOffset,double ScaleFactor);
	void SetText(char* text);
	char* GetVersion();
	void Initial();
	void SetTextProperty(WORD Size,WORD TextAlign)
	{
		m_BarFontSize = Size;
		m_BarTextAlign = TextAlign;
	}
private:
	 Barcode_Item* pBC;
	 WORD m_BarFontSize;
	 WORD m_BarTextAlign;
};
#endif // !defined(AFX_BARCODEOBJ_H__2BAAE33D_7F24_4D0B_BED5_29880FE0CB0A__INCLUDED_)
