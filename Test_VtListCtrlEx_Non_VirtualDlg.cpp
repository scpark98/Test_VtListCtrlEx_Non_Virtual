
// Test_VtListCtrlEx_Non_VirtualDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Test_VtListCtrlEx_Non_Virtual.h"
#include "Test_VtListCtrlEx_Non_VirtualDlg.h"

#include "Functions.h"

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


// CTestVtListCtrlExNonVirtualDlg 대화 상자



CTestVtListCtrlExNonVirtualDlg::CTestVtListCtrlExNonVirtualDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TEST_VTLISTCTRLEX_NON_VIRTUAL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestVtListCtrlExNonVirtualDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_list);
}

BEGIN_MESSAGE_MAP(CTestVtListCtrlExNonVirtualDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_WINDOWPOSCHANGED()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST, &CTestVtListCtrlExNonVirtualDlg::OnLvnItemChangedList)
	ON_REGISTERED_MESSAGE(Message_CVtListCtrlEx, &CTestVtListCtrlExNonVirtualDlg::on_message_CVtListCtrlEx)
END_MESSAGE_MAP()


// CTestVtListCtrlExNonVirtualDlg 메시지 처리기

BOOL CTestVtListCtrlExNonVirtualDlg::OnInitDialog()
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
	m_resize.Create(this);
	m_resize.Add(IDC_LIST, 0, 0, 100, 100);
	m_resize.Add(IDOK, 100, 100, 0, 0);
	m_resize.Add(IDCANCEL, 100, 100, 0, 0);

	init_list();

	RestoreWindowPosition(&theApp, this);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CTestVtListCtrlExNonVirtualDlg::init_list()
{
	//m_list.set_use_virtual_list(false);
	m_list.SetExtendedStyle(LVS_EX_CHECKBOXES);// | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	//m_list.InsertColumn(0, _T("기능/옵션"), LVCFMT_LEFT, 100);
	//m_list.InsertItem(0, _T("마우스/키보드 제어"));

	m_list.set_line_height(24);

	m_list.set_headings(_T("기능/옵션,100;설명,250;옵션 ID,150;옵션 Value,100"));
	m_list.insert_item(-1, -1, _T("마우스/키보드 제어"), _T("마우스 / 키보드 제어를 사용합니다."), _T("_RCFunctionRight_CONTROL"), _T("0x00000001"));
	m_list.insert_item(-1, -1, _T("마우스/키보드 제어"), _T("마우스 / 키보드 제어를 사용합니다."), _T("_RCFunctionRight_CONTROL"), _T("0x00000001"));
	m_list.insert_item(-1, -1, _T("마우스/키보드 제어"), _T("마우스 / 키보드 제어를 사용합니다."), _T("_RCFunctionRight_CONTROL"), _T("0x00000001"));
}

void CTestVtListCtrlExNonVirtualDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CTestVtListCtrlExNonVirtualDlg::OnPaint()
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
HCURSOR CTestVtListCtrlExNonVirtualDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTestVtListCtrlExNonVirtualDlg::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	SaveWindowPosition(&theApp, this);
}

void CTestVtListCtrlExNonVirtualDlg::OnLvnItemChangedList(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	//체크박스 상태가 변경된 경우에만 처리하기 위해.
	UINT old_check = pNMLV->uOldState & LVIS_STATEIMAGEMASK;
	UINT new_check = pNMLV->uNewState & LVIS_STATEIMAGEMASK;

	TRACE(_T("OnLvnItemChangedList: item = %d, sub = %d, old = %d, new = %d, old_check = %d, new_check = %d\n"),
								pNMLV->iItem, pNMLV->iSubItem, pNMLV->uOldState, pNMLV->uNewState, old_check, new_check);
	if (pNMLV->uChanged & LVIF_STATE) // item state has been changed
	{
		switch (pNMLV->uNewState & LVIS_STATEIMAGEMASK)
		{
		case 0x2000: // new state: checked
			TRACE1("\n Item %d has been checked", pNMLV->iItem);
			break;
		case 0x1000: // new state: unchecked
			TRACE1("\n Item %d has been unchecked", pNMLV->iItem);
			break;
		}
	}

	*pResult = 0;
}

LRESULT CTestVtListCtrlExNonVirtualDlg::on_message_CVtListCtrlEx(WPARAM wParam, LPARAM lParam)
{
	auto msg = (CVtListCtrlExMessage*)wParam;
	if (msg->message == CVtListCtrlEx::message_checked_item)
	{
		int item = (int)lParam;
		TRACE(_T("on_message_CVtListCtrlEx: message_checked_item, item = %d\n"), item);

		std::deque<int> dq;
		m_list.get_checked_items(&dq);
		TRACE(_T("checked list = %s\n"), get_list_str(dq));
	}

	std::deque<CString> dq = { _T("test1"), _T("test2"), _T("test3") };
	TRACE(_T("checked list = %s\n"), get_list_str(dq));

	return 0;
}