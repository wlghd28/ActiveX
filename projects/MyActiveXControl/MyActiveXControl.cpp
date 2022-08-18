// MyActiveXControl.cpp: CMyActiveXControlApp의 구현 및 DLL 등록입니다.

#include "pch.h"
#include "framework.h"
#include "MyActiveXControl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CMyActiveXControlApp theApp;

const GUID CDECL _tlid = {0x3f3e321f,0xb158,0x46d5,{0xa6,0x6b,0x57,0xdd,0x26,0x7d,0x94,0xc0}};
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CMyActiveXControlApp::InitInstance - DLL 초기화

BOOL CMyActiveXControlApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: 여기에 직접 작성한 모듈 초기화 코드를 추가합니다.
	}

	return bInit;
}



// CMyActiveXControlApp::ExitInstance - DLL 종료

int CMyActiveXControlApp::ExitInstance()
{
	// TODO: 여기에 직접 작성한 모듈 종료 코드를 추가합니다.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 시스템 레지스트리에 항목을 추가합니다.

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 시스템 레지스트리에서 항목을 제거합니다.

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
