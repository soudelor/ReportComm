// Cell.h: interface for the CCell class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CELL_H__7A84060C_794B_48A5_82FE_3FE14E7AB74F__INCLUDED_)
#define AFX_CELL_H__7A84060C_794B_48A5_82FE_3FE14E7AB74F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "basefun.h"

class CCell  
{
public:
	CCell();
	CCell(POINT topleft ,POINT rightbottom,string text);
	virtual ~CCell();
	void Initial();
	POINT GetTopLeft();
	POINT GetBottomRight();
	void SetRegion(WORD left,WORD top,WORD right,WORD bottom)
	{
		m_Region.left = left;m_Region.top = top;
		m_Region.right = right;m_Region.bottom = bottom;
	}
	void SetProperty(const CPropertys& propertys);
	void Draw(HDC hDC,WORD param=LN_ALL);
protected:
	string m_Text;
	string m_FontName;
	string m_BarType;
	WORD m_FontSize;
	DWORD m_FontColor;
	WORD m_FontAttributes;
	DWORD m_BorderColor;
	float m_Border;
	WORD m_BorderFlag;
	WORD m_AlignFlag;
	POINT m_TopLeft;
	POINT m_BottomRight;
	float m_BarHeight;
	float m_BarPrecision;
	WORD m_BarFontSize;
	WORD m_BarTextAlign;
	WORD m_CellParam;
	RECT m_Region;
};

#endif // !defined(AFX_CELL_H__7A84060C_794B_48A5_82FE_3FE14E7AB74F__INCLUDED_)
