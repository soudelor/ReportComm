/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Dec 29 21:05:19 2010
 */
/* Compiler settings for D:\data\My Document\project\DawnproCtl\DawnproComm.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IWebCom = {0xB25F6435,0x55EA,0x4284,{0xAE,0xD0,0x18,0x30,0x4F,0x56,0x5F,0xCF}};


const IID IID_IWebComUI = {0x0A955494,0x4A7F,0x4283,{0xBC,0xDE,0xCE,0x91,0x5D,0x1C,0xE1,0x71}};


const IID IID_IReport = {0x422C35F2,0xA91C,0x47C4,{0x87,0x64,0x70,0xDC,0x8B,0x90,0x2F,0xF1}};


const IID IID_IReportUI = {0xEC730A2B,0x4DD2,0x4BAE,{0xAD,0x8A,0xFA,0xAF,0xAB,0x8D,0xCF,0x54}};


const IID LIBID_DAWNPROCOMMLib = {0x5D140B51,0x0DEF,0x434F,{0xA7,0x5F,0x18,0x1A,0x41,0xC1,0xE2,0xDA}};


const CLSID CLSID_WebCom = {0xC79C2515,0xD2FA,0x4FC3,{0x92,0x08,0x06,0x09,0x00,0x57,0x1A,0x1C}};


const CLSID CLSID_Report = {0x34A9809A,0x579E,0x4DC0,{0xA3,0x9C,0xB4,0xF0,0x94,0x46,0xA7,0x08}};


#ifdef __cplusplus
}
#endif

