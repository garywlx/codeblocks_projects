// MultiThreadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MultiThread.h"
#include "MultiThreadDlg.h"
#include "UIThread.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
threadInfo info;
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiThreadDlg dialog

CMultiThreadDlg::CMultiThreadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMultiThreadDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMultiThreadDlg)
	m_nMilliSecond = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMultiThreadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMultiThreadDlg)
	DDX_Control(pDX, IDC_PROGRESS1, m_ctrlProgress);
	DDX_Text(pDX, IDC_MILLISECOND, m_nMilliSecond);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMultiThreadDlg, CDialog)
	//{{AFX_MSG_MAP(CMultiThreadDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDSTART, OnStart)
	ON_BN_CLICKED(IDCREATE, OnCreate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiThreadDlg message handlers

BOOL CMultiThreadDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_ctrlProgress.SetRange(0,99);
	m_nMilliSecond=10;
	UpdateData(false);

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMultiThreadDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMultiThreadDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMultiThreadDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMultiThreadDlg::OnStart() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	info.nMilliSecond=m_nMilliSecond;
	info.pctrlProgress=&m_ctrlProgress;

	pThread=AfxBeginThread(ThreadFunc,&info);
}
UINT ThreadFunc(LPVOID lpParam){
	threadInfo* pInfo=(threadInfo*)lpParam;
	for(int i=0;i<100;i++){
		int nTemp=pInfo->nMilliSecond;
		pInfo->pctrlProgress->SetPos(i);
		Sleep(nTemp);
	}
	return 0;
}

void CMultiThreadDlg::OnCreate() 
{
	// TODO: Add your control notification handler code here
	CUIThread * pThread=new CUIThread();
	pThread->CreateThread();
}
