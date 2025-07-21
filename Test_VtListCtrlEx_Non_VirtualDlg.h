
// Test_VtListCtrlEx_Non_VirtualDlg.h: 헤더 파일
//

#pragma once

#include "ResizeCtrl.h"
#include "CListCtrl/CVtListCtrlEx/VtListCtrlEx.h"


// CTestVtListCtrlExNonVirtualDlg 대화 상자
class CTestVtListCtrlExNonVirtualDlg : public CDialogEx
{
// 생성입니다.
public:
	CTestVtListCtrlExNonVirtualDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_VTLISTCTRLEX_NON_VIRTUAL_DIALOG };
#endif

	CResizeCtrl		m_resize;
	void			init_list();
	LRESULT			on_message_CVtListCtrlEx(WPARAM wParam, LPARAM lParam);

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
	CVtListCtrlEx m_list;
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	afx_msg void OnLvnItemChangedList(NMHDR* pNMHDR, LRESULT* pResult);
};
