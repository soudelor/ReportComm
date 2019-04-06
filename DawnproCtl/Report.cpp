// Report.cpp : Implementation of CReport
#include "stdafx.h"
#include "DawnproComm.h"
#include "Report.h"
#include "WININET.H"
#include "httpfile.h"
#include "basefun.h"
#include "comutil.h"
/////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CReport::put_FilePath(BSTR newVal)
{
	
	char szANSIData [128]; 
	WideCharToMultiByte ( CP_ACP,                // ANSI 代码页 
                          WC_COMPOSITECHECK, // 检查重音字符 
                          newVal,         // 原Unicode 串 
                          -1,                    // -1 意思是串以0x00结尾 
                          szANSIData,          // 目的char字符串 
                          sizeof(szANSIData),  // 缓冲大小 
                          NULL,                  // 肥缺省字符串 
                          NULL );                // 忽略这个参数  
	
	m_UrlPath=szANSIData;
	return S_OK;
}

STDMETHODIMP CReport::Print(long *rtnValue)
{	
	*rtnValue = Print();
	return S_OK;
}

long CReport::Print()
{
	HDC hdc;
	CHttpFile httpfile;
	CPrintData printdata;
	httpfile.StartHttpGet(m_UrlPath);
	
		
	long size=httpfile.GetWEBFileSize();
	httpfile.SetReadBufferSize(size);
	char* buffer = new char[size+1] ; 
	httpfile.Read(buffer,size+1);	
	m_PrintData.Read(buffer);
 	if(GetPrintDC(&hdc))
	{		
		m_PrintData.Print(hdc,0);
		::DeleteDC(hdc) ;
	}

	httpfile.EndHttpGet();
	delete []buffer;
	return 0;
}
//获得打印DC	
/****************************************************************************
Function:       GetPrintDC
Description:    取得打印DC
Calls:          无
Table Accessed: 无
Table Updated:  无
Input:			无
Output:         hdc 打印HDC指针
Return:         是否成功
****************************************************************************
*/
bool CReport::GetPrintDC(HDC *hdc)
{	
	
	if ( m_Printer!="" ) //指定打印机打印
	{
		//::MessageBox(NULL,"打印机名",m_Printer.c_str(),MB_OK);
		if(GetPrintDCByName(hdc,m_Printer))
			return true;				
	}

	DOCINFO  di;
	PRINTDLG pd;
	if (!GetPrinterInfo(NULL, di, pd))
	{
		return false;
	}
		
	HFONT hFont = CreateDispFont(pd.hDC, "宋体", 80, 0, 0, TRUE);
	::SelectObject(pd.hDC, hFont);
	
	// 得到显示字体高度
	int nXChar, nYChar;
	GetFontXY(pd.hDC, nXChar, nYChar);
	
	PageInfo pi;
	pi.hDC = pd.hDC;
	pi.hFont = hFont;
	pi.nXChar = nXChar;
	pi.nYChar = nYChar;
	//CString x,y;
	//x.Format("%d",nXChar);
	//y.Format("%d",nYChar);
	//MessageBox(x,y,0);
	pi.nPageCols = -1;
	pi.nPageRows = -1;
	pi.nRowsPerPage = -1;
	pi.nColsPerPage = 1; 
	pi.nTotalCols = 1; 
	pi.nTotalRows = -1; 
	LPDEVNAMES lpDevNames = (LPDEVNAMES)::GlobalLock(pd.hDevNames); 
	if (lpDevNames) 
	{
		strcpy(pi.szDev, (char*)lpDevNames + lpDevNames->wDeviceOffset);
		strcpy(pi.szDriver, (char*)lpDevNames + lpDevNames->wDriverOffset);
		strcpy(pi.szOutput, (char*)lpDevNames + lpDevNames->wOutputOffset); 
	}
	GlobalUnlock(lpDevNames);
	
	CComBSTR  bstrDev(pi.szDev);
	CComBSTR  bstrDriver(pi.szDriver);
	CComBSTR  bstrPort(pi.szOutput); 
	
	return GetPrintDC(hdc,bstrDev,bstrDriver,bstrPort);
}
/*
****************************************************************************
Function:       GetPrintDC
Description:    根据所给打印机取得打印DC
Calls:          无
Table Accessed: 无
Table Updated:  无
Input:			
BSTR printName  打印机名
BSTR printDrv	打印机驱动
BSTR printID	打印机ID
Output:         hdc 打印HDC指针
Return:         是否成功
****************************************************************************
*/
bool CReport::GetPrintDC(HDC *hdc, BSTR printName, BSTR printDrv, BSTR printID)
{
	char          lpPrintType[255];
    char          lpPrintDriver[255];
    char          lpPrintPort[255];
    char          pmodule[32];
    HANDLE        hDriver = 0;
    HANDLE        hDevMode = 0;
    LPDEVMODE     lpDevMode = NULL;
    LPFNDEVMODE   lpfnExtDeviceMode;
    int           count;
	
	{
		USES_CONVERSION;			
		strcpy(lpPrintType, W2A(printName));
		strcpy(lpPrintDriver, W2A(printDrv));
		strcpy(lpPrintPort, W2A(printID));
	}
    wsprintf (pmodule, "%s.drv",(LPSTR)lpPrintDriver);
	
    if(int(hDriver = LoadLibrary(pmodule)) > 31)
    {
        if (lpfnExtDeviceMode = (LPFNDEVMODE)GetProcAddress((HINSTANCE)hDriver,
			(LPSTR)"EXTDEVICEMODE"))
        {
			count = lpfnExtDeviceMode(0,
				(HINSTANCE)hDriver,
				NULL,
				lpPrintType,
				lpPrintPort,
				NULL,
				NULL,
				0);
			
			if (count != -1)
			{
				hDevMode = GlobalAlloc(GHND, count);
				
				if (hDevMode)
				{
					lpDevMode = (LPDEVMODE)GlobalLock(hDevMode);
					count = lpfnExtDeviceMode(0,
						(HINSTANCE)hDriver,
						lpDevMode,
						lpPrintType,
						lpPrintPort,
						NULL,
						NULL,
						DM_OUT_BUFFER);
			
					if (lpDevMode->dmFields & (DM_ORIENTATION|DM_COPIES) )
					{
						lpDevMode->dmFields = 0;
						lpDevMode->dmFields = (DM_ORIENTATION|DM_COPIES);
						lpDevMode->dmOrientation = m_iOrientation;//DMORIENT_LANDSCAPE;
						lpDevMode->dmCopies = m_inCopys;
						count = lpfnExtDeviceMode(0,
							(HINSTANCE)hDriver,
							lpDevMode,
							lpPrintType,
							lpPrintPort,
							lpDevMode,
							NULL,
							DM_OUT_BUFFER | DM_IN_BUFFER);
						*hdc = CreateDC(lpPrintDriver,
							lpPrintType,
							lpPrintPort,
							lpDevMode);
					}
					else
					{
						*hdc = CreateDC(lpPrintDriver,
							lpPrintType,
							lpPrintPort,
							lpDevMode);
					}
					GlobalUnlock(hDevMode);
					GlobalFree(hDevMode);
					FreeLibrary((HINSTANCE)hDriver);
					return true;
				} 
			} 
        } 
    } 
	if ((HINSTANCE)hDriver)
		FreeLibrary((HINSTANCE)hDriver);
	return false;
}
/*
****************************************************************************
Function:       GetPrinterInfo
Description:    取得打印信息
Calls:          无
Table Accessed: 无
Table Updated:  无
Input:			
HWND hWnd		当前窗口	
Output:         
DOCINFO& di		文档信息
PRINTDLG& pd	打印设置对话框
Return:         是否成功
****************************************************************************
*/
bool CReport::GetPrinterInfo(HWND hWnd, DOCINFO& di, PRINTDLG& pd)
{
	di.cbSize = sizeof(DOCINFO);
	di.lpszDocName = "LVN";
	di.lpszOutput = NULL;
	di.lpszDatatype = NULL;
	di.fwType = 0;
	
	pd.lStructSize         = sizeof (PRINTDLG);
	pd.hwndOwner           = hWnd;
	pd.hDevMode            = NULL;
	pd.hDevNames           = NULL;
	pd.hDC                 = NULL;
	
	pd.Flags               = PD_ALLPAGES | PD_COLLATE | PD_RETURNDC;
	if (m_iShowPrintDlg==0)
		pd.Flags = pd.Flags | PD_RETURNDEFAULT;

	pd.nFromPage           = 0;
	pd.nToPage             = 0;
	pd.nMinPage            = 0;
	pd.nMaxPage            = 0;
	pd.nCopies             = 1;
	pd.hInstance           = NULL;
	pd.lCustData           = 0L;
	pd.lpfnPrintHook       = NULL;
	pd.lpfnSetupHook       = NULL;
	pd.lpPrintTemplateName = NULL;
	pd.lpSetupTemplateName = NULL;
	pd.hPrintTemplate      = NULL;
	pd.hSetupTemplate      = NULL;
	
	if (::PrintDlg(&pd) == 0) 
	{
		return false;
	}
	if(m_iShowPrintDlg==0) //显示打印对话框
	{
		pd.nCopies = m_inCopys;
		LPDEVMODE lpDevMode  = (LPDEVMODE)::GlobalLock(pd.hDevMode);
		lpDevMode->dmOrientation = m_iOrientation;
		lpDevMode->dmPaperWidth = 200;
		lpDevMode->dmPaperLength = 200;	
		GlobalUnlock(pd.hDevMode);
	}
	m_inCopys = pd.nCopies;
	
	return true;
}



STDMETHODIMP CReport::PrintString(BSTR Content)
{	
	size_t sz = wcslen(Content)*2;
	char* szANSIData = new char[sz]; 
	//char szANSIData[1024]; 
	WideCharToMultiByte ( CP_ACP,                // ANSI 代码页 
                          WC_COMPOSITECHECK, // 检查重音字符 
                          Content,         // 原Unicode 串 
                          -1,                    // -1 意思是串以0x00结尾 
                          szANSIData,          // 目的char字符串 
                          sz,  // 缓冲大小 
                          NULL,                  // 肥缺省字符串 
                          NULL );                // 忽略这个参数  
	szANSIData[sz-1]=0;
	HDC hdc;
	m_PrintData.Read(szANSIData);
 	if(GetPrintDC(&hdc))
	{		
		m_PrintData.Print(hdc,0);
		::DeleteDC(hdc) ;
	}
	delete []szANSIData;
	return S_OK;
}

STDMETHODIMP CReport::put_Orientation(short newVal)
{
	m_iOrientation = newVal%10;
	m_inCopys = newVal/10; //接口已经确定，为避免不兼容，公用一个字段
	if ( m_inCopys == 0) 
		m_inCopys = 1;
	return S_OK;
}

bool CReport::GetDefaultPrintDC(HDC *hdc)
{
	char szprinter[80];
	char *szDevice,*szDriver,*szOutput;
	DOCINFO di={sizeof(DOCINFO),"printer",NULL};
	// 得到设备字符串存入数组szprinter中
	GetProfileString("windows","device",",,,",szprinter,80);
	
	// 将设备字符串分解
	if(NULL!=(szDevice=strtok(szprinter,","))&&
	NULL!=(szDriver=strtok(NULL,","))&&
	NULL!=(szOutput=strtok(NULL,",")))
	// 创建一个打印机设备句柄
	*hdc=CreateDC(szDriver,szDevice,szOutput,NULL);
	CComBSTR  bstrDev(szDevice);
	CComBSTR  bstrDriver(szDriver);
	CComBSTR  bstrPort(szOutput); 
	return GetPrintDC(hdc,bstrDev,bstrDriver,bstrPort);	
}

bool CReport::GetPrintDCByName(HDC *hdc,string printer)
{
	vector<string> parms =split(printer, "|");
	TCHAR szDevice[400], szDriver[400],szPort[400],gcszPrintKey[400];

	if( parms.size()!=3 && parms.size()>1) 
	{
		::MessageBox(NULL,"请在注册表查询，打印机名|打印机驱动|打印机端口","打印机参数不全",MB_OK);
		return false;
	}
	else if(parms.size()!=3){
		//::MessageBox(NULL,printer.c_str(),"printername",MB_OK);
		HKEY hKey;
		LONG lRet, lRet2;
		DWORD dwLength, dwDataType;

		char gcszlocal[]	= _T( "SYSTEM\\CurrentControlSet\\Control\\Print\\Printers\\" );
		memset(gcszPrintKey,0,sizeof(gcszPrintKey));
		strcat(gcszPrintKey,gcszlocal);
		strcat(gcszPrintKey,printer.c_str());
		const char gcszPrintName[] = _T("Name");
		const char gcszPrintDriver[] = _T("Printer Driver");
		const char gcszPrintPort[] = _T("Port");
		
				// 打开注册表键
		lRet = ::RegOpenKeyEx( HKEY_LOCAL_MACHINE, gcszPrintKey, 0, KEY_READ | KEY_WRITE, &hKey );
		if( lRet != ERROR_SUCCESS )
		{
			::MessageBox(NULL,"没有发现改打印机!","gcszPrintKey",MB_OK);
			return FALSE;
		}
		// 查询自动运行项目是否存在
		dwLength = sizeof( szDevice );
		lRet = ::RegQueryValueEx( hKey, gcszPrintName, NULL, &dwDataType, (LPBYTE)szDevice, &dwLength );
		if( lRet != ERROR_SUCCESS )
		{
			DWORD dwErrorCode = GetLastError();
			char temp[20];
			sprintf(temp,"failed. %d\n",lRet);	
			::MessageBox(NULL,temp,gcszPrintName,MB_OK);	
			return false;
		}
		dwLength = sizeof( szDriver );
		lRet = RegQueryValueEx( hKey, gcszPrintDriver, NULL, &dwDataType, (LPBYTE)szDriver, &dwLength );
		if( lRet != ERROR_SUCCESS )
		{
			char temp[20];
			sprintf(temp,"failed. %d\n",lRet);	
			::MessageBox(NULL,temp,gcszPrintDriver,MB_OK);
	
			return false;
		}
		dwLength = sizeof( szPort );
		lRet = RegQueryValueEx( hKey, gcszPrintPort, NULL, &dwDataType, (LPBYTE)szPort, &dwLength );
		if( lRet != ERROR_SUCCESS )
		{			
			char temp[20];
			sprintf(temp,"failed. %d\n",lRet);	
			::MessageBox(NULL,temp,gcszPrintPort,MB_OK);
			return false;
		}
			// 关闭注册表键
		RegCloseKey( hKey );		
	}

	if( parms.size()==3 ) 
	{
		strcpy( szDevice , parms[0].c_str());
		strcpy( szDriver , parms[1].c_str());
		strcpy( szPort , parms[2].c_str());
	}	
	// 创建一个打印机设备句柄
	*hdc=CreateDC(szDriver,szDevice,szPort,NULL);
	return true;
	
	//CComBSTR  bstrDev(szDevice);
	//CComBSTR  bstrDriver(szDriver);
	//CComBSTR  bstrPort(szOutput); 
	//return GetPrintDC(hdc,bstrDev,bstrDriver,bstrPort);		
}

STDMETHODIMP CReport::put_ShowPrintDlg(short newVal)
{
	//0:缺省打印机 1:弹出打印对话框
	m_iShowPrintDlg = newVal;
	return S_OK;
}

STDMETHODIMP CReport::get_Copys(short *pVal)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CReport::put_Copys(short newVal)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CReport::get_Printer(BSTR *pVal)
{
	// TODO: Add your implementation code here
//	* pVal =_bstr_t(m_Printer.c_str()); 
	return S_OK;
}

STDMETHODIMP CReport::put_Printer(BSTR newVal)
{
	char szANSIData [128]; 
	WideCharToMultiByte ( CP_ACP,                // ANSI 代码页 
                          WC_COMPOSITECHECK, // 检查重音字符 
                          newVal,         // 原Unicode 串 
                          -1,                    // -1 意思是串以0x00结尾 
                          szANSIData,          // 目的char字符串 
                          sizeof(szANSIData),  // 缓冲大小 
                          NULL,                  // 肥缺省字符串 
                          NULL );                // 忽略这个参数  
	
	m_Printer=szANSIData;
	 
	return S_OK;
}

vector<string> split(const string& src, string separate_character)
{
 vector< string > strs;
 int separate_characterLen = separate_character.size();//分割字符串的长度,这样就可以支持如“,,”多字符串的>分隔符
 int lastPosition = 0,index = -1;
 while (-1 != (index = src.find(separate_character,lastPosition)))
 {
      strs.push_back(src.substr(lastPosition,index - lastPosition));
      lastPosition = index + separate_characterLen;
 }
 string lastString = src.substr(lastPosition);//截取最后一个分隔符后的内容
 if (!lastString.empty())
      strs.push_back(lastString);//如果最后一个分隔符后还有内容就入队
 return strs;
}

