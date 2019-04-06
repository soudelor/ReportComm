// WebCom.h : Declaration of the CWebCom

#ifndef __WEBCOM_H_
#define __WEBCOM_H_

#include "resource.h"       // main symbols
#include <atlctl.h>


/////////////////////////////////////////////////////////////////////////////
// CWebCom
class ATL_NO_VTABLE CWebCom : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CStockPropImpl<CWebCom, IWebCom, &IID_IWebCom, &LIBID_DAWNPROCOMMLib>,
	public IDispatchImpl<IWebComUI, &IID_IWebComUI, &LIBID_DAWNPROCOMMLib>,
	public IObjectSafetyImpl<CWebCom, INTERFACESAFE_FOR_UNTRUSTED_CALLER>,
	public CComControl<CWebCom>,
	public IPersistStreamInitImpl<CWebCom>,
	public IOleControlImpl<CWebCom>,
	public IOleObjectImpl<CWebCom>,
	public IOleInPlaceActiveObjectImpl<CWebCom>,
	public IViewObjectExImpl<CWebCom>,
	public IOleInPlaceObjectWindowlessImpl<CWebCom>,
	public CComCoClass<CWebCom, &CLSID_WebCom>
{
public:
	CWebCom()
	{
		m_bWindowOnly = TRUE;
		m_bOpened = FALSE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_WEBCOM)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CWebCom)
	COM_INTERFACE_ENTRY(IWebCom)
	COM_INTERFACE_ENTRY(IWebComUI)
	COM_INTERFACE_ENTRY2(IDispatch, IWebCom)
	COM_INTERFACE_ENTRY(IObjectSafety) 
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
END_COM_MAP()

BEGIN_PROP_MAP(CWebCom)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	PROP_ENTRY("Appearance", DISPID_APPEARANCE, CLSID_NULL)
	PROP_ENTRY("Enabled", DISPID_ENABLED, CLSID_NULL)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_MSG_MAP(CWebCom)
	MESSAGE_HANDLER(WM_CREATE, OnCreate)
	CHAIN_MSG_MAP(CComControl<CWebCom>)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);



// IViewObjectEx
	DECLARE_VIEW_STATUS(0)

// IWebCom
public:
	short m_nAppearance;
	BOOL m_bEnabled;

// IWebComUI
public:
	STDMETHOD(OpenPortParam)(long nPort, long nBaud, long nByteSzie, long nParity, long StopBit);
	STDMETHOD(TraceInfo)(BSTR File,BSTR Data);
	STDMETHOD(MsgInfo)(BSTR Data);
	STDMETHOD(ClosePort)();
	STDMETHOD(SendData)(BSTR data);
	STDMETHOD(OpenPort)(long nPort,long nBaud);

	STDMETHOD(GetInterfaceSafetyOptions)(REFIID riid, DWORD *pdwSupportedOptions,
										DWORD *pdwEnabledOptions)
	{
		*pdwSupportedOptions = INTERFACESAFE_FOR_UNTRUSTED_CALLER | INTERFACESAFE_FOR_UNTRUSTED_DATA;
		*pdwEnabledOptions = INTERFACESAFE_FOR_UNTRUSTED_DATA;
		return S_OK;
	}
	STDMETHOD(SetInterfaceSafetyOptions)(REFIID riid, DWORD dwOptionSetMask,
										DWORD dwEnabledOptions)
	{
		 OLECHAR szGUID[39];
		 // What is this interface anyway?
		 // We can do a quick lookup in the registry under HKEY_CLASSES_ROOT\Interface
		 int i = StringFromGUID2(riid, szGUID, 39);

		 if (0 == dwOptionSetMask && 0 == dwEnabledOptions)
		 {
		  // the control certainly supports NO requests through the specified interface
		  // so it's safe to return S_OK even if the interface isn't supported.
		  return S_OK;
		 }

		 // Do we support the specified interface?
/*		 if (NULL == GetInterface(&riid))
		 {
		  TRACE1("%s is not support.\n", szGUID);
		  return E_FAIL;
		 }
*/

		 if (riid == IID_IDispatch)
		 {
		   if (INTERFACESAFE_FOR_UNTRUSTED_CALLER == dwOptionSetMask && INTERFACESAFE_FOR_UNTRUSTED_CALLER == dwEnabledOptions)
		  {
		   return S_OK;
		  }
		  else
		  {
		   return E_FAIL;
		  }
		 }
		 else if (riid == IID_IPersistPropertyBag 
			|| riid == IID_IPersistStreamInit
			|| riid == IID_IPersistStorage
			|| riid == IID_IPersistMemory)
		 {
		  if (INTERFACESAFE_FOR_UNTRUSTED_DATA == dwOptionSetMask && INTERFACESAFE_FOR_UNTRUSTED_DATA == dwEnabledOptions)
		  {
		   return NOERROR;
		  }
		  else
		  {
		   return E_FAIL;
		  }
		 }
		 else
		 {
		  return E_FAIL;
		 }


		return S_OK;
	}

	// Example method called by the HTML to change the <BODY> background color
	STDMETHOD(OnClick)(IDispatch* pdispBody, VARIANT varColor)
	{
		CComQIPtr<IHTMLBodyElement> spBody(pdispBody);
		if (spBody != NULL)
			spBody->put_bgColor(varColor);
		return S_OK;
	}

	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		CAxWindow wnd(m_hWnd);
		HRESULT hr = wnd.CreateControl(IDH_WEBCOM);
		if (SUCCEEDED(hr))
			hr = wnd.SetExternalDispatch(static_cast<IWebComUI*>(this));
		if (SUCCEEDED(hr))
			hr = wnd.QueryControl(IID_IWebBrowser2, (void**)&m_spBrowser);
		return SUCCEEDED(hr) ? 0 : -1;
	}

	CComPtr<IWebBrowser2> m_spBrowser;
protected:
	DWORD WriteData(const char *buffer,DWORD dwBytesWritten);
	BOOL m_bOpened;	
	HANDLE m_hComDev;
	OVERLAPPED m_OverlappedRead;
	OVERLAPPED m_OverlappedWrite;
	BOOL Open(int nPort, int nBaud,int nByteSize,int nParity,int nStopBits);
	int InBufferCount();
	DWORD ReadData( void *buffer, DWORD dwBytesRead);
	DWORD SendData( const char *buffer, DWORD dwBytesWritten);	
	DWORD TraceInfo(const char *file, const char *data);
	int Close();
};

#endif //__WEBCOM_H_
