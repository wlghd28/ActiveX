﻿#pragma once

// MyActiveXControlPropPage.h : CMyActiveXControlPropPage 속성 페이지 클래스의 선언입니다.


// CMyActiveXControlPropPage : 구현에 대해서는 MyActiveXControlPropPage.cpp을(를) 참조하세요.

class CMyActiveXControlPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMyActiveXControlPropPage)
	DECLARE_OLECREATE_EX(CMyActiveXControlPropPage)

// 생성자입니다.
public:
	CMyActiveXControlPropPage();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_PROPPAGE_MYACTIVEXCONTROL };

// 구현입니다.
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 메시지 맵입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

