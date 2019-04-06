// HttpFile.cpp: implementation of the CHttpFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HttpFile.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CHttpFile::CHttpFile()
{
	m_nReadBufferBytes=0;
	m_nReadBufferPos=0;
	m_nReadBufferSize=0;
	m_pbReadBuffer=0;
	m_dwContext=0;

	m_hSession=NULL;//�Ự
	m_hConnect=NULL;//����
	m_hRequest=NULL;//http����
}

CHttpFile::~CHttpFile()
{
	if (m_hRequest != NULL)
	{
		EndHttpGet();
	
		if (m_pbReadBuffer != NULL)
		{
			delete [] m_pbReadBuffer;
			m_pbReadBuffer = NULL;
		}
	
	}

	if (m_pbReadBuffer != NULL)
		delete m_pbReadBuffer;
}
void CHttpFile::StartHttpGet(string httpstr)
{
	
   char HostName[128],FileName[128];
   ParseURL(httpstr.c_str(),HostName, FileName); 
	

    // 1.�����Ự
      m_hSession = InternetOpen("iexplore",INTERNET_OPEN_TYPE_PRECONFIG,NULL,NULL,0); // ͬ����ʽ
      if( m_hSession==NULL)	  return;   
	  
/*
      // 2.��������
      m_hConnect=InternetConnect(m_hSession,
            "http://cfi.net.cn",
            INTERNET_DEFAULT_HTTP_PORT,
            NULL,NULL,
            INTERNET_SERVICE_HTTP, 0, 0);
      if(m_hConnect==NULL) return;
  
      // 3.��ʼ����������
      */
	   //const char *FAcceptTypes = "* *";// ��*�м��и�/
/*
      m_hRequest = HttpOpenRequest(m_hConnect,
            "GET", // �ӷ�������ȡ����
            FileName, // ���ȡ���ļ�������
            "HTTP/1.1", // ʹ�õ�Э��
            NULL,
            &FAcceptTypes,
            INTERNET_FLAG_RELOAD,
            0);
      if( m_hRequest==NULL) return;    

      // 4.������������
      HttpSendRequest(m_hRequest, NULL, 0, NULL, 0);
  */  
	
    m_hRequest = ::InternetOpenUrl( 
			m_hSession, // 1 HINTERNET hInternetSession 
			httpstr.c_str(), // 2 LPCTSTR lpszUrl 
			NULL, // 3 LPCTSTR lpszHeaders 
			0, // 4 DWORD dwHeadersLength 
			INTERNET_FLAG_RELOAD, // 5 DWORD dwFlags INTERNET_FLAG_HYPERLINK
			0 // 6 DWORD dwContext 
		) ; 

}

// ȡ�ô������ļ��Ĵ�С
long  CHttpFile::GetWEBFileSize(void)
{
  int HTTPGET_BUFFER_MAX =512;
  char Buffer[512];
  DWORD BufLen=HTTPGET_BUFFER_MAX;
        DWORD dwIndex=0;
        bool RetQueryInfo=HttpQueryInfo(m_hRequest,
        HTTP_QUERY_CONTENT_LENGTH,
        Buffer, &BufLen,
        &dwIndex);
  if( RetQueryInfo==false) return -1;

  int FileSize=atoi(Buffer); // �ļ���С    
   
   return FileSize;
}

// ������ļ����Ա������ص�����
DWORD CHttpFile::OpenOutFile(void)
{ 
   
   return 0;
}
// ִ�����ع���
void CHttpFile::DoHttpGet(void)
{
	
}

BOOL CHttpFile::SetReadBufferSize(UINT nReadSize)
{
	BOOL bRet = TRUE;

	if (nReadSize != -1 && nReadSize != m_nReadBufferSize)
	{
		if (m_nReadBufferPos > nReadSize)
			bRet = FALSE;
		else
		{
			if (nReadSize == 0)
			{
				delete [] m_pbReadBuffer;
				m_pbReadBuffer = NULL;
			}
			else if (m_pbReadBuffer == NULL)
			{
				m_pbReadBuffer = new BYTE[nReadSize];
				m_nReadBufferPos = nReadSize;
			}
			else
			{
				DWORD dwMoved = m_nReadBufferSize - m_nReadBufferPos;
				LPBYTE pbTemp = m_pbReadBuffer;
				m_pbReadBuffer = new BYTE[nReadSize];

				if (dwMoved > 0)
				{
					memcpy(m_pbReadBuffer, pbTemp + m_nReadBufferPos, dwMoved);
					m_nReadBufferPos = 0;
					m_nReadBufferBytes = dwMoved;
				}
				else
				{
					m_nReadBufferBytes = 0;
					m_nReadBufferPos = nReadSize;
				}
				delete [] pbTemp;
			}

			m_nReadBufferSize = nReadSize;
		}
	}

	return bRet;
}

LONG CHttpFile::Seek(LONG lOffset, UINT nFrom)
{

	// can't do this on a file for writing
	// can't do this on a file that's got a buffer
	enum
	{
		begin,current,end
	};

	switch (nFrom)
	{
		case begin:
			nFrom = FILE_BEGIN;
			break;

		case current:
			nFrom = FILE_CURRENT;
			break;

		case end:
			nFrom = FILE_END;
			break;

		default:		
			break;
	}

	LONG lRet;
	lRet = InternetSetFilePointer(m_hRequest, lOffset, NULL, nFrom, m_dwContext);	
	return lRet;
}

UINT CHttpFile::Read(LPVOID lpBuf, UINT nCount)
{

	DWORD dwBytes;	

	if (m_pbReadBuffer == NULL)
	{
		if (!InternetReadFile(m_hRequest, (LPVOID) lpBuf, nCount, &dwBytes))				
		return dwBytes;
	}

	LPBYTE lpbBuf = (LPBYTE) lpBuf;

	// if the requested size is bigger than our buffer,
	// then handle it directly

	if (nCount >= m_nReadBufferSize)
	{
		DWORD dwMoved = max(0, (long)m_nReadBufferBytes - (long)m_nReadBufferPos);
		memcpy(lpBuf, m_pbReadBuffer + m_nReadBufferPos, dwMoved);
		m_nReadBufferPos = m_nReadBufferSize;
		if (!InternetReadFile(m_hRequest, lpbBuf+dwMoved, nCount-dwMoved, &dwBytes))			
		dwBytes += dwMoved;
	}
	else
	{
		if (m_nReadBufferPos + nCount >= m_nReadBufferBytes)
		{
			DWORD dwMoved = max(0, (long)m_nReadBufferBytes - (long)m_nReadBufferPos);
			memcpy(lpbBuf, m_pbReadBuffer + m_nReadBufferPos, dwMoved);

			DWORD dwRead;
			if (!InternetReadFile(m_hRequest, m_pbReadBuffer, m_nReadBufferSize,
					&dwRead))			
			m_nReadBufferBytes = dwRead;

			dwRead = min(nCount - dwMoved, m_nReadBufferBytes);
			memcpy(lpbBuf + dwMoved, m_pbReadBuffer, dwRead);
			m_nReadBufferPos = dwRead;
			dwBytes = dwMoved + dwRead;
		}
		else
		{
			memcpy(lpbBuf, m_pbReadBuffer + m_nReadBufferPos, nCount);
			m_nReadBufferPos += nCount;
			dwBytes = nCount;
		}
	}

	return dwBytes;
}

void CHttpFile::EndHttpGet(void)
{
   if(m_hConnect)
   {     
      try
      {
         InternetCloseHandle(m_hRequest);
         InternetCloseHandle(m_hConnect);
         InternetCloseHandle(m_hSession);
      }catch(...){}
      m_hSession=NULL;
      m_hConnect=NULL;
      m_hRequest=NULL;          
   }
}


void CHttpFile::ParseURL(const char* bsUrl, char* HostName,char* FileName)
{
   
   char* pch =strstr(bsUrl,"http://");
   if(pch>0)
   {
      bsUrl = bsUrl+7;
   }
   pch = strstr(bsUrl,"/");

   int i = pch-bsUrl;
   strncpy(HostName,bsUrl, i);
   HostName[i+1]=0;
   int leng = strlen(bsUrl);
   strncpy(FileName,bsUrl+i, leng-i);
   FileName[leng-i+1]=0;
}
