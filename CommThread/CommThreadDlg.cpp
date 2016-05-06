// CommThreadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CommThread.h"
#include "CommThreadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int running=1;
void DoEvent();
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

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
// CCommThreadDlg dialog

CCommThreadDlg::CCommThreadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCommThreadDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCommThreadDlg)
	m_nSendtr = _T("");
	m_nReceiveStr = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCommThreadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCommThreadDlg)
	DDX_Text(pDX, IDC_EDIT_SEND, m_nSendtr);
	DDX_Text(pDX, IDC_EDIT_RECEIVE, m_nReceiveStr);
	DDX_Control(pDX, IDC_MSCOMM1, m_CtrlSend);
	DDX_Control(pDX, IDC_MSCOMM2, m_CtrlReceive);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCommThreadDlg, CDialog)
	//{{AFX_MSG_MAP(CCommThreadDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_BT_SEND, OnSend)
	ON_BN_CLICKED(ID_BUTTON_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCommThreadDlg message handlers

BOOL CCommThreadDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	//初始化发送串口
	m_CtrlSend.SetCommPort(2);
	m_CtrlSend.SetInputMode(1);
	m_CtrlSend.SetSettings("9600,N,8,1");
	m_CtrlSend.SetInBufferSize(512);
	m_CtrlSend.SetOutBufferSize(1024);
	m_CtrlSend.SetRThreshold(4);
	if(!m_CtrlSend.GetPortOpen()){
		m_CtrlSend.SetPortOpen(TRUE);
	}
	if(!m_CtrlSend.GetPortOpen())
		AfxMessageBox("打开端口2失败");
	else{
		m_CtrlSend.SetInputLen(0);
		m_CtrlSend.GetInput();
	}

	//初始化接收串口
	m_CtrlReceive.SetCommPort(3);
	m_CtrlReceive.SetInputMode(1);
	m_CtrlReceive.SetSettings("9600,N,8,1");
	m_CtrlReceive.SetInBufferSize(512);
	m_CtrlReceive.SetOutBufferSize(1024);
	m_CtrlReceive.SetRThreshold(4);
	if(!m_CtrlReceive.GetPortOpen())
		m_CtrlReceive.SetPortOpen(TRUE);
	if(!m_CtrlReceive.GetPortOpen())
		AfxMessageBox("打开端口3失败");
	else{
		m_CtrlReceive.SetInputLen(0);
		m_CtrlReceive.GetInput();
	}
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

void CCommThreadDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCommThreadDlg::OnPaint() 
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
HCURSOR CCommThreadDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BEGIN_EVENTSINK_MAP(CCommThreadDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CCommThreadDlg)
	ON_EVENT(CCommThreadDlg, IDC_MSCOMM1, 1 /* OnComm */, OnOnCommMscomm1, VTS_NONE)
	ON_EVENT(CCommThreadDlg, IDC_MSCOMM2, 1 /* OnComm */, OnOnCommMscomm2, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CCommThreadDlg::OnOnCommMscomm1() 
{
	// TODO: Add your control notification handler code here
	
}

void CCommThreadDlg::OnOnCommMscomm2() 
{
	// TODO: Add your control notification handler code here
	VARIANT varTemp;
	COleSafeArray safearray;
	long len,k;
	BYTE bytes[4];
	CString strTemp;
	if(m_CtrlReceive.GetCommEvent()==2){
		varTemp=m_CtrlReceive.GetInput();
		safearray=varTemp;
		len=safearray.GetOneDimSize();
		
		for(k=0;k<len;k++)
			safearray.GetElement(&k,bytes+k);
		int data=0;
		for(int i=0;i<4;i++){
			data += (bytes[i] & 0XFF) << 8*i;
		}
		DOUBLE da;
		da=data/1000.0;
		strTemp.Format("%0.2f ",da);
		m_nReceiveStr += strTemp;
		UpdateData(FALSE);
	} 
}

void CCommThreadDlg::OnSend() 
{
	// TODO: Add your control notification handler code here
	running=1;
	CString strtmp;
	double data=4.56;
	int idata;
	BYTE btmp[4];
	CByteArray bytes;
	bytes.RemoveAll();
	bytes.SetSize(4);
	while(running){
		idata=data*1000;
		DoEvent();
		for(int i=0;i<4;i++){
			btmp[i] = byte((idata >> 8*i) & 0XFF);
			bytes.SetAt(i,btmp[i]);
		}
		m_CtrlSend.SetOutput(COleVariant(bytes));
		strtmp.Format("%0.2f ",data);
		m_nSendtr += strtmp;
		Sleep(500);
		data+=0.01;
	}
}

void CCommThreadDlg::OnCancel() 
{
	// TODO: Add your control notification handler code here
	::PostMessage(NULL,WM_STOP,0,0);
	m_CtrlSend.SetPortOpen(FALSE);
	m_CtrlReceive.SetPortOpen(FALSE);
	CDialog::OnCancel();
}
void DoEvent(){
	MSG msg;
	bool result;
	while(::PeekMessage(&msg,NULL,0,0,PM_NOREMOVE)){
		result=::GetMessage(&msg,NULL,0,0);

		if(result ==0){
			::PostQuitMessage(msg.wParam);
			break;
		}else if(result == -1){

		}else {
			if(msg.message==WM_STOP)
				running = 0;
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
		}
	}
}