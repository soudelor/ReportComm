// WebCom.cpp : Implementation of CWebCom
//yeguodong ���ڿؼ� ��ͨ����ҳ����

#include "stdafx.h"
#include "DawnproComm.h"
#include "WebCom.h"

/////////////////////////////////////////////////////////////////////////////
// CWebCom
//�򿪴��� nPort:�˿ں� nBaud:������
BOOL CWebCom::Open(int nPort, int nBaud,int nByteSize,int nParity,int nStopBits)
{
	if( m_bOpened ) return( TRUE );

	char szPort[15];
	DCB dcb;

	wsprintf( szPort, "COM%d", nPort );
	//�첽ģʽ�򿪴���
	m_hComDev = CreateFile( szPort, GENERIC_READ | GENERIC_WRITE, 0, NULL, 
	OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, NULL );
	if( m_hComDev == NULL ) return( FALSE );

	memset( &m_OverlappedRead, 0, sizeof( OVERLAPPED ) );
	memset( &m_OverlappedWrite, 0, sizeof( OVERLAPPED ) );

	COMMTIMEOUTS CommTimeOuts;
	CommTimeOuts.ReadIntervalTimeout = 0xFFFFFFFF;
	CommTimeOuts.ReadTotalTimeoutMultiplier = 0;
	CommTimeOuts.ReadTotalTimeoutConstant = 0;
	CommTimeOuts.WriteTotalTimeoutMultiplier = 0;
	CommTimeOuts.WriteTotalTimeoutConstant = 5000;
	SetCommTimeouts( m_hComDev, &CommTimeOuts );

	m_OverlappedRead.hEvent = CreateEvent( NULL, TRUE, FALSE, NULL );
	m_OverlappedWrite.hEvent = CreateEvent( NULL, TRUE, FALSE, NULL );
	//����DCB�ṹ��DCB���������ʡ���żУ�����͡�����λ��ֹͣλ
	dcb.DCBlength = sizeof( DCB );
	GetCommState( m_hComDev, &dcb );
	dcb.BaudRate = nBaud;
	dcb.ByteSize = nByteSize;
	dcb.Parity = nParity;
	if (nStopBits>=0)
		dcb.StopBits = nStopBits;

	if( !SetCommState( m_hComDev, &dcb ) ||
		!SetupComm( m_hComDev, 10000, 10000 ) ||
		m_OverlappedRead.hEvent == NULL ||
		m_OverlappedWrite.hEvent == NULL )
	{
		DWORD dwError = GetLastError();
		if( m_OverlappedRead.hEvent != NULL ) 
			CloseHandle( m_OverlappedRead.hEvent );
		if( m_OverlappedWrite.hEvent != NULL ) 
			CloseHandle( m_OverlappedWrite.hEvent );
		
		CloseHandle( m_hComDev );
		return FALSE;
	}
	
	m_bOpened = TRUE;
	return m_bOpened;
}
//ȡBUFFER�е��ַ���Ŀ
int CWebCom::InBufferCount( void )
{

	if( !m_bOpened || m_hComDev == NULL )
		return( 0 );

	DWORD dwErrorFlags;
	COMSTAT ComStat;

	ClearCommError( m_hComDev, &dwErrorFlags, &ComStat );

	return (int)ComStat.cbInQue;
}
//��ȡ�������ݣ�buffer:���뻺����,dwBytesRead������ַ�����Ŀ
DWORD CWebCom::ReadData( void *buffer, DWORD dwBytesRead)
{

	if( !m_bOpened || m_hComDev == NULL ) 
		return 0;

	BOOL bReadStatus;
	DWORD dwErrorFlags;
	COMSTAT ComStat;

	ClearCommError( m_hComDev, &dwErrorFlags, &ComStat );
	if( !ComStat.cbInQue ) 
		return 0;

	dwBytesRead = min(dwBytesRead,(DWORD) ComStat.cbInQue);

	bReadStatus = ReadFile( m_hComDev, buffer, dwBytesRead, &dwBytesRead,&m_OverlappedRead );

	if( !bReadStatus )
	{
		if( GetLastError() == ERROR_IO_PENDING )
		{
			WaitForSingleObject( m_OverlappedRead.hEvent, 2000 );
			return dwBytesRead;
		}
		return 0;
	}

	return dwBytesRead;

}
//ͨ�����ڷ������ݣ�buffer:���ͻ�����,dwBytesWritten:���͵��ַ�����Ŀ
DWORD CWebCom::SendData( const char *buffer, DWORD dwBytesWritten)
{

	if( !m_bOpened || m_hComDev == NULL ) 
		return( 0 );

	BOOL bWriteStat;

	bWriteStat = WriteFile( m_hComDev, buffer, dwBytesWritten, &dwBytesWritten,&m_OverlappedWrite );

	if( !bWriteStat)
	{
		if ( GetLastError() == ERROR_IO_PENDING ) 
		{
			WaitForSingleObject( m_OverlappedWrite.hEvent, 1000 );
			return dwBytesWritten;
		}
		return 0;
	}
	return dwBytesWritten;
}
//�رմ���
int CWebCom::Close()
{
	return CloseHandle(m_hComDev);
}
//��ʾ�ַ���
DWORD CWebCom::WriteData(const char *buffer, DWORD dwBytesWritten)
{	
	char cominfo[1024];
	if( ReadData( cominfo, 1024) )
		::MessageBox(NULL,cominfo,buffer,MB_OK);
	else
		::MessageBox(NULL,buffer,buffer,MB_OK);

	return 1;
}
//���ַ�д���ļ�,fileΪ�ļ�����,dataΪд���ļ�������
DWORD CWebCom::TraceInfo(const char *file, const char *data)
{
	HANDLE hFile = CreateFile(file, GENERIC_WRITE, 0, NULL, OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL);//�����ļ�   
	if ( hFile != NULL  )
	{
		DWORD dwWritten;
		WriteFile(hFile, data, strlen(data), &dwWritten, NULL); // д���ļ�ͷ
		CloseHandle(hFile); 
		return 1;
	}
	return 0;
}


//�ӿ�:ͨ�����ڷ����ַ���
STDMETHODIMP CWebCom::SendData(BSTR data)
{
	char szANSIString [1024]; 
	
	WideCharToMultiByte ( CP_ACP,                // ANSI ����ҳ 
                          WC_COMPOSITECHECK, // ��������ַ� 
                          data,         // ԭUnicode �� 
                          -1,                    // -1 ��˼�Ǵ���0x00��β 
                          szANSIString,          // Ŀ��char�ַ��� 
                          sizeof(szANSIString),  // �����С 
                          NULL,                  // ��ȱʡ�ַ��� 
                          NULL );                // �����������  
	long sz = strlen(szANSIString);
	SendData(szANSIString,sz);
	return S_OK;
}


//�ӿ�:��ʾ�ַ�����������
STDMETHODIMP CWebCom::MsgInfo(BSTR Data)
{
	char szANSIString [1024]; 
	
	WideCharToMultiByte ( CP_ACP,                // ANSI ����ҳ 
                          WC_COMPOSITECHECK, // ��������ַ� 
                          Data,         // ԭUnicode �� 
                          -1,                    // -1 ��˼�Ǵ���0x00��β 
                          szANSIString,          // Ŀ��char�ַ��� 
                          sizeof(szANSIString),  // �����С 
                          NULL,                  // ��ȱʡ�ַ��� 
                          NULL );                // �����������  
	WriteData(szANSIString,strlen(szANSIString));

	return S_OK;
}
//�ӿ�:�򿪴���
STDMETHODIMP CWebCom::OpenPort(long nPort, long nBaud)
{
	Open(nPort, nBaud,7,EVENPARITY,ONESTOPBIT);
	return S_OK;
}

STDMETHODIMP CWebCom::OpenPortParam(long nPort, long nBaud, long nByteSzie, long nParity, long StopBit)
{
	//char szANSIString [256]; 
	//wsprintfA(szANSIString,"����%d-������%d-����λ%d-��żУ��%d-ֹͣλ%d",nPort, nBaud,nByteSzie,nParity,StopBit);
	//::MessageBox(NULL,szANSIString,"����������ʾ",MB_OK);
	Open(nPort, nBaud,nByteSzie,nParity,StopBit);
	return S_OK;	
}
//�ӿ�:�رմ���
STDMETHODIMP CWebCom::ClosePort()
{
	Close();
	return S_OK;
}


//�ӿ�:������д���ļ�,FileΪ�ļ���,DataΪд������
STDMETHODIMP CWebCom::TraceInfo(BSTR File, BSTR Data)
{
	char szANSIFile [128]; 
	char szANSIData [1024]; 
	
	WideCharToMultiByte ( CP_ACP,                // ANSI ����ҳ 
                          WC_COMPOSITECHECK, // ��������ַ� 
                          File,         // ԭUnicode �� 
                          -1,                    // -1 ��˼�Ǵ���0x00��β 
                          szANSIFile,          // Ŀ��char�ַ��� 
                          sizeof(szANSIFile),  // �����С 
                          NULL,                  // ��ȱʡ�ַ��� 
                          NULL );                // �����������  
	WideCharToMultiByte ( CP_ACP,                // ANSI ����ҳ 
                          WC_COMPOSITECHECK, // ��������ַ� 
                          Data,         // ԭUnicode �� 
                          -1,                    // -1 ��˼�Ǵ���0x00��β 
                          szANSIData,          // Ŀ��char�ַ��� 
                          sizeof(szANSIData),  // �����С 
                          NULL,                  // ��ȱʡ�ַ��� 
                          NULL );                // �����������  
	TraceInfo(szANSIFile,szANSIData);

	return S_OK;
}



