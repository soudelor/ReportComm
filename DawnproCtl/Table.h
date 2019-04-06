// Table.h: interface for the CTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TABLE_H__452D7276_8669_4139_8822_06D153DE11CF__INCLUDED_)
#define AFX_TABLE_H__452D7276_8669_4139_8822_06D153DE11CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define COLNUM  300
#define ROWNUM  300 

#include "basefun.h"
class CCell;
class CTable  
{
public:
	CTable();
	virtual ~CTable();	

	void DrawCell(HDC hDC);
	void DrawBorder(HDC hDC);
	void Draw(HDC hDC);

	long Read(const char* buffer);
	void AddRowHeight(WORD height);
	void AddColWidth(WORD width);
	void SetColWidth(WORD col,WORD width);
	void SetProperty(const CPropertys& propertys);

	void Calculate();
private:
	WORD SetTDFlag(POINT spt,POINT ept, BYTE value);
	WORD GetNextTDPos(WORD &nRow,WORD &nCol);
	void InitCoorder();
protected:		
	BYTE m_Coorder[COLNUM][ROWNUM];
	string m_FontName;
	WORD m_FontSize;
	WORD m_BorderFlag;
	WORD m_FontFlag;
	short m_CellSpacing;
	POINT Offset;
	float m_Border;
	DWORD m_BorderColor;
	DWORD m_Param;
	vector<WORD> m_RowHeights;
	vector<WORD> m_ColWidths;
	vector<CCell> m_Cells;
	
};

#endif // !defined(AFX_TABLE_H__452D7276_8669_4139_8822_06D153DE11CF__INCLUDED_)
