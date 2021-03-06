
// ComboBoxCtrlDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "ComboBoxCtrl.h"
#include "ComboBoxCtrlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CComboBoxCtrlDlg 대화 상자



CComboBoxCtrlDlg::CComboBoxCtrlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COMBOBOXCTRL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CComboBoxCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CComboBoxCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_DBLCLK(IDC_COMBO4, &CComboBoxCtrlDlg::OnCbnDblclkCombo4)
	ON_CBN_DROPDOWN(IDC_COMBO4, &CComboBoxCtrlDlg::OnCbnDropdownCombo4)
	ON_CBN_EDITCHANGE(IDC_COMBO4, &CComboBoxCtrlDlg::OnCbnEditchangeCombo4)
	ON_CBN_KILLFOCUS(IDC_COMBO4, &CComboBoxCtrlDlg::OnCbnKillfocusCombo4)
	ON_CBN_SELCHANGE(IDC_COMBO4, &CComboBoxCtrlDlg::OnCbnSelchangeCombo4)
	ON_CBN_SELENDCANCEL(IDC_COMBO4, &CComboBoxCtrlDlg::OnCbnSelendcancelCombo4)
	ON_CBN_SETFOCUS(IDC_COMBO4, &CComboBoxCtrlDlg::OnCbnSetfocusCombo4)
	ON_BN_CLICKED(IDC_BUTTON1, &CComboBoxCtrlDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CComboBoxCtrlDlg 메시지 처리기

BOOL CComboBoxCtrlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	CWnd* pCombo = GetDlgItem(IDC_COMBO1); // id 값을 받고 그 값을 combo 박스 주소를 저장 그 이후 이 값을 enable 시켜줘
										   //pCombo->EnableWindow(false);

	//General
	CComboBox* pComboBox = (CComboBox*)pCombo;
	InitComboBox(pComboBox);
	pComboBox->ResetContent();
	/*
	CString str;
	pComboBox->GetLBText(0, str);
	pComboBox->SetWindowText(str);
	*/


	//scale
	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO2);
	InitComboBox(pComboBox);
	
	CString str;
	pComboBox->GetLBText(0, str);
	pComboBox->SetWindowText(str); //edit 기능이 있을시 사용 가능
	
	
	
	//drop List(edit 가능하지 않음)
	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO3);
	InitComboBox(pComboBox);
	pComboBox->SetCurSel(0);



	//input
	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO4);
	


	//
	m_bComboFocus = false;





	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CComboBoxCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CComboBoxCtrlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CComboBoxCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CComboBoxCtrlDlg::InitComboBox(CComboBox * pCombo)
{
	pCombo->AddString("C++");
	pCombo->AddString("java");
	pCombo->AddString("jsp");
	pCombo->AddString("api");
	pCombo->AddString("mfc");
	pCombo->AddString("databse");
	pCombo->AddString("network");
	pCombo->AddString("directx");

}



void CComboBoxCtrlDlg::OnCbnDblclkCombo4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CComboBoxCtrlDlg::OnCbnDropdownCombo4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CComboBoxCtrlDlg::OnCbnEditchangeCombo4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CComboBoxCtrlDlg::OnCbnKillfocusCombo4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bComboFocus = false;
}


void CComboBoxCtrlDlg::OnCbnSelchangeCombo4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CComboBoxCtrlDlg::OnCbnSelendcancelCombo4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CComboBoxCtrlDlg::OnCbnSetfocusCombo4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bComboFocus = true;
}


void CComboBoxCtrlDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;

	CComboBox* pComboBox;

	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO4);

	pComboBox->GetWindowText(str);


	pComboBox->AddString(str);



}


BOOL CComboBoxCtrlDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->message == WM_KEYDOWN) //WM 동작들
	{
		TRACE("message : %d\n", pMsg->message);

		//pMsg->lParam;// 마우스의 위치 및 이벤트 등에 값들이 할당함 (shift 이용한 입력)

		if (pMsg->wParam == VK_ESCAPE || pMsg->wParam == VK_RETURN) //기타 값들
		{

			if (m_bComboFocus)
			{
				CComboBox* pCom = (CComboBox*)GetDlgItem(IDC_COMBO4);
				CString  str;


				pCom->GetWindowText(str);


				pCom->AddString(str);



			}
			return TRUE;


		}



	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
