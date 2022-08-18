// MyActiveXControlCtrl.cpp : CMyActiveXControlCtrl ActiveX 컨트롤 클래스의 구현입니다.

#include "pch.h"
#include "framework.h"
#include "MyActiveXControl.h"
#include "MyActiveXControlCtrl.h"
#include "MyActiveXControlPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMyActiveXControlCtrl, COleControl)

// 메시지 맵입니다.

BEGIN_MESSAGE_MAP(CMyActiveXControlCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// 디스패치 맵입니다.

BEGIN_DISPATCH_MAP(CMyActiveXControlCtrl, COleControl)
	DISP_FUNCTION_ID(CMyActiveXControlCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// 이벤트 맵입니다.

BEGIN_EVENT_MAP(CMyActiveXControlCtrl, COleControl)
END_EVENT_MAP()

// 속성 페이지입니다.

// TODO: 필요에 따라 속성 페이지를 추가합니다.  카운트도 이에 따라 증가해야 합니다.
BEGIN_PROPPAGEIDS(CMyActiveXControlCtrl, 1)
	PROPPAGEID(CMyActiveXControlPropPage::guid)
END_PROPPAGEIDS(CMyActiveXControlCtrl)

// 클래스 팩터리와 GUID를 초기화합니다.

IMPLEMENT_OLECREATE_EX(CMyActiveXControlCtrl, "MFCACTIVEXCONTRO.MyActiveXControlCtrl.1",
	0x578e6cd4,0xcde5,0x4f06,0x92,0x84,0x06,0x4a,0xd3,0xfd,0x19,0xd4)

// 형식 라이브러리 ID와 버전입니다.

IMPLEMENT_OLETYPELIB(CMyActiveXControlCtrl, _tlid, _wVerMajor, _wVerMinor)

// 인터페이스 ID입니다.

const IID IID_DMyActiveXControl = {0x21ea13a1,0x0da3,0x4bee,{0x8e,0xce,0x33,0xc2,0xdc,0x74,0xdf,0xbf}};
const IID IID_DMyActiveXControlEvents = {0xa2645bdb,0x031c,0x4bc5,{0xa3,0x7a,0x3e,0x67,0xde,0x9a,0xcc,0x46}};

// 컨트롤 형식 정보입니다.

static const DWORD _dwMyActiveXControlOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMyActiveXControlCtrl, IDS_MYACTIVEXCONTROL, _dwMyActiveXControlOleMisc)

// CMyActiveXControlCtrl::CMyActiveXControlCtrlFactory::UpdateRegistry -
// CMyActiveXControlCtrl에 대한 시스템 레지스트리 항목을 추가하거나 제거합니다.

BOOL CMyActiveXControlCtrl::CMyActiveXControlCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: 컨트롤이 아파트 모델 스레딩 규칙을 준수하는지
	// 확인합니다. 자세한 내용은 MFC Technical Note 64를
	// 참조하십시오. 컨트롤이 아파트 모델 규칙에
	// 맞지 않는 경우 다음에서 여섯 번째 매개 변수를 변경합니다.
	// afxRegApartmentThreading을 0으로 설정합니다.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_MYACTIVEXCONTROL,
			IDB_MYACTIVEXCONTROL,
			afxRegApartmentThreading,
			_dwMyActiveXControlOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CMyActiveXControlCtrl::CMyActiveXControlCtrl - 생성자

CMyActiveXControlCtrl::CMyActiveXControlCtrl()
{
	InitializeIIDs(&IID_DMyActiveXControl, &IID_DMyActiveXControlEvents);
	// TODO: 여기에서 컨트롤의 인스턴스 데이터를 초기화합니다.
}

// CMyActiveXControlCtrl::~CMyActiveXControlCtrl - 소멸자

CMyActiveXControlCtrl::~CMyActiveXControlCtrl()
{
	// TODO: 여기에서 컨트롤의 인스턴스 데이터를 정리합니다.
}

// CMyActiveXControlCtrl::OnDraw - 그리기 함수

void CMyActiveXControlCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO: 다음 코드를 사용자가 직접 작성한 그리기 코드로 바꾸십시오.
	//pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	//pdc->Ellipse(rcBounds);
}

// CMyActiveXControlCtrl::DoPropExchange - 지속성 지원

void CMyActiveXControlCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 지속적인 사용자 지정 속성 모두에 대해 PX_ functions를 호출합니다.
}


// CMyActiveXControlCtrl::OnResetState - 컨트롤을 기본 상태로 다시 설정

void CMyActiveXControlCtrl::OnResetState()
{
	COleControl::OnResetState();  // DoPropExchange에 들어 있는 기본값을 다시 설정합니다.

	// TODO: 여기에서 다른 모든 컨트롤의 상태를 다시 설정합니다.
}


// CMyActiveXControlCtrl::AboutBox - "정보" 대화 상자를 사용자에게 표시

void CMyActiveXControlCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_MYACTIVEXCONTROL);
	dlgAbout.DoModal();
}


// CMyActiveXControlCtrl 메시지 처리기


int CMyActiveXControlCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	RECT rect;
	::GetClientRect(m_hWnd, &rect);

	if (m_MyFormView.Create(NULL, NULL, WS_VISIBLE | WS_CHILD, rect, this, IDD_FORMVIEW))
	{
		OutputDebugString(L"MyFormView Create");
	}
	return 0;
}
