
// ComboBoxCtrlDlg.h: 헤더 파일
//

#pragma once


// CComboBoxCtrlDlg 대화 상자
class CComboBoxCtrlDlg : public CDialogEx
{
// 생성입니다.
public:
	CComboBoxCtrlDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COMBOBOXCTRL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:


	bool m_bComboFocus;

	void InitComboBox(CComboBox* pCombo);



	afx_msg void OnCbnDblclkCombo4();
	afx_msg void OnCbnDropdownCombo4();
	afx_msg void OnCbnEditchangeCombo4();
	afx_msg void OnCbnKillfocusCombo4();
	afx_msg void OnCbnSelchangeCombo4();
	afx_msg void OnCbnSelendcancelCombo4();
	afx_msg void OnCbnSetfocusCombo4();
	afx_msg void OnBnClickedButton1();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
