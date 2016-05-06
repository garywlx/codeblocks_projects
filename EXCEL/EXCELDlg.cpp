// EXCELDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EXCEL.h"
#include "EXCELDlg.h"
#include <comdef.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

//定义变量
_Application excelapp;
Workbooks workBooks;
_Workbook workBook;
Worksheets workSheets;
_Worksheet worksheet;
Range excelRange,usedRange;

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
// CEXCELDlg dialog

CEXCELDlg::CEXCELDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEXCELDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEXCELDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEXCELDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEXCELDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEXCELDlg, CDialog)
	//{{AFX_MSG_MAP(CEXCELDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDADDEXCELDATA, OnAddexceldata)
	ON_BN_CLICKED(IDC_Release, OnRelease)
	ON_BN_CLICKED(IDC_BUTTON2, OnSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEXCELDlg message handlers

BOOL CEXCELDlg::OnInitDialog()
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

void CEXCELDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEXCELDlg::OnPaint() 
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
HCURSOR CEXCELDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEXCELDlg::OnAddexceldata()
{
	// TODO: 在此添加控件通知处理程序代码
	
	//打开模板
	if(!excelapp.CreateDispatch(_T("Excel.Application"),NULL)){
		AfxMessageBox(_T("创建Excel服务失败!"));
		return;
	}
	excelapp.SetVisible(FALSE);
	CString filePath;
	filePath+="C:\\报表.xls";
	CFileFind fileFind;
	if(!fileFind.FindFile(filePath)){
		AfxMessageBox("没有找到模板文档，请查找：");
		CFileDialog filedlg(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
			"模板(*xls.)|*.xls||",NULL);
		if(IDOK==filedlg.DoModal()){
			filePath=filedlg.GetPathName();
		}
	}
	//操作模板路径
	COleVariant vOptional((long)DISP_E_PARAMNOTFOUND,VT_ERROR);
	TRY 
	{
		workBooks.AttachDispatch(excelapp.GetWorkbooks(),TRUE);
		workBook.AttachDispatch(workBooks.Add(COleVariant(filePath)),true);
		workSheets=workBook.GetWorksheets();
		worksheet=workSheets.GetItem(_variant_t("首页"));
		excelRange=worksheet.GetCells();
		for(int i=3;i<12;i++){
			char date[20];
			//GetSystemTime(date);
			sprintf(date,"%s%d","A",i);
			//excelRange.SetValue(_variant_t(date),_variant_t("hello"));
		//	excelRange.SetItem(_variant_t((long)i),_variant_t((long)1),_variant_t(date));
			excelRange.SetItem(_variant_t((long)i),_variant_t((long)2),_variant_t("数理统计"));
			excelRange.SetItem(_variant_t((long)i),_variant_t((long)3),_variant_t("李全信"));
			excelRange.SetItem(_variant_t((long)i),_variant_t((long)4),_variant_t("研究1班"));
			//excelRange.set			
		}
		
		

	}
	CATCH (CMemoryException, e)
	{
		AfxMessageBox("");
	}
	END_CATCH
	workBook.Save();
	
}

void CEXCELDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	// TODO: Add your control notification handler code here
	
	CDialog::OnCancel();
}

void CEXCELDlg::OnRelease() 
{
	// TODO: Add your control notification handler code here
	
	//释放对象（相当重要！） 
	excelRange.ReleaseDispatch(); 
	worksheet.ReleaseDispatch(); 
	workSheets.ReleaseDispatch(); 
	workBook.ReleaseDispatch(); 
	workBooks.ReleaseDispatch(); 
	//excelapp一定要释放，否则程序结束后还会有一个Excel进程驻留在内存中，而且程序重复运行的时候会出错
	excelapp.Quit();
	excelapp.ReleaseDispatch(); 
	//退出程序 
	
}

void CEXCELDlg::OnSave() 
{
	// TODO: Add your control notification handler code here
	workBook.Save();

}
