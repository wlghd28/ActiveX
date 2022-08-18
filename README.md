# ActiveX
ActiveX 관련 내용입니다.

# 개념
ActiveX는 마이크로소프트가 전략적 객체지향 프로그래밍 기술 및 도구모음에 대해 붙인 이름이다. 그 주요 기술은 COM이다. 디렉토리 및 기타 부가적인 지원과 함께 네트웍 내에서 사용되던 COM은 DCOM이 된다. ActiveX 환경에서 운영되는 프로그램을 개발할 때 생성하게 되는 중요한 것이 컴포넌트인데, 이것은 ActiveX 네트웍의 어느 부분에서나 실행되기에 스스로 충분한 하나의 프로그램이라 할 수 있다. 이 컴포넌트를 ActiveX control 이라 부른다. ActiveX는 썬 마이크로시스템즈의 자바 기술에 대항하기 위해 마이크로소프트가 내놓은 기술이다. 그러므로 ActiveX control은 대체로 자바 애플릿과 동등한 위치에 있다고 할 수 있다.

윈도우 운영체계가 설치된 PC에서 파일의 확장자에 "OCX"라고 붙은 많은 파일들이 발견되는데, OCX란 "Object Linking and Embedding control"의 약자이다. 개체연결 및 삽입 (OLE ; Object Linking and Embedding)은 윈도우 데스크탑과 같은 복합문서를 지원하기 위한 마이크로소프트의 프로그램 기술이었으나, 이제 COM이 OLE를 커다란 개념의 일부로 흡수하였다. 이제 마이크로소프트는 컴포넌트 객체를 위해 OCX 대신에 "ActiveX control"이라는 용어를 사용한다.

컴포넌트의 주요 장점 중의 하나는, 많은 응용 프로그램에서 재사용될 수 있다는 것이다. ActiveX control은 C++, 비주얼베이직, 파워빌더 또는 VBScript와 같은 스크립트 도구 등을 포함, 여러가지 언어나 개발도구를 사용해서 만들 수 있다.

# 실습 프로젝트 참고 링크
[참고링크](https://soultomind.tistory.com/189)

# MFC ActiveX 프로젝트 클래스 설명
1. xxxxxxxxApp
    - 최상단 앱 클래스(일반 MFC와 동일 개념)

2. xxxxxxxxCtrl
    - 주 처리 클래스(컨트롤의 주체)

3. xxxxxxxxPropPage
    - 속성창에서 보여줄 페이지

4. xxxxxxxx.idl
    - 함수, 변수, 이벤트 연결


# MFC ActiveX Control 생성 과정
1. 프로젝트 설정에서 MFC 정적 라이브러리 활용을 설정합니다.
2. 리소스 파일에 xxxxxxxxCtrl 클래스에서 부를 폼 클래스를 생성(ex)CMyFormView)합니다.
3. CMyFormView 클래스에서 Create, PostNcDestroy 함수를 재정의 합니다.
4. 재정의 후 추가한 PostNcDestory 함수에서 CFormView::PostNcDestroy() 호출 부분을 주석합니다.
5. 다음은 xxxxxxxxApp.h 파일에서 MyFormView.h 파일을 Include 후에 xxxxxxxxCtrl 클래스에서 사용 할 수 있게 CMyFormView 클래스를 멤버 변수로 선언합니다.
6. xxxxxxxxCtrl 클래스에서 클래스마법사를 통해 WM_CREATE 메시지를 추가하고 OnCreate 함수를 재정의 합니다.
7. xxxxxxxxCtrl 클래스의 OnDraw 함수에서 그리는 코드를 주석 후 OnCreate 함수에서 CMyFormView 를 추가합니다.


# MFC ActiveX Control 연동 과정
1. MFC ActiveX 프로젝트를 통해 ActiveX Control(xxxxxxxx.ocx)을 생성합니다. **(64bit, 32bit 버전으로 둘다 컴파일 해서 생성할 것)**
2. 생성한 ocx 파일을 64bit 파일일 경우 C:\Windows\System32 경로에 파일을 복사하고, 32bit 파일의 경우 C:\Windows\SysWOW64 경로에 파일을 복사합니다.
3. cmd 명령창을 관리자권한으로 실행시킨 후 64bit인 경우 cd C:\Windows\System32, 32bit인 경우 cd C:\Windows\SysWOW64 명령을 칩니다.
4. 64bit, 32bit 각각 경로에서 regsvr32 xxxxxxxx.ocx 명령을 쳐서 ocx를 등록 해줍니다. (ocx 등록 해제는 regsvr32 -u xxxxxxxx.ocx 입니다.)
5. ActiveX Control을 끌어다 쓸 MFC 앱의 다이얼로그 리소스 파일에서 오른쪽 마우스 클릭 후 ActiveX 삽입을 누릅니다.
6. 추가된 ActiveX Control을 클릭합니다.
