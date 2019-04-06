// WebCom.cpp : Implementation of CWebCom
//yeguodong 串口控件 可通过网页调用

#include "stdafx.h"
#include "DawnproComm.h"
#include "WebCom.h"

/////////////////////////////////////////////////////////////////////////////
// CWebCom
//打开串口 nPort:端口号 nBaud:波特率
BOOL CWebCom::Open(int nPort, int nBaud,int nByteSize,int nParity,int nStopBits)
{
	if( m_bOpened ) return( TRUE );

	char szPort[15];
	DCB dcb;

	wsprintf( szPort, "COM%d", nPort );
	//异步模式打开串口
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
	//设置DCB结构，DCB包括波特率、奇偶校验类型、数据位、停止位
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
//取BUFFER中的字符数目
int CWebCom::InBufferCount( void )
{

	if( !m_bOpened || m_hComDev == NULL )
		return( 0 );

	DWORD dwErrorFlags;
	COMSTAT ComStat;

	ClearCommError( m_hComDev, &dwErrorFlags, &ComStat );

	return (int)ComStat.cbInQue;
}
//读取串口数据，buffer:读入缓冲区,dwBytesRead读入的字符串数目
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
//通过串口发送数据，buffer:发送缓冲区,dwBytesWritten:发送的字符串数目
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
//关闭串口
int CWebCom::Close()
{
	return CloseHandle(m_hComDev);
}
//显示字符串
DWORD CWebCom::WriteData(const char *buffer, DWORD dwBytesWritten)
{	
	char cominfo[1024];
	if( ReadData( cominfo, 1024) )
		::MessageBox(NULL,cominfo,buffer,MB_OK);
	else
		::MessageBox(NULL,buffer,buffer,MB_OK);

	return 1;
}
//把字符写入文件,file为文件名称,data为写入文件的内容
DWORD CWebCom::TraceInfo(const char *file, const char *data)
{
	HANDLE hFile = CreateFile(file, GENERIC_WRITE, 0, NULL, OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL);//创建文件   
	if ( hFile != NULL  )
	{
		DWORD dwWritten;
		WriteFile(hFile, data, strlen(data), &dwWritten, NULL); // 写入文件头
		CloseHandle(hFile); 
		return 1;
	}
	return 0;
}


//接口:通过串口发送字符串
STDMETHODIMP CWebCom::SendData(BSTR data)
{
	char szANSIString [1024]; 
	
	WideCharToMultiByte ( CP_ACP,                // ANSI 代码页 
                          WC_COMPOSITECHECK, // 检查重音字符 
                          data,         // 原Unicode 串 
                          -1,                    // -1 意思是串以0x00结尾 
                          szANSIString,          // 目的char字符串 
                          sizeof(szANSIString),  // 缓冲大小 
                          NULL,                  // 肥缺省字符串 
                          NULL );                // 忽略这个参数  
	long sz = strlen(szANSIString);
	SendData(szANSIString,sz);
	return S_OK;
}


//接口:显示字符串，测试用
STDMETHODIMP CWebCom::MsgInfo(BSTR Data)
{
	char szANSIString [1024]; 
	
	WideCharToMultiByte ( CP_ACP,                // ANSI 代码页 
                          WC_COMPOSITECHECK, // 检查重音字符 
                          Data,         // 原Unicode 串 
                          -1,                    // -1 意思是串以0x00结尾 
                          szANSIString,          // 目的char字符串 
                          sizeof(szANSIString),  // 缓冲大小 
                          NULL,                  // 肥缺省字符串 
                          NULL );                // 忽略这个参数  
	WriteData(szANSIString,strlen(szANSIString));

	return S_OK;
}
//接口:打开串口
STDMETHODIMP CWebCom::OpenPort(long nPort, long nBaud)
{
	Open(nPort, nBaud,7,EVENPARITY,ONESTOPBIT);
	return S_OK;
}

STDMETHODIMP CWebCom::OpenPortParam(long nPort, long nBaud, long nByteSzie, long nParity, long StopBit)
{
	//char szANSIString [256]; 
	//wsprintfA(szANSIString,"串口%d-波特率%d-数据位%d-基偶校验%d-停止位%d",nPort, nBaud,nByteSzie,nParity,StopBit);
	//::MessageBox(NULL,szANSIString,"串口数据显示",MB_OK);
	Open(nPort, nBaud,nByteSzie,nParity,StopBit);
	return S_OK;	
}
//接口:关闭串口
STDMETHODIMP CWebCom::ClosePort()
{
	Close();
	return S_OK;
}


//接口:将数据写入文件,File为文件名,Data为写入内容
STDMETHODIMP CWebCom::TraceInfo(BSTR File, BSTR Data)
{
	char szANSIFile [128]; 
	char szANSIData [1024]; 
	
	WideCharToMultiByte ( CP_ACP,                // ANSI 代码页 
                          WC_COMPOSITECHECK, // 检查重音字符 
                          File,         // 原Unicode 串 
                          -1,                    // -1 意思是串以0x00结尾 
                          szANSIFile,          // 目的char字符串 
                          sizeof(szANSIFile),  // 缓冲大小 
                          NULL,                  // 肥缺省字符串 
                          NULL );                // 忽略这个参数  
	WideCharToMultiByte ( CP_ACP,                // ANSI 代码页 
                          WC_COMPOSITECHECK, // 检查重音字符 
                          Data,         // 原Unicode 串 
                          -1,                    // -1 意思是串以0x00结尾 
                          szANSIData,          // 目的char字符串 
                          sizeof(szANSIData),  // 缓冲大小 
                          NULL,                  // 肥缺省字符串 
                          NULL );                // 忽略这个参数  
	TraceInfo(szANSIFile,szANSIData);

	return S_OK;
}



