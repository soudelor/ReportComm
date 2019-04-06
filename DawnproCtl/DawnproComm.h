/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Dec 29 21:05:19 2010
 */
/* Compiler settings for D:\data\My Document\project\DawnproCtl\DawnproComm.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __DawnproComm_h__
#define __DawnproComm_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IWebCom_FWD_DEFINED__
#define __IWebCom_FWD_DEFINED__
typedef interface IWebCom IWebCom;
#endif 	/* __IWebCom_FWD_DEFINED__ */


#ifndef __IWebComUI_FWD_DEFINED__
#define __IWebComUI_FWD_DEFINED__
typedef interface IWebComUI IWebComUI;
#endif 	/* __IWebComUI_FWD_DEFINED__ */


#ifndef __IReport_FWD_DEFINED__
#define __IReport_FWD_DEFINED__
typedef interface IReport IReport;
#endif 	/* __IReport_FWD_DEFINED__ */


#ifndef __IReportUI_FWD_DEFINED__
#define __IReportUI_FWD_DEFINED__
typedef interface IReportUI IReportUI;
#endif 	/* __IReportUI_FWD_DEFINED__ */


#ifndef __WebCom_FWD_DEFINED__
#define __WebCom_FWD_DEFINED__

#ifdef __cplusplus
typedef class WebCom WebCom;
#else
typedef struct WebCom WebCom;
#endif /* __cplusplus */

#endif 	/* __WebCom_FWD_DEFINED__ */


#ifndef __Report_FWD_DEFINED__
#define __Report_FWD_DEFINED__

#ifdef __cplusplus
typedef class Report Report;
#else
typedef struct Report Report;
#endif /* __cplusplus */

#endif 	/* __Report_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IWebCom_INTERFACE_DEFINED__
#define __IWebCom_INTERFACE_DEFINED__

/* interface IWebCom */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IWebCom;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B25F6435-55EA-4284-AED0-18304F565FCF")
    IWebCom : public IDispatch
    {
    public:
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Appearance( 
            /* [in] */ short appearance) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Appearance( 
            /* [retval][out] */ short __RPC_FAR *pappearance) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenPort( 
            long nPort,
            long nBaud) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendData( 
            BSTR data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClosePort( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MsgInfo( 
            BSTR Data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TraceInfo( 
            BSTR File,
            BSTR Data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenPortParam( 
            long nPort,
            long nBaud,
            long nByteSzie,
            long nParity,
            long StopBit) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWebComVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IWebCom __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IWebCom __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IWebCom __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IWebCom __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IWebCom __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IWebCom __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IWebCom __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Enabled )( 
            IWebCom __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enabled )( 
            IWebCom __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Appearance )( 
            IWebCom __RPC_FAR * This,
            /* [in] */ short appearance);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Appearance )( 
            IWebCom __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pappearance);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenPort )( 
            IWebCom __RPC_FAR * This,
            long nPort,
            long nBaud);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SendData )( 
            IWebCom __RPC_FAR * This,
            BSTR data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClosePort )( 
            IWebCom __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MsgInfo )( 
            IWebCom __RPC_FAR * This,
            BSTR Data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TraceInfo )( 
            IWebCom __RPC_FAR * This,
            BSTR File,
            BSTR Data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenPortParam )( 
            IWebCom __RPC_FAR * This,
            long nPort,
            long nBaud,
            long nByteSzie,
            long nParity,
            long StopBit);
        
        END_INTERFACE
    } IWebComVtbl;

    interface IWebCom
    {
        CONST_VTBL struct IWebComVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWebCom_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWebCom_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWebCom_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWebCom_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IWebCom_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IWebCom_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IWebCom_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IWebCom_put_Enabled(This,vbool)	\
    (This)->lpVtbl -> put_Enabled(This,vbool)

#define IWebCom_get_Enabled(This,pbool)	\
    (This)->lpVtbl -> get_Enabled(This,pbool)

#define IWebCom_put_Appearance(This,appearance)	\
    (This)->lpVtbl -> put_Appearance(This,appearance)

#define IWebCom_get_Appearance(This,pappearance)	\
    (This)->lpVtbl -> get_Appearance(This,pappearance)

#define IWebCom_OpenPort(This,nPort,nBaud)	\
    (This)->lpVtbl -> OpenPort(This,nPort,nBaud)

#define IWebCom_SendData(This,data)	\
    (This)->lpVtbl -> SendData(This,data)

#define IWebCom_ClosePort(This)	\
    (This)->lpVtbl -> ClosePort(This)

#define IWebCom_MsgInfo(This,Data)	\
    (This)->lpVtbl -> MsgInfo(This,Data)

#define IWebCom_TraceInfo(This,File,Data)	\
    (This)->lpVtbl -> TraceInfo(This,File,Data)

#define IWebCom_OpenPortParam(This,nPort,nBaud,nByteSzie,nParity,StopBit)	\
    (This)->lpVtbl -> OpenPortParam(This,nPort,nBaud,nByteSzie,nParity,StopBit)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propput] */ HRESULT STDMETHODCALLTYPE IWebCom_put_Enabled_Proxy( 
    IWebCom __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL vbool);


void __RPC_STUB IWebCom_put_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IWebCom_get_Enabled_Proxy( 
    IWebCom __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbool);


void __RPC_STUB IWebCom_get_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IWebCom_put_Appearance_Proxy( 
    IWebCom __RPC_FAR * This,
    /* [in] */ short appearance);


void __RPC_STUB IWebCom_put_Appearance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IWebCom_get_Appearance_Proxy( 
    IWebCom __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pappearance);


void __RPC_STUB IWebCom_get_Appearance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebCom_OpenPort_Proxy( 
    IWebCom __RPC_FAR * This,
    long nPort,
    long nBaud);


void __RPC_STUB IWebCom_OpenPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebCom_SendData_Proxy( 
    IWebCom __RPC_FAR * This,
    BSTR data);


void __RPC_STUB IWebCom_SendData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebCom_ClosePort_Proxy( 
    IWebCom __RPC_FAR * This);


void __RPC_STUB IWebCom_ClosePort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebCom_MsgInfo_Proxy( 
    IWebCom __RPC_FAR * This,
    BSTR Data);


void __RPC_STUB IWebCom_MsgInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebCom_TraceInfo_Proxy( 
    IWebCom __RPC_FAR * This,
    BSTR File,
    BSTR Data);


void __RPC_STUB IWebCom_TraceInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWebCom_OpenPortParam_Proxy( 
    IWebCom __RPC_FAR * This,
    long nPort,
    long nBaud,
    long nByteSzie,
    long nParity,
    long StopBit);


void __RPC_STUB IWebCom_OpenPortParam_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWebCom_INTERFACE_DEFINED__ */


#ifndef __IWebComUI_INTERFACE_DEFINED__
#define __IWebComUI_INTERFACE_DEFINED__

/* interface IWebComUI */
/* [unique][helpstring][uuid][dual][object] */ 


EXTERN_C const IID IID_IWebComUI;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0A955494-4A7F-4283-BCDE-CE915D1CE171")
    IWebComUI : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnClick( 
            /* [in] */ IDispatch __RPC_FAR *pdispBody,
            /* [in] */ VARIANT varColor) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWebComUIVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IWebComUI __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IWebComUI __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IWebComUI __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IWebComUI __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IWebComUI __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IWebComUI __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IWebComUI __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnClick )( 
            IWebComUI __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *pdispBody,
            /* [in] */ VARIANT varColor);
        
        END_INTERFACE
    } IWebComUIVtbl;

    interface IWebComUI
    {
        CONST_VTBL struct IWebComUIVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWebComUI_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWebComUI_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWebComUI_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWebComUI_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IWebComUI_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IWebComUI_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IWebComUI_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IWebComUI_OnClick(This,pdispBody,varColor)	\
    (This)->lpVtbl -> OnClick(This,pdispBody,varColor)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWebComUI_OnClick_Proxy( 
    IWebComUI __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *pdispBody,
    /* [in] */ VARIANT varColor);


void __RPC_STUB IWebComUI_OnClick_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWebComUI_INTERFACE_DEFINED__ */


#ifndef __IReport_INTERFACE_DEFINED__
#define __IReport_INTERFACE_DEFINED__

/* interface IReport */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IReport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("422C35F2-A91C-47C4-8764-70DC8B902FF1")
    IReport : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FilePath( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Print( 
            long __RPC_FAR *rtnValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PrintString( 
            BSTR Content) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Orientation( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowPrintDlg( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Printer( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Printer( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IReportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IReport __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IReport __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IReport __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IReport __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IReport __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IReport __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IReport __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FilePath )( 
            IReport __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Print )( 
            IReport __RPC_FAR * This,
            long __RPC_FAR *rtnValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PrintString )( 
            IReport __RPC_FAR * This,
            BSTR Content);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Orientation )( 
            IReport __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ShowPrintDlg )( 
            IReport __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Printer )( 
            IReport __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Printer )( 
            IReport __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IReportVtbl;

    interface IReport
    {
        CONST_VTBL struct IReportVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IReport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IReport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IReport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IReport_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IReport_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IReport_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IReport_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IReport_put_FilePath(This,newVal)	\
    (This)->lpVtbl -> put_FilePath(This,newVal)

#define IReport_Print(This,rtnValue)	\
    (This)->lpVtbl -> Print(This,rtnValue)

#define IReport_PrintString(This,Content)	\
    (This)->lpVtbl -> PrintString(This,Content)

#define IReport_put_Orientation(This,newVal)	\
    (This)->lpVtbl -> put_Orientation(This,newVal)

#define IReport_put_ShowPrintDlg(This,newVal)	\
    (This)->lpVtbl -> put_ShowPrintDlg(This,newVal)

#define IReport_get_Printer(This,pVal)	\
    (This)->lpVtbl -> get_Printer(This,pVal)

#define IReport_put_Printer(This,newVal)	\
    (This)->lpVtbl -> put_Printer(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IReport_put_FilePath_Proxy( 
    IReport __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IReport_put_FilePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IReport_Print_Proxy( 
    IReport __RPC_FAR * This,
    long __RPC_FAR *rtnValue);


void __RPC_STUB IReport_Print_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IReport_PrintString_Proxy( 
    IReport __RPC_FAR * This,
    BSTR Content);


void __RPC_STUB IReport_PrintString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IReport_put_Orientation_Proxy( 
    IReport __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB IReport_put_Orientation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IReport_put_ShowPrintDlg_Proxy( 
    IReport __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB IReport_put_ShowPrintDlg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IReport_get_Printer_Proxy( 
    IReport __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IReport_get_Printer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IReport_put_Printer_Proxy( 
    IReport __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IReport_put_Printer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IReport_INTERFACE_DEFINED__ */


#ifndef __IReportUI_INTERFACE_DEFINED__
#define __IReportUI_INTERFACE_DEFINED__

/* interface IReportUI */
/* [unique][helpstring][uuid][dual][object] */ 


EXTERN_C const IID IID_IReportUI;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EC730A2B-4DD2-4BAE-AD8A-FAAFAB8DCF54")
    IReportUI : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnClick( 
            /* [in] */ IDispatch __RPC_FAR *pdispBody,
            /* [in] */ VARIANT varColor) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IReportUIVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IReportUI __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IReportUI __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IReportUI __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IReportUI __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IReportUI __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IReportUI __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IReportUI __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnClick )( 
            IReportUI __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *pdispBody,
            /* [in] */ VARIANT varColor);
        
        END_INTERFACE
    } IReportUIVtbl;

    interface IReportUI
    {
        CONST_VTBL struct IReportUIVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IReportUI_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IReportUI_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IReportUI_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IReportUI_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IReportUI_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IReportUI_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IReportUI_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IReportUI_OnClick(This,pdispBody,varColor)	\
    (This)->lpVtbl -> OnClick(This,pdispBody,varColor)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IReportUI_OnClick_Proxy( 
    IReportUI __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *pdispBody,
    /* [in] */ VARIANT varColor);


void __RPC_STUB IReportUI_OnClick_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IReportUI_INTERFACE_DEFINED__ */



#ifndef __DAWNPROCOMMLib_LIBRARY_DEFINED__
#define __DAWNPROCOMMLib_LIBRARY_DEFINED__

/* library DAWNPROCOMMLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_DAWNPROCOMMLib;

EXTERN_C const CLSID CLSID_WebCom;

#ifdef __cplusplus

class DECLSPEC_UUID("C79C2515-D2FA-4FC3-9208-060900571A1C")
WebCom;
#endif

EXTERN_C const CLSID CLSID_Report;

#ifdef __cplusplus

class DECLSPEC_UUID("34A9809A-579E-4DC0-A39C-B4F09446A708")
Report;
#endif
#endif /* __DAWNPROCOMMLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long __RPC_FAR *, unsigned long            , VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long __RPC_FAR *, VARIANT __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
