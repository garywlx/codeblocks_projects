// FileManipulateDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FileManipulate.h"
#include "FileManipulateDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CFileManipulateDlg dialog

CFileManipulateDlg::CFileManipulateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileManipulateDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileManipulateDlg)
	m_szSrcFile = _T("");
	m_szDstFile = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileManipulateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileManipulateDlg)
	DDX_Text(pDX, IDC_SRCFILE, m_szSrcFile);
	DDX_Text(pDX, IDC_DSTFILE, m_szDstFile);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFileManipulateDlg, CDialog)
	//{{AFX_MSG_MAP(CFileManipulateDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_COPY, OnCopy)
	ON_BN_CLICKED(IDC_MOVE, OnMove)
	ON_BN_CLICKED(IDC_OPENSRC, OnOpensrc)
	ON_BN_CLICKED(IDC_OPENDST, OnOpendst)
	ON_BN_CLICKED(IDC_DELETE, OnDel)
	ON_BN_CLICKED(IDC_CANCLE, OnCancle)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileManipulateDlg message handlers

BOOL CFileManipulateDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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

void CFileManipulateDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFileManipulateDlg::OnPaint() 
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
HCURSOR CFileManipulateDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFileManipulateDlg::OnCopy() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(MessageBox("是否将原始文件复制到目标文件？","提示",MB_OKCANCEL)==IDOK){
		CFile *pStrFile=NULL;
		CFile *pDstFile=NULL;
		TRY
		{
			pStrFile=new CFile(m_szSrcFile,CFile::modeRead);//原始文件
			pDstFile=new CFile(m_szDstFile,CFile::modeWrite|CFile::modeCreate);//目标文件
			int nRead;
			char szBuffer[1024];
			while(nRead=pStrFile->Read(szBuffer,sizeof(szBuffer))){
				pDstFile->Write(szBuffer,nRead);
			}
			pStrFile->Close();
			pDstFile->Close();
			delete pStrFile;
			delete pDstFile;
			MessageBox("文件复制成功！","提示",MB_OK);
		}
		CATCH (CFileException, e)
		{
			MessageBox("文件复制失败！","提示",MB_OK);
			if(pStrFile!=NULL){
				pStrFile->Abort();
				delete pStrFile;
			}
			if(pDstFile!=NULL){
				delete pDstFile;
			}
		}
		END_CATCH
	}
}

void CFileManipulateDlg::OnMove() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(MessageBox("是否将源文件移动到目标文件？","提示",MB_OKCANCEL)==IDOK){
		CFile *pStrFile=NULL;
		CFile *pDstFile=NULL;
		TRY
		{
			pStrFile=new CFile(m_szSrcFile,CFile::modeRead);//原始文件
			pDstFile=new CFile(m_szDstFile,CFile::modeWrite|CFile::modeCreate);//目标文件
			int nRead;
			char szBuffer[1024];
			while(nRead=pStrFile->Read(szBuffer,sizeof(szBuffer))){
				pDstFile->Write(szBuffer,nRead);
			}
			pStrFile->Close();
			pDstFile->Close();
			delete pStrFile;
			delete pDstFile;
			CFile::Remove(m_szSrcFile);
			MessageBox("文件移动成功！","提示",MB_OK);
		}
		CATCH (CFileException, e)
		{
			MessageBox("文件移动失败！","提示",MB_OK);
			if(pStrFile!=NULL){
				pStrFile->Abort();
				delete pStrFile;
			}
			if(pDstFile!=NULL){
				delete pDstFile;
			}
		}
		END_CATCH
	}
}

void CFileManipulateDlg::OnOpensrc() 
{
	// TODO: Add your control notification handler code here
	CString   FilePathName;//文件名参数定义
    CFileDialog  Dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"TXT Files(*.txt)|*.txt|All Files(*.*)|*.*");
	//打开文件
    if(Dlg.DoModal() == IDOK)//是否打开成功
    {
        FilePathName =  Dlg.GetPathName();//取得文件路径及文件名
        SetDlgItemText(IDC_SRCFILE,FilePathName);//在一个地址为IDC_OutPutFile的editbox中显示文件名
    }
    else//打开失败处理
    {
        //打开失败处理
        //MessageBox("打开失败",NULL,MB_OK);
    }
}

void CFileManipulateDlg::OnOpendst() 
{
	// TODO: Add your control notification handler code here
	CString FilePathName;//文件名参数定义
    CFileDialog Dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"TXT Files(*.txt)|*.txt|All Files(*.*)|*.*");
	//打开文件
    if(Dlg.DoModal() == IDOK)//是否打开成功
    {
        FilePathName =  Dlg.GetPathName();//取得文件路径及文件名
        SetDlgItemText(IDC_DSTFILE,FilePathName);//在一个地址为IDC_OutPutFile的editbox中显示文件名
    }
    else//打开失败处理
    {
        //打开失败处理
        //MessageBox("打开失败",NULL,MB_OK);
    }
}

void CFileManipulateDlg::OnDel() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(MessageBox("是否删除原始文件？","提示",MB_OKCANCEL)==IDOK){
		TRY 
		{
			CFile::Remove(m_szSrcFile);
			MessageBox("文件删除成功！","提示",MB_OK);
		}
		CATCH (CFileException, e)
		{
			MessageBox("文件删除失败！","提示",MB_OK);
		}
		END_CATCH
	}
}

void CFileManipulateDlg::OnCancle() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}
