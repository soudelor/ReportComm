
DawnproCommps.dll: dlldata.obj DawnproComm_p.obj DawnproComm_i.obj
	link /dll /out:DawnproCommps.dll /def:DawnproCommps.def /entry:DllMain dlldata.obj DawnproComm_p.obj DawnproComm_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del DawnproCommps.dll
	@del DawnproCommps.lib
	@del DawnproCommps.exp
	@del dlldata.obj
	@del DawnproComm_p.obj
	@del DawnproComm_i.obj
