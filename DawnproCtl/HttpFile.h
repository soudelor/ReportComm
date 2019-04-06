// HttpFile.h: interface for the CHttpFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HTTPFILE_H__926F25BC_789D_42A4_AEF4_F94C999352E6__INCLUDED_)
#define AFX_HTTPFILE_H__926F25BC_789D_42A4_AEF4_F94C999352E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "wininet.h"

class CHttpFile  
{
public:
	CHttpFile();
	virtual ~CHttpFile();
	void StartHttpGet(string httpstr);
	void EndHttpGet();
	void DoHttpGet();
	UINT Read(LPVOID lpBuf, UINT nCount);
	DWORD OpenOutFile();
	long  GetWEBFileSize();
	void ParseURL(const char* bsUrl,char*HostName,char*FileName);
	BOOL SetReadBufferSize(UINT nReadSize);
	long Seek(LONG lOffset, UINT nFrom);
protected:
	HINTERNET m_hSession;//会话
	HINTERNET m_hConnect;//连接
	HINTERNET m_hRequest;//http请求
	long m_nReadBufferBytes;
	long m_nReadBufferPos;
	long m_nReadBufferSize;
public:
	BYTE* m_pbReadBuffer;
	long m_dwContext;
};

#endif // !defined(AFX_HTTPFILE_H__926F25BC_789D_42A4_AEF4_F94C999352E6__INCLUDED_)
