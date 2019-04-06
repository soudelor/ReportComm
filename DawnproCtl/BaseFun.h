// BaseFun.h: interface for the BaseFun class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASEFUN_H__4386EED7_8777_47E3_80CF_99835804D58B__INCLUDED_)
#define AFX_BASEFUN_H__4386EED7_8777_47E3_80CF_99835804D58B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


typedef struct tagProperty
{
	string name;
	string value;	
} Property;
typedef vector<Property> CPropertys;

// �߿�
//#define BF_LEFT			1
//#define BF_TOP			2
//#define BF_RIGHT		4
//#define BF_BOTTOM		8

extern long ReadItem(const char* buf,char* name, CPropertys& propertys);
extern long ReadContent(const char* buf,string name,string& content);
extern long ReadItemEnd(const char* buf,string name);
extern long GetProperty(CPropertys propertys, const string&  name, string& property);
extern long ToLowerCase(char* str);
extern string GetChineseFromNum(short Num);
// CReport
// ����������ʾ������
#define FONT_ATTR_BOLD				1
#define FONT_ATTR_ITALIC			2
#define FONT_ATTR_UNDERLINE			4
#define FONT_ATTR_STRIKEOUT			8


#define LN_NONE 0
#define LN_ALL 1



typedef struct tagPageInfo
{
	HDC hDC;					// DC���
	HFONT hFont;				// ������
	int nXChar;					// �ֿ�
	int nYChar;					// �ָ�
	int nPageCols;				// �ֱ𲻿����й���Ҫ��ҳ��
	int nPageRows;				// �ֱ𲻿����й���Ҫ��ҳ��
	int nRowsPerPage;			// ÿҳ����ʾ����
	int nColsPerPage;			// ÿҳ����ʾ����
	int nTotalCols;				// ���ж�����
	int nTotalRows;				// ���ж�����
	
	char szDev[255];
	char szDriver[255];
	char szOutput[255]; 
	
} PageInfo;


extern double fabs(double dnum);
extern void GetFontXY(HDC hDC, int &nXChar, int &nYChar);
extern HFONT CreateDispFont(HDC hdc, char* szFaceName, int iDeciPtHeight, int iDeciPtWidth, int iAttributes, BOOL fLogRes);
extern BOOL ExtMoveTo(HDC hdc,int x,int y,LPPOINT lp);
extern BOOL ExtLineTo(HDC hdc,int x,int y);
extern int ExtDrawText(HDC hdc, LPSTR text, int length, LPRECT txrc, UINT alignflag, LPDRAWTEXTPARAMS drparam);
extern int ExTextOut(HDC hdc, int x, int y, LPCSTR text,int cbString);
BOOL ExRectangle( HDC hdc, int nLeftRect, int nTopRect, int nRightRect, int nBottomRect);

extern const char ROWHEIGHT[] ;
extern const char COLWIDTH[] ;
extern short FONTSIZE;
extern double nLogPixelX ;//ÿ���׵��߼�����
extern double nLogPixelY ;
extern double MM ;
extern int xPhysicalOffset;
extern int yPhysicalOffset;
extern int nPhysicalWidth ;
extern int nPhysicalHeight;
#endif // !defined(AFX_BASEFUN_H__4386EED7_8777_47E3_80CF_99835804D58B__INCLUDED_)
