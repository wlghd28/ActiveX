// MyActiveXControlPropPage.cpp : CMyActiveXControlPropPage 속성 페이지 클래스의 구현입니다.

#include "pch.h"
#include "framework.h"
#include "MyActiveXControl.h"
#include "MyActiveXControlPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMyActiveXControlPropPage, COlePropertyPage)

// 메시지 맵입니다.

BEGIN_MESSAGE_MAP(CMyActiveXControlPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 클래스 팩터리와 GUID를 초기화합니다.

IMPLEMENT_OLECREATE_EX(CMyActiveXControlPropPage, "MFCACTIVEXCONT.MyActiveXControlPropPage.1",
	0xcf581f0c,0xed07,0x46c5,0xa7,0x8b,0x5f,0xce,0x93,0x57,0x8e,0x39)

// CMyActiveXControlPropPage::CMyActiveXControlPropPageFactory::UpdateRegistry -
// CMyActiveXControlPropPage에 대한 시스템 레지스트리 항목을 추가하거나 제거합니다.

BOOL CMyActiveXControlPropPage::CMyActiveXControlPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MYACTIVEXCONTROL_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, nullptr);
}

// CMyActiveXControlPropPage::CMyActiveXControlPropPage - 생성자

CMyActiveXControlPropPage::CMyActiveXControlPropPage() :
	COlePropertyPage(IDD, IDS_MYACTIVEXCONTROL_PPG_CAPTION)
{
}

// CMyActiveXControlPropPage::DoDataExchange - 페이지와 속성 간 데이터를 이동합니다.

void CMyActiveXControlPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CMyActiveXControlPropPage 메시지 처리기
