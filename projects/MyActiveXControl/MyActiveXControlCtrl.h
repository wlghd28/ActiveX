#pragma once

// MyActiveXControlCtrl.h : CMyActiveXControlCtrl ActiveX 컨트롤 클래스의 선언입니다.


// CMyActiveXControlCtrl : 구현에 대해서는 MyActiveXControlCtrl.cpp을(를) 참조하세요.
class CMyFormView;
class CMyActiveXControlCtrl : public COleControl
{
	DECLARE_DYNCREATE(CMyActiveXControlCtrl)

// 생성자입니다.
public:
	CMyActiveXControlCtrl();

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
// 구현입니다.
protected:
	~CMyActiveXControlCtrl();

	DECLARE_OLECREATE_EX(CMyActiveXControlCtrl)    // 클래스 팩터리와 GUID입니다.
	DECLARE_OLETYPELIB(CMyActiveXControlCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMyActiveXControlCtrl)     // 속성 페이지 ID입니다.
	DECLARE_OLECTLTYPE(CMyActiveXControlCtrl)		// 형식 이름과 기타 상태입니다.

// 메시지 맵입니다.
	DECLARE_MESSAGE_MAP()

// 디스패치 맵입니다.
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// 이벤트 맵입니다.
	DECLARE_EVENT_MAP()

// 디스패치와 이벤트 ID입니다.

public:
	enum {
	};


	// 멤버변수
	CMyFormView m_MyFormView;
};

