// Table.cpp: implementation of the CTable class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Table.h"
#include "cell.h"
#include "basefun.h"
#include "barcodeobj.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTable::CTable()
{
	m_FontName = "";
	m_FontSize = 0;
	m_CellSpacing = 0.2;
	Offset.x = 0;
	Offset.y = 0;
	m_Border = 0.5;
	m_BorderColor = RGB(0,0,0);
	m_BorderFlag = BF_LEFT|BF_TOP|BF_RIGHT|BF_BOTTOM;
	m_Param = LN_ALL;
	InitCoorder();
}
void CTable::InitCoorder()
{	
	for ( short i=0;i<ROWNUM;i++)
	{
		for ( short j=0;j<COLNUM;j++)
			m_Coorder[i][j] = 0;
	}
}
CTable::~CTable()
{
	m_Cells.clear();
}
long CTable::Read(const char* buffer)
{
	long offset = 0;
	const char* pbuf = buffer;
	char ch;
	long len;
	char name[10];
	CPropertys propertys;
	string property;
	string content;
	
	
	WORD nROW = 100;
	WORD nCol = 20;

	

	WORD pos=0,row=0,col=0;

	while(*pbuf!=0)
	{
		ch = *pbuf;
		if( '<' == ch && *(pbuf+1)!='/')
		{			
			propertys.clear();
			len = ReadItem(pbuf,name, propertys);
			ToLowerCase(name);//换成小写
			if( strcmp(name,"tr")==0)
			{				
				if ( GetProperty(propertys, "height", property) == -1)
					property = ROWHEIGHT;
				pbuf += len;
				AddRowHeight(atoi(property.c_str()));
				len = ReadContent(pbuf,name,content);
				if (len < 0) { offset = -1;break; }
				
				const char* colbuf=pbuf;
				col = 0;
				while(colbuf<pbuf+len)
				{
					propertys.clear();
					pos = ReadItem(colbuf,name, propertys);
					ToLowerCase(name);//换成小写
					if( strcmp(name,"td") !=0 ) 
					{
						colbuf++;
						continue;
					}
					colbuf += pos;
					pos = ReadContent(colbuf,name,content);
					colbuf += pos;
					pos = ReadItemEnd(colbuf,"td");
					colbuf += pos;
					
					int cols=1,rows=1;
					if ( GetProperty(propertys, "colspan", property) != -1)
							cols = atoi(property.c_str());												
					if ( GetProperty(propertys, "rowspan", property) != -1)
							rows = atoi(property.c_str());					

					int flag = GetProperty(propertys, "width", property);							

					GetNextTDPos(row,col);//
					if (row==0)
					{		
						if ( -1 == flag )
							property = COLWIDTH;
						for (BYTE k=0;k<cols;k++)
							AddColWidth(atoi(property.c_str())/cols);
					}
					else //如果有宽度，设置宽度
					{	
						if ( -1 != flag )
						{
							for (BYTE k=0;k<cols;k++)						
								SetColWidth(col,atoi(property.c_str())/cols);
						}
					}
					POINT pt1,pt2;				

					if (cols>1||rows>1)
					{
						pt1.x = col;
						pt1.y = row;
						pt2.x = col + cols - 1;
						pt2.y = row + rows - 1;
						SetTDFlag(pt1,pt2,1);//标明占用标志									
					}
					pt1.x = col;
					pt1.y = row;
					pt2.x = col + cols - 1;
					pt2.y = row + rows - 1;
					//char temp[20];
					//sprintf(temp,"%d",width);					
					CCell cell(pt1,pt2,content);
					cell.SetProperty(propertys);
					m_Cells.push_back(cell);					
					col++;
				}
				pbuf += len;
				//在这里组合表格
			//	table.Read(content);
				row++;
				pos = ReadItemEnd(pbuf,"tr");
				pbuf += pos;
			}	
			else
			{
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
void CTable::DrawCell(HDC hDC)
{
	Calculate();

	double Unit = nLogPixelX;//屏幕上10个点一个毫米
	HFONT hFont,hOldFont;
	HPEN hPen,hOldPen;
	if ( m_FontSize > 0 && m_FontName != "")
	{
		char* fontname = (char*)m_FontName.c_str();
		hFont = CreateDispFont(hDC, fontname, m_FontSize*Unit, 0, 0, TRUE);
		hOldFont = (HFONT)::SelectObject(hDC, hFont);
	}
	if (m_CellSpacing>0)
	{
		hPen=::CreatePen(PS_SOLID,m_CellSpacing*Unit,RGB(0,0,0)); 
		hOldPen = (HPEN)::SelectObject(hDC,hPen); 
	}

	short sz = m_Cells.size();
	short kk;
	for(kk=0;kk<sz;kk++)
		m_Cells[kk].Draw(hDC,m_Param);

	if ( m_FontSize > 0 && m_FontName != "")
	{
		::SelectObject(hDC, hOldFont);
		::DeleteObject(hFont);
	}

	if (m_CellSpacing>0)
	{
		::SelectObject(hDC,hOldPen);
		::DeleteObject(hPen);
	}
}
void CTable::DrawBorder(HDC hDC)
{
	int cols = m_ColWidths.size();
	int rows = m_RowHeights.size();
	double Unit = nLogPixelX;//屏幕上10个点一个毫米
	WORD offestX = Offset.x,offestY = Offset.y;

	int left = offestX;
	int top = offestY;
	
	int right = offestX;
	int bottom = offestY;

	
	for (short j=0;j<cols;j++)
		right += m_ColWidths[j];
	
	for (j=0;j<rows;j++)
		bottom += m_RowHeights[j];

	//坐标比例转换
	left = left*Unit;
	top = top*Unit;
	right = right*Unit;
	bottom = bottom*Unit;

	HPEN hPen,hOldPen;
	hPen=::CreatePen(PS_SOLID,m_Border*Unit,m_BorderColor); 
	hOldPen = (HPEN)::SelectObject(hDC,hPen); 
	
	RECT rc={left,top,right,bottom};
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
	
	::SelectObject(hDC,hOldPen);
	::DeleteObject(hPen);
}
void CTable::Calculate()
{
	short kk,j;
	short sz = m_Cells.size();
	POINT pt1,pt2;
	
	WORD left=0,top=0,right=0,bottom=0;
	WORD width,height;
	for(kk=0;kk<sz;kk++)
	{
		pt1 = m_Cells[kk].GetTopLeft();
		pt2 = m_Cells[kk].GetBottomRight();
		

		left = Offset.x;
		top = Offset.y;

		if ( pt1.x > 0 )
		{
			width = 0;			
			for (j=0;j<pt1.x;j++)
				width += m_ColWidths[j];
			left += width;
		}
		if ( pt1.y > 0 )
		{
			height = 0;
			for (j=0;j<pt1.y;j++)
				height += m_RowHeights[j];
			top += height;
		}
		
		if ( pt2.x >= 0 )
		{
			width = 0;
			for (j=pt1.x;j<=pt2.x;j++)
				width += m_ColWidths[j];
		}
		
		if ( pt2.y >= 0 )
		{
			height =0 ;
			for (j=pt1.y;j<=pt2.y;j++)
				height += m_RowHeights[j];			
		}

		right = left + width;
		bottom = top + height;
		m_Cells[kk].SetRegion(left,top,right,bottom);
	}
}
void CTable::Draw(HDC hDC)
{	
	DrawCell(hDC);
	if (m_Param&LN_ALL)
		DrawBorder(hDC);
}
void CTable::AddRowHeight(WORD height)
{
	m_RowHeights.push_back(height);
}
void CTable::AddColWidth(WORD width)
{	
	m_ColWidths.push_back(width);
}
void CTable::SetColWidth(WORD col,WORD width)
{	
	int sz = m_ColWidths.size();
	if ( col<sz )
		m_ColWidths[col] = width;
}
WORD CTable::GetNextTDPos(WORD &nRow,WORD &nCol)
{
	if (nCol>COLNUM) return 0;
	if (nRow>ROWNUM) return 0;
	
	short j;
	for (j=nCol;j<COLNUM;j++)
	{
		if(	0 == m_Coorder[nRow][j] ) //占用
			break;		
	}
	nCol += j-nCol;
	return 0 ;
}

WORD CTable::SetTDFlag(POINT spt,POINT ept, BYTE value)
{
	if (spt.x>COLNUM||ept.x>COLNUM) return 0;
	if (ept.y>ROWNUM||ept.y>ROWNUM) return 0;
	short i,j;

	for (j=spt.y;j<=ept.y;j++)
		for (i=spt.x;i<=ept.x;i++)	
			m_Coorder[j][i] = value;
		
	return 0;
}
void CTable::SetProperty(const CPropertys& propertys)
{
	string property;
	if ( GetProperty(propertys, "fontname", property) != -1)//字体名
		m_FontName = property;
	if ( GetProperty(propertys, "fontsize", property) != -1)//字体大小
		m_FontSize = atoi(property.c_str());
	if ( GetProperty(propertys, "cellspacing", property) != -1)//单元格线框
		m_CellSpacing = atoi(property.c_str());
	if ( GetProperty(propertys, "offsetx", property) != -1)//偏移量X
		Offset.x = atoi(property.c_str());
	if ( GetProperty(propertys, "offsety", property) != -1)//偏移量X
		Offset.y = atoi(property.c_str());
	if ( GetProperty(propertys, "borderflag", property) != -1)//边框风格
		m_BorderFlag = atoi(property.c_str());
	if ( GetProperty(propertys, "border", property) != -1)//边框宽度
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
	if ( GetProperty(propertys, "param", property) != -1)//颜色
		m_Param = atol(property.c_str());
	else 
		m_Param |= LN_ALL;
}