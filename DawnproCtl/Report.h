// Report.h : Declaration of the CReport

#ifndef __REPORT_H_
#define __REPORT_H_

#include "resource.h"       // main symbols
#include <atlctl.h>
#include "PrintData.h"

extern vector<string> split(const string& src, string separate_character);
/////////////////////////////////////////////////////////////////////////////
// CReport
class ATL_NO_VTABLE CReport : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IReport, &IID_IReport, &LIBID_DAWNPROCOMMLib>,
	public IDispatchImpl<IReportUI, &IID_IReportUI, &LIBID_DAWNPROCOMMLib>,
	public IObjectSafetyImpl<CReport, INTERFACESAFE_FOR_UNTRUSTED_CALLER>,
	public CComControl<CReport>,
	public IPersistStreamInitImpl<CReport>,
	public IOleControlImpl<CReport>,
	public IOleObjectImpl<CReport>,
	public IOleInPlaceActiveObjectImpl<CReport>,
	public IViewObjectExImpl<CReport>,
	public IOleInPlaceObjectWindowlessImpl<CReport>,	
	public CComCoClass<CReport, &CLSID_Report>
{
public:
	CReport()
	{
		m_bWindowOnly = TRUE;
		m_UrlPath = "";
		m_iShowPrintDlg = 0;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_REPORT)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CReport)
	COM_INTERFACE_ENTRY(IReport)
	COM_INTERFACE_ENTRY(IReportUI)
	COM_INTERFACE_ENTRY2(IDispatch, IReport)
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

BEGIN_PROP_MAP(CReport)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_MSG_MAP(CReport)
	MESSAGE_HANDLER(WM_CREATE, OnCreate)
	CHAIN_MSG_MAP(CComControl<CReport>)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);



// IViewObjectEx
	DECLARE_VIEW_STATUS(0)
public:
	CPrintData m_PrintData;
	string m_UrlPath;
	string m_Printer;
	short m_iShowPrintDlg;
	short m_inCopys;
	short m_iOrientation;
// IReport
public:
	//获得打印DC	
	bool GetPrintDC(HDC *hdc);
	bool GetPrintDC(HDC *hdc, BSTR printName, BSTR printDrv, BSTR printID);
	//获得打印机信息
	bool GetPrinterInfo(HWND hWnd, DOCINFO& di, PRINTDLG& pd);
	long Print();
public:
	STDMETHOD(Print)(long* rtnValue);
	STDMETHOD(put_FilePath)(/*[in]*/ BSTR newVal);
// IReportUI
public:	
	STDMETHOD(get_Printer)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Printer)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_Copys)(/*[out, retval]*/ short *pVal);
	STDMETHOD(put_Copys)(/*[in]*/ short newVal);
	STDMETHOD(put_ShowPrintDlg)(/*[in]*/ short newVal);
	STDMETHOD(put_Orientation)(/*[in]*/ short newVal);
	STDMETHOD(PrintString)(BSTR Content);
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
		HRESULT hr = wnd.CreateControl(IDH_REPORT);
		if (SUCCEEDED(hr))
			hr = wnd.SetExternalDispatch(static_cast<IReportUI*>(this));
		if (SUCCEEDED(hr))
			hr = wnd.QueryControl(IID_IWebBrowser2, (void**)&m_spBrowser);
		return SUCCEEDED(hr) ? 0 : -1;
	}
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
	CComPtr<IWebBrowser2> m_spBrowser;
protected:
	bool GetDefaultPrintDC(HDC *hdc);
	bool GetPrintDCByName(HDC *hdc,string printer);
};

#endif //__REPORT_H_


