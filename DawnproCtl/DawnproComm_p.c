/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Dec 29 21:05:19 2010
 */
/* Compiler settings for D:\data\My Document\project\DawnproCtl\DawnproComm.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 440
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "DawnproComm.h"

#define TYPE_FORMAT_STRING_SIZE   1007                              
#define PROC_FORMAT_STRING_SIZE   541                               

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IWebCom, ver. 0.0,
   GUID={0xB25F6435,0x55EA,0x4284,{0xAE,0xD0,0x18,0x30,0x4F,0x56,0x5F,0xCF}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWebCom_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IWebCom_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    28,
    56,
    84,
    112,
    146,
    174,
    196,
    224,
    258
    };

static const MIDL_SERVER_INFO IWebCom_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWebCom_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IWebCom_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWebCom_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(17) _IWebComProxyVtbl = 
{
    &IWebCom_ProxyInfo,
    &IID_IWebCom,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IWebCom::put_Enabled */ ,
    (void *)-1 /* IWebCom::get_Enabled */ ,
    (void *)-1 /* IWebCom::put_Appearance */ ,
    (void *)-1 /* IWebCom::get_Appearance */ ,
    (void *)-1 /* IWebCom::OpenPort */ ,
    (void *)-1 /* IWebCom::SendData */ ,
    (void *)-1 /* IWebCom::ClosePort */ ,
    (void *)-1 /* IWebCom::MsgInfo */ ,
    (void *)-1 /* IWebCom::TraceInfo */ ,
    (void *)-1 /* IWebCom::OpenPortParam */
};


static const PRPC_STUB_FUNCTION IWebCom_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IWebComStubVtbl =
{
    &IID_IWebCom,
    &IWebCom_ServerInfo,
    17,
    &IWebCom_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IWebComUI, ver. 0.0,
   GUID={0x0A955494,0x4A7F,0x4283,{0xBC,0xDE,0xCE,0x91,0x5D,0x1C,0xE1,0x71}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWebComUI_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IWebComUI_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    310
    };

static const MIDL_SERVER_INFO IWebComUI_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWebComUI_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IWebComUI_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWebComUI_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(8) _IWebComUIProxyVtbl = 
{
    &IWebComUI_ProxyInfo,
    &IID_IWebComUI,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IWebComUI::OnClick */
};


static const PRPC_STUB_FUNCTION IWebComUI_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2
};

CInterfaceStubVtbl _IWebComUIStubVtbl =
{
    &IID_IWebComUI,
    &IWebComUI_ServerInfo,
    8,
    &IWebComUI_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IReport, ver. 0.0,
   GUID={0x422C35F2,0xA91C,0x47C4,{0x87,0x64,0x70,0xDC,0x8B,0x90,0x2F,0xF1}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IReport_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IReport_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    344,
    372,
    400,
    428,
    456,
    484,
    512
    };

static const MIDL_SERVER_INFO IReport_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IReport_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IReport_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IReport_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(14) _IReportProxyVtbl = 
{
    &IReport_ProxyInfo,
    &IID_IReport,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IReport::put_FilePath */ ,
    (void *)-1 /* IReport::Print */ ,
    (void *)-1 /* IReport::PrintString */ ,
    (void *)-1 /* IReport::put_Orientation */ ,
    (void *)-1 /* IReport::put_ShowPrintDlg */ ,
    (void *)-1 /* IReport::get_Printer */ ,
    (void *)-1 /* IReport::put_Printer */
};


static const PRPC_STUB_FUNCTION IReport_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IReportStubVtbl =
{
    &IID_IReport,
    &IReport_ServerInfo,
    14,
    &IReport_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IReportUI, ver. 0.0,
   GUID={0xEC730A2B,0x4DD2,0x4BAE,{0xAD,0x8A,0xFA,0xAF,0xAB,0x8D,0xCF,0x54}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IReportUI_ServerInfo;

#pragma code_seg(".orpc")
extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[2];

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x20000, /* Ndr library version */
    0,
    0x50100a4, /* MIDL Version 5.1.164 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    1,  /* Flags */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
    };

static const unsigned short IReportUI_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    310
    };

static const MIDL_SERVER_INFO IReportUI_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IReportUI_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IReportUI_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IReportUI_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(8) _IReportUIProxyVtbl = 
{
    &IReportUI_ProxyInfo,
    &IID_IReportUI,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IReportUI::OnClick */
};


static const PRPC_STUB_FUNCTION IReportUI_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2
};

CInterfaceStubVtbl _IReportUIStubVtbl =
{
    &IID_IReportUI,
    &IReportUI_ServerInfo,
    8,
    &IReportUI_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

#pragma data_seg(".rdata")

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[2] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            },
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            }

        };


#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT40_OR_LATER)
#error You need a Windows NT 4.0 or later to run this stub because it uses these features:
#error   -Oif or -Oicf, [wire_marshal] or [user_marshal] attribute, more than 32 methods in the interface.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure put_Enabled */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/*  8 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 10 */	NdrFcShort( 0x6 ),	/* 6 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter vbool */

/* 16 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 18 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 20 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 22 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 24 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 26 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Enabled */

/* 28 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 30 */	NdrFcLong( 0x0 ),	/* 0 */
/* 34 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 36 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 38 */	NdrFcShort( 0x0 ),	/* 0 */
/* 40 */	NdrFcShort( 0xe ),	/* 14 */
/* 42 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pbool */

/* 44 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 46 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 48 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 50 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 52 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 54 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Appearance */

/* 56 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 58 */	NdrFcLong( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
/* 64 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 66 */	NdrFcShort( 0x6 ),	/* 6 */
/* 68 */	NdrFcShort( 0x8 ),	/* 8 */
/* 70 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter appearance */

/* 72 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 74 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 76 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 78 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 80 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 82 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Appearance */

/* 84 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 86 */	NdrFcLong( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0xa ),	/* 10 */
#ifndef _ALPHA_
/* 92 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */
/* 96 */	NdrFcShort( 0xe ),	/* 14 */
/* 98 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pappearance */

/* 100 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 102 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 104 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 106 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 108 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OpenPort */

/* 112 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 114 */	NdrFcLong( 0x0 ),	/* 0 */
/* 118 */	NdrFcShort( 0xb ),	/* 11 */
#ifndef _ALPHA_
/* 120 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 122 */	NdrFcShort( 0x10 ),	/* 16 */
/* 124 */	NdrFcShort( 0x8 ),	/* 8 */
/* 126 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nPort */

/* 128 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 130 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 132 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nBaud */

/* 134 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 136 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 138 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 140 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 142 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 144 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SendData */

/* 146 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 148 */	NdrFcLong( 0x0 ),	/* 0 */
/* 152 */	NdrFcShort( 0xc ),	/* 12 */
#ifndef _ALPHA_
/* 154 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 158 */	NdrFcShort( 0x8 ),	/* 8 */
/* 160 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter data */

/* 162 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 164 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 166 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 168 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 170 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 172 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ClosePort */

/* 174 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 176 */	NdrFcLong( 0x0 ),	/* 0 */
/* 180 */	NdrFcShort( 0xd ),	/* 13 */
#ifndef _ALPHA_
/* 182 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 186 */	NdrFcShort( 0x8 ),	/* 8 */
/* 188 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 192 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MsgInfo */

/* 196 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0xe ),	/* 14 */
#ifndef _ALPHA_
/* 204 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 208 */	NdrFcShort( 0x8 ),	/* 8 */
/* 210 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter Data */

/* 212 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 214 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 216 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 218 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 220 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 222 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TraceInfo */

/* 224 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 226 */	NdrFcLong( 0x0 ),	/* 0 */
/* 230 */	NdrFcShort( 0xf ),	/* 15 */
#ifndef _ALPHA_
/* 232 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 236 */	NdrFcShort( 0x8 ),	/* 8 */
/* 238 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter File */

/* 240 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 242 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 244 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Parameter Data */

/* 246 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 248 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 250 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 252 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 254 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 256 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OpenPortParam */

/* 258 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 260 */	NdrFcLong( 0x0 ),	/* 0 */
/* 264 */	NdrFcShort( 0x10 ),	/* 16 */
#ifndef _ALPHA_
/* 266 */	NdrFcShort( 0x1c ),	/* x86, MIPS, PPC Stack size/offset = 28 */
#else
			NdrFcShort( 0x38 ),	/* Alpha Stack size/offset = 56 */
#endif
/* 268 */	NdrFcShort( 0x28 ),	/* 40 */
/* 270 */	NdrFcShort( 0x8 ),	/* 8 */
/* 272 */	0x4,		/* Oi2 Flags:  has return, */
			0x6,		/* 6 */

	/* Parameter nPort */

/* 274 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 276 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 278 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nBaud */

/* 280 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 282 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 284 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nByteSzie */

/* 286 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 288 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 290 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nParity */

/* 292 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 294 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 296 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter StopBit */

/* 298 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 300 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 302 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 304 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 306 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 308 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OnClick */


	/* Procedure OnClick */

/* 310 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 312 */	NdrFcLong( 0x0 ),	/* 0 */
/* 316 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/* 318 */	NdrFcShort( 0x1c ),	/* x86, MIPS, PPC Stack size/offset = 28 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 322 */	NdrFcShort( 0x8 ),	/* 8 */
/* 324 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter pdispBody */


	/* Parameter pdispBody */

/* 326 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 328 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 330 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Parameter varColor */


	/* Parameter varColor */

/* 332 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 334 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 336 */	NdrFcShort( 0x3ce ),	/* Type Offset=974 */

	/* Return value */


	/* Return value */

/* 338 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 340 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 342 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_FilePath */

/* 344 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 346 */	NdrFcLong( 0x0 ),	/* 0 */
/* 350 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/* 352 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 356 */	NdrFcShort( 0x8 ),	/* 8 */
/* 358 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 360 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 362 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 364 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 366 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 368 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Print */

/* 372 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 374 */	NdrFcLong( 0x0 ),	/* 0 */
/* 378 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 380 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 382 */	NdrFcShort( 0x8 ),	/* 8 */
/* 384 */	NdrFcShort( 0x8 ),	/* 8 */
/* 386 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter rtnValue */

/* 388 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
#ifndef _ALPHA_
/* 390 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 392 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 394 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 396 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 398 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PrintString */

/* 400 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 402 */	NdrFcLong( 0x0 ),	/* 0 */
/* 406 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
/* 408 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 412 */	NdrFcShort( 0x8 ),	/* 8 */
/* 414 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter Content */

/* 416 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 418 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 420 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 422 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 424 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 426 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Orientation */

/* 428 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 430 */	NdrFcLong( 0x0 ),	/* 0 */
/* 434 */	NdrFcShort( 0xa ),	/* 10 */
#ifndef _ALPHA_
/* 436 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 438 */	NdrFcShort( 0x6 ),	/* 6 */
/* 440 */	NdrFcShort( 0x8 ),	/* 8 */
/* 442 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 444 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 446 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 448 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 450 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 452 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 454 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ShowPrintDlg */

/* 456 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 458 */	NdrFcLong( 0x0 ),	/* 0 */
/* 462 */	NdrFcShort( 0xb ),	/* 11 */
#ifndef _ALPHA_
/* 464 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 466 */	NdrFcShort( 0x6 ),	/* 6 */
/* 468 */	NdrFcShort( 0x8 ),	/* 8 */
/* 470 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 472 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 474 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 476 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 478 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 480 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 482 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Printer */

/* 484 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 486 */	NdrFcLong( 0x0 ),	/* 0 */
/* 490 */	NdrFcShort( 0xc ),	/* 12 */
#ifndef _ALPHA_
/* 492 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 496 */	NdrFcShort( 0x8 ),	/* 8 */
/* 498 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 500 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 502 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 504 */	NdrFcShort( 0x3e4 ),	/* Type Offset=996 */

	/* Return value */

/* 506 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 508 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 510 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Printer */

/* 512 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 514 */	NdrFcLong( 0x0 ),	/* 0 */
/* 518 */	NdrFcShort( 0xd ),	/* 13 */
#ifndef _ALPHA_
/* 520 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 524 */	NdrFcShort( 0x8 ),	/* 8 */
/* 526 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 528 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 530 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 532 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 534 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 536 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 538 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  4 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x12, 0x0,	/* FC_UP */
/*  8 */	NdrFcShort( 0xc ),	/* Offset= 12 (20) */
/* 10 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 12 */	NdrFcShort( 0x2 ),	/* 2 */
/* 14 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 16 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 18 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 20 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 22 */	NdrFcShort( 0x8 ),	/* 8 */
/* 24 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (10) */
/* 26 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 28 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 30 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 32 */	NdrFcShort( 0x0 ),	/* 0 */
/* 34 */	NdrFcShort( 0x4 ),	/* 4 */
/* 36 */	NdrFcShort( 0x0 ),	/* 0 */
/* 38 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (6) */
/* 40 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 42 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 46 */	NdrFcShort( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x0 ),	/* 0 */
/* 50 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 52 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 54 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 56 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 58 */	
			0x12, 0x0,	/* FC_UP */
/* 60 */	NdrFcShort( 0x37e ),	/* Offset= 894 (954) */
/* 62 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 64 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 66 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 68 */	NdrFcShort( 0x2 ),	/* Offset= 2 (70) */
/* 70 */	NdrFcShort( 0x10 ),	/* 16 */
/* 72 */	NdrFcShort( 0x2b ),	/* 43 */
/* 74 */	NdrFcLong( 0x3 ),	/* 3 */
/* 78 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 80 */	NdrFcLong( 0x11 ),	/* 17 */
/* 84 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 86 */	NdrFcLong( 0x2 ),	/* 2 */
/* 90 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 92 */	NdrFcLong( 0x4 ),	/* 4 */
/* 96 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 98 */	NdrFcLong( 0x5 ),	/* 5 */
/* 102 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 104 */	NdrFcLong( 0xb ),	/* 11 */
/* 108 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 110 */	NdrFcLong( 0xa ),	/* 10 */
/* 114 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 116 */	NdrFcLong( 0x6 ),	/* 6 */
/* 120 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (334) */
/* 122 */	NdrFcLong( 0x7 ),	/* 7 */
/* 126 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 128 */	NdrFcLong( 0x8 ),	/* 8 */
/* 132 */	NdrFcShort( 0xffffff82 ),	/* Offset= -126 (6) */
/* 134 */	NdrFcLong( 0xd ),	/* 13 */
/* 138 */	NdrFcShort( 0xca ),	/* Offset= 202 (340) */
/* 140 */	NdrFcLong( 0x9 ),	/* 9 */
/* 144 */	NdrFcShort( 0xffffff98 ),	/* Offset= -104 (40) */
/* 146 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 150 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (358) */
/* 152 */	NdrFcLong( 0x24 ),	/* 36 */
/* 156 */	NdrFcShort( 0x2da ),	/* Offset= 730 (886) */
/* 158 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 162 */	NdrFcShort( 0x2d4 ),	/* Offset= 724 (886) */
/* 164 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 168 */	NdrFcShort( 0x2d2 ),	/* Offset= 722 (890) */
/* 170 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 174 */	NdrFcShort( 0x2d0 ),	/* Offset= 720 (894) */
/* 176 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 180 */	NdrFcShort( 0x2ce ),	/* Offset= 718 (898) */
/* 182 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 186 */	NdrFcShort( 0x2cc ),	/* Offset= 716 (902) */
/* 188 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 192 */	NdrFcShort( 0x2ca ),	/* Offset= 714 (906) */
/* 194 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 198 */	NdrFcShort( 0x2b8 ),	/* Offset= 696 (894) */
/* 200 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 204 */	NdrFcShort( 0x2b6 ),	/* Offset= 694 (898) */
/* 206 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 210 */	NdrFcShort( 0x2bc ),	/* Offset= 700 (910) */
/* 212 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 216 */	NdrFcShort( 0x2b2 ),	/* Offset= 690 (906) */
/* 218 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 222 */	NdrFcShort( 0x2b4 ),	/* Offset= 692 (914) */
/* 224 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 228 */	NdrFcShort( 0x2b2 ),	/* Offset= 690 (918) */
/* 230 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 234 */	NdrFcShort( 0x2b0 ),	/* Offset= 688 (922) */
/* 236 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 240 */	NdrFcShort( 0x2ae ),	/* Offset= 686 (926) */
/* 242 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 246 */	NdrFcShort( 0x2ac ),	/* Offset= 684 (930) */
/* 248 */	NdrFcLong( 0x10 ),	/* 16 */
/* 252 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 254 */	NdrFcLong( 0x12 ),	/* 18 */
/* 258 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 260 */	NdrFcLong( 0x13 ),	/* 19 */
/* 264 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 266 */	NdrFcLong( 0x16 ),	/* 22 */
/* 270 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 272 */	NdrFcLong( 0x17 ),	/* 23 */
/* 276 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 278 */	NdrFcLong( 0xe ),	/* 14 */
/* 282 */	NdrFcShort( 0x290 ),	/* Offset= 656 (938) */
/* 284 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 288 */	NdrFcShort( 0x296 ),	/* Offset= 662 (950) */
/* 290 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 294 */	NdrFcShort( 0x254 ),	/* Offset= 596 (890) */
/* 296 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 300 */	NdrFcShort( 0x252 ),	/* Offset= 594 (894) */
/* 302 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 306 */	NdrFcShort( 0x250 ),	/* Offset= 592 (898) */
/* 308 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 312 */	NdrFcShort( 0x24a ),	/* Offset= 586 (898) */
/* 314 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 318 */	NdrFcShort( 0x244 ),	/* Offset= 580 (898) */
/* 320 */	NdrFcLong( 0x0 ),	/* 0 */
/* 324 */	NdrFcShort( 0x0 ),	/* Offset= 0 (324) */
/* 326 */	NdrFcLong( 0x1 ),	/* 1 */
/* 330 */	NdrFcShort( 0x0 ),	/* Offset= 0 (330) */
/* 332 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (331) */
/* 334 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 336 */	NdrFcShort( 0x8 ),	/* 8 */
/* 338 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 340 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 342 */	NdrFcLong( 0x0 ),	/* 0 */
/* 346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 350 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 352 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 354 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 356 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 358 */	
			0x12, 0x0,	/* FC_UP */
/* 360 */	NdrFcShort( 0x1fc ),	/* Offset= 508 (868) */
/* 362 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 364 */	NdrFcShort( 0x18 ),	/* 24 */
/* 366 */	NdrFcShort( 0xa ),	/* 10 */
/* 368 */	NdrFcLong( 0x8 ),	/* 8 */
/* 372 */	NdrFcShort( 0x58 ),	/* Offset= 88 (460) */
/* 374 */	NdrFcLong( 0xd ),	/* 13 */
/* 378 */	NdrFcShort( 0x78 ),	/* Offset= 120 (498) */
/* 380 */	NdrFcLong( 0x9 ),	/* 9 */
/* 384 */	NdrFcShort( 0x94 ),	/* Offset= 148 (532) */
/* 386 */	NdrFcLong( 0xc ),	/* 12 */
/* 390 */	NdrFcShort( 0xbc ),	/* Offset= 188 (578) */
/* 392 */	NdrFcLong( 0x24 ),	/* 36 */
/* 396 */	NdrFcShort( 0x114 ),	/* Offset= 276 (672) */
/* 398 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 402 */	NdrFcShort( 0x130 ),	/* Offset= 304 (706) */
/* 404 */	NdrFcLong( 0x10 ),	/* 16 */
/* 408 */	NdrFcShort( 0x148 ),	/* Offset= 328 (736) */
/* 410 */	NdrFcLong( 0x2 ),	/* 2 */
/* 414 */	NdrFcShort( 0x160 ),	/* Offset= 352 (766) */
/* 416 */	NdrFcLong( 0x3 ),	/* 3 */
/* 420 */	NdrFcShort( 0x178 ),	/* Offset= 376 (796) */
/* 422 */	NdrFcLong( 0x14 ),	/* 20 */
/* 426 */	NdrFcShort( 0x190 ),	/* Offset= 400 (826) */
/* 428 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (427) */
/* 430 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 432 */	NdrFcShort( 0x4 ),	/* 4 */
/* 434 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 438 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 440 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 442 */	NdrFcShort( 0x4 ),	/* 4 */
/* 444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 446 */	NdrFcShort( 0x1 ),	/* 1 */
/* 448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 452 */	0x12, 0x0,	/* FC_UP */
/* 454 */	NdrFcShort( 0xfffffe4e ),	/* Offset= -434 (20) */
/* 456 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 458 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 460 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 462 */	NdrFcShort( 0x8 ),	/* 8 */
/* 464 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 466 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 468 */	NdrFcShort( 0x4 ),	/* 4 */
/* 470 */	NdrFcShort( 0x4 ),	/* 4 */
/* 472 */	0x11, 0x0,	/* FC_RP */
/* 474 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (430) */
/* 476 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 478 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 480 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 482 */	NdrFcShort( 0x0 ),	/* 0 */
/* 484 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 488 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 492 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 494 */	NdrFcShort( 0xffffff66 ),	/* Offset= -154 (340) */
/* 496 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 498 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 500 */	NdrFcShort( 0x8 ),	/* 8 */
/* 502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 504 */	NdrFcShort( 0x6 ),	/* Offset= 6 (510) */
/* 506 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 508 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 510 */	
			0x11, 0x0,	/* FC_RP */
/* 512 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (480) */
/* 514 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 518 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 522 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 526 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 528 */	NdrFcShort( 0xfffffe18 ),	/* Offset= -488 (40) */
/* 530 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 532 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 534 */	NdrFcShort( 0x8 ),	/* 8 */
/* 536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 538 */	NdrFcShort( 0x6 ),	/* Offset= 6 (544) */
/* 540 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 542 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 544 */	
			0x11, 0x0,	/* FC_RP */
/* 546 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (514) */
/* 548 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 550 */	NdrFcShort( 0x4 ),	/* 4 */
/* 552 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 556 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 558 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 560 */	NdrFcShort( 0x4 ),	/* 4 */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 564 */	NdrFcShort( 0x1 ),	/* 1 */
/* 566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 570 */	0x12, 0x0,	/* FC_UP */
/* 572 */	NdrFcShort( 0x17e ),	/* Offset= 382 (954) */
/* 574 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 576 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 578 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 580 */	NdrFcShort( 0x8 ),	/* 8 */
/* 582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 584 */	NdrFcShort( 0x6 ),	/* Offset= 6 (590) */
/* 586 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 588 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 590 */	
			0x11, 0x0,	/* FC_RP */
/* 592 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (548) */
/* 594 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 596 */	NdrFcLong( 0x2f ),	/* 47 */
/* 600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 604 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 606 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 608 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 610 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 612 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 614 */	NdrFcShort( 0x1 ),	/* 1 */
/* 616 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 618 */	NdrFcShort( 0x4 ),	/* 4 */
/* 620 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 622 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 624 */	NdrFcShort( 0x10 ),	/* 16 */
/* 626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 628 */	NdrFcShort( 0xa ),	/* Offset= 10 (638) */
/* 630 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 632 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 634 */	NdrFcShort( 0xffffffd8 ),	/* Offset= -40 (594) */
/* 636 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 638 */	
			0x12, 0x0,	/* FC_UP */
/* 640 */	NdrFcShort( 0xffffffe4 ),	/* Offset= -28 (612) */
/* 642 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 644 */	NdrFcShort( 0x4 ),	/* 4 */
/* 646 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 648 */	NdrFcShort( 0x0 ),	/* 0 */
/* 650 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 652 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 654 */	NdrFcShort( 0x4 ),	/* 4 */
/* 656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 658 */	NdrFcShort( 0x1 ),	/* 1 */
/* 660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 662 */	NdrFcShort( 0x0 ),	/* 0 */
/* 664 */	0x12, 0x0,	/* FC_UP */
/* 666 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (622) */
/* 668 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 670 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 672 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 674 */	NdrFcShort( 0x8 ),	/* 8 */
/* 676 */	NdrFcShort( 0x0 ),	/* 0 */
/* 678 */	NdrFcShort( 0x6 ),	/* Offset= 6 (684) */
/* 680 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 682 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 684 */	
			0x11, 0x0,	/* FC_RP */
/* 686 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (642) */
/* 688 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 690 */	NdrFcShort( 0x8 ),	/* 8 */
/* 692 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 694 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 696 */	NdrFcShort( 0x10 ),	/* 16 */
/* 698 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 700 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 702 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffff1 ),	/* Offset= -15 (688) */
			0x5b,		/* FC_END */
/* 706 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 708 */	NdrFcShort( 0x18 ),	/* 24 */
/* 710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 712 */	NdrFcShort( 0xa ),	/* Offset= 10 (722) */
/* 714 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 716 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 718 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (694) */
/* 720 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 722 */	
			0x11, 0x0,	/* FC_RP */
/* 724 */	NdrFcShort( 0xffffff0c ),	/* Offset= -244 (480) */
/* 726 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 728 */	NdrFcShort( 0x1 ),	/* 1 */
/* 730 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 734 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 736 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 738 */	NdrFcShort( 0x8 ),	/* 8 */
/* 740 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 742 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 744 */	NdrFcShort( 0x4 ),	/* 4 */
/* 746 */	NdrFcShort( 0x4 ),	/* 4 */
/* 748 */	0x12, 0x0,	/* FC_UP */
/* 750 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (726) */
/* 752 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 754 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 756 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 758 */	NdrFcShort( 0x2 ),	/* 2 */
/* 760 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 764 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 766 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 768 */	NdrFcShort( 0x8 ),	/* 8 */
/* 770 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 772 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 774 */	NdrFcShort( 0x4 ),	/* 4 */
/* 776 */	NdrFcShort( 0x4 ),	/* 4 */
/* 778 */	0x12, 0x0,	/* FC_UP */
/* 780 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (756) */
/* 782 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 784 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 786 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 788 */	NdrFcShort( 0x4 ),	/* 4 */
/* 790 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 794 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 796 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 798 */	NdrFcShort( 0x8 ),	/* 8 */
/* 800 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 802 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 804 */	NdrFcShort( 0x4 ),	/* 4 */
/* 806 */	NdrFcShort( 0x4 ),	/* 4 */
/* 808 */	0x12, 0x0,	/* FC_UP */
/* 810 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (786) */
/* 812 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 814 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 816 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 818 */	NdrFcShort( 0x8 ),	/* 8 */
/* 820 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 824 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 826 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 828 */	NdrFcShort( 0x8 ),	/* 8 */
/* 830 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 832 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 834 */	NdrFcShort( 0x4 ),	/* 4 */
/* 836 */	NdrFcShort( 0x4 ),	/* 4 */
/* 838 */	0x12, 0x0,	/* FC_UP */
/* 840 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (816) */
/* 842 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 844 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 846 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 848 */	NdrFcShort( 0x8 ),	/* 8 */
/* 850 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 852 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 854 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 856 */	NdrFcShort( 0x8 ),	/* 8 */
/* 858 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 860 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 862 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 864 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (846) */
/* 866 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 868 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 870 */	NdrFcShort( 0x28 ),	/* 40 */
/* 872 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (854) */
/* 874 */	NdrFcShort( 0x0 ),	/* Offset= 0 (874) */
/* 876 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 878 */	0x38,		/* FC_ALIGNM4 */
			0x8,		/* FC_LONG */
/* 880 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 882 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffdf7 ),	/* Offset= -521 (362) */
			0x5b,		/* FC_END */
/* 886 */	
			0x12, 0x0,	/* FC_UP */
/* 888 */	NdrFcShort( 0xfffffef6 ),	/* Offset= -266 (622) */
/* 890 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 892 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 894 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 896 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 898 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 900 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 902 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 904 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 906 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 908 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 910 */	
			0x12, 0x0,	/* FC_UP */
/* 912 */	NdrFcShort( 0xfffffdbe ),	/* Offset= -578 (334) */
/* 914 */	
			0x12, 0x10,	/* FC_UP */
/* 916 */	NdrFcShort( 0xfffffc72 ),	/* Offset= -910 (6) */
/* 918 */	
			0x12, 0x10,	/* FC_UP */
/* 920 */	NdrFcShort( 0xfffffdbc ),	/* Offset= -580 (340) */
/* 922 */	
			0x12, 0x10,	/* FC_UP */
/* 924 */	NdrFcShort( 0xfffffc8c ),	/* Offset= -884 (40) */
/* 926 */	
			0x12, 0x10,	/* FC_UP */
/* 928 */	NdrFcShort( 0xfffffdc6 ),	/* Offset= -570 (358) */
/* 930 */	
			0x12, 0x10,	/* FC_UP */
/* 932 */	NdrFcShort( 0x2 ),	/* Offset= 2 (934) */
/* 934 */	
			0x12, 0x0,	/* FC_UP */
/* 936 */	NdrFcShort( 0xfffffc58 ),	/* Offset= -936 (0) */
/* 938 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 940 */	NdrFcShort( 0x10 ),	/* 16 */
/* 942 */	0x6,		/* FC_SHORT */
			0x2,		/* FC_CHAR */
/* 944 */	0x2,		/* FC_CHAR */
			0x38,		/* FC_ALIGNM4 */
/* 946 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 948 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 950 */	
			0x12, 0x0,	/* FC_UP */
/* 952 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (938) */
/* 954 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 956 */	NdrFcShort( 0x20 ),	/* 32 */
/* 958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 960 */	NdrFcShort( 0x0 ),	/* Offset= 0 (960) */
/* 962 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 964 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 966 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 968 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 970 */	NdrFcShort( 0xfffffc74 ),	/* Offset= -908 (62) */
/* 972 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 974 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 976 */	NdrFcShort( 0x1 ),	/* 1 */
/* 978 */	NdrFcShort( 0x10 ),	/* 16 */
/* 980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 982 */	NdrFcShort( 0xfffffc64 ),	/* Offset= -924 (58) */
/* 984 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 986 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 988 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 990 */	NdrFcShort( 0x6 ),	/* Offset= 6 (996) */
/* 992 */	
			0x13, 0x0,	/* FC_OP */
/* 994 */	NdrFcShort( 0xfffffc32 ),	/* Offset= -974 (20) */
/* 996 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1000 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1004 */	NdrFcShort( 0xfffffff4 ),	/* Offset= -12 (992) */

			0x0
        }
    };

const CInterfaceProxyVtbl * _DawnproComm_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IReportUIProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWebComProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWebComUIProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IReportProxyVtbl,
    0
};

const CInterfaceStubVtbl * _DawnproComm_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IReportUIStubVtbl,
    ( CInterfaceStubVtbl *) &_IWebComStubVtbl,
    ( CInterfaceStubVtbl *) &_IWebComUIStubVtbl,
    ( CInterfaceStubVtbl *) &_IReportStubVtbl,
    0
};

PCInterfaceName const _DawnproComm_InterfaceNamesList[] = 
{
    "IReportUI",
    "IWebCom",
    "IWebComUI",
    "IReport",
    0
};

const IID *  _DawnproComm_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _DawnproComm_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _DawnproComm, pIID, n)

int __stdcall _DawnproComm_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _DawnproComm, 4, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _DawnproComm, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _DawnproComm, 4, *pIndex )
    
}

const ExtendedProxyFileInfo DawnproComm_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _DawnproComm_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _DawnproComm_StubVtblList,
    (const PCInterfaceName * ) & _DawnproComm_InterfaceNamesList,
    (const IID ** ) & _DawnproComm_BaseIIDList,
    & _DawnproComm_IID_Lookup, 
    4,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
