// pc_pcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "pc_pc.h"
#include "EXCEL.h"
#include "pc_pcDlg.h"
#include <comdef.h>
#include <AFXMT.H>
#include <SSTREAM>
#include <STRING>
#include <IOSTREAM>
#include <CMATH>
#ifdef _DEBUG
#define new DEBUG_NEW
using namespace std;
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//#define int ISRUNNING 1
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
CCriticalSection critical_section;
SendThreadInfo sInfo;
ReceiveThreadInfo rInfo;
int isRunning=1;
CString path;
void DoEvents();
int DetectPort(CStringArray* PortList);
void initSerialPort();
int i=3;

//定义变量
_Application excelapp;
Workbooks workbooks;
_Workbook workbook;
Worksheets worksheets;
_Worksheet worksheet;
Range excelrange;

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
// CPc_pcDlg dialog

CPc_pcDlg::CPc_pcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPc_pcDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPc_pcDlg)
	m_strReceive = _T("");
	m_strSend = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPc_pcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPc_pcDlg)
	DDX_Control(pDX, IDC_STOP_BIT2, m_stop_bit2);
	DDX_Control(pDX, IDC_STOP_BIT1, m_stop_bit1);
	DDX_Control(pDX, IDC_PARITY_BIT2, m_parity_bit2);
	DDX_Control(pDX, IDC_PARITY_BIT1, m_parity_bit1);
	DDX_Control(pDX, IDC_DATA_BIT2, m_data_bit2);
	DDX_Control(pDX, IDC_DATA_BIT1, m_data_bit1);
	DDX_Control(pDX, IDC_BUFFER_SIZE2, m_buffer_size2);
	DDX_Control(pDX, IDC_BUFFER_SIZE1, m_buffer_size1);
	DDX_Control(pDX, IDC_BAUD_RATE2, m_baud_rate2);
	DDX_Control(pDX, IDC_PORT2, m_port2);
	DDX_Control(pDX, IDC_PORT1, m_port1);
	DDX_Control(pDX, IDC_BAUD_RATE1, m_baud_rate1);
	DDX_Control(pDX, IDC_MSCOMM1, m_ctrlComm);
	DDX_Text(pDX, IDC_receive, m_strReceive);
	DDX_Text(pDX, IDC_send, m_strSend);
	DDX_Control(pDX, IDC_MSCOMM2, m_ctrlComm2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPc_pcDlg, CDialog)
	//{{AFX_MSG_MAP(CPc_pcDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_BN_CLICKED(ID_SAVE_SETTING, OnSaveSetting)
	ON_MESSAGE(WM_MYUPDATEDATA,OnUpdateSendData)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPc_pcDlg message handlers

BOOL CPc_pcDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	sThread = AfxBeginThread(sendThreadFunc,this,THREAD_PRIORITY_NORMAL,0,0,NULL);
	sThread->SuspendThread();
	rThread = AfxBeginThread(receiveThreadFunc,this,THREAD_PRIORITY_NORMAL,0,0,NULL);
	rThread->SuspendThread();

	//CStringArray PortList;
	CStringArray PortList;
	PortList.Add(NULL);	
	int countNum=DetectPort(&PortList);
	for(int i=0;i<countNum+1;i++){//有个需要解决的问题
		CString port=PortList.GetAt(i);
		m_port1.AddString(_T(port));
		m_port2.AddString(_T(port));
	}
	m_port1.SetCurSel(0);
	m_port2.SetCurSel(0);

	m_baud_rate1.SetCurSel(0);
	m_baud_rate2.SetCurSel(0);

	m_parity_bit1.SetCurSel(0);
	m_parity_bit2.SetCurSel(0);

	m_data_bit1.SetCurSel(0);
	m_data_bit2.SetCurSel(0);
	
	m_stop_bit1.SetCurSel(0);
	m_stop_bit2.SetCurSel(0);

	m_buffer_size1.SetCurSel(0);
	m_buffer_size2.SetCurSel(0);	
	
	((CButton*)GetDlgItem(IDOK))->EnableWindow(FALSE);
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
LRESULT CPc_pcDlg::OnUpdateSendData(WPARAM wParam,LPARAM lParam){
	CString *str=(CString *)wParam;
	m_strSend+=*str;
	UpdateData(FALSE);
	return 1;
}
	/************************************************************************/
	/* 串口检测                                                                     */
	/************************************************************************/
int DetectPort(CStringArray *PortList){
	CString strTemp;
	HANDLE hCom;
	int count=0;
	for(int i=0;i<255;i++){
		strTemp.Format("COM%d",i+1);
		hCom=CreateFile(strTemp,GENERIC_READ | GENERIC_WRITE,0,NULL,OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL|FILE_FLAG_OVERLAPPED, NULL);
		if(INVALID_HANDLE_VALUE==hCom) continue;
		else{
			PortList->Add(strTemp);
			CloseHandle(hCom);
			count++;
		}
		
	}
	return count;
}
/************************************************************************/
/* 初始化串口                                                                     */
/************************************************************************/
void initSerialPort(){
	
}
void CPc_pcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPc_pcDlg::OnPaint() 
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
HCURSOR CPc_pcDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
// click send button
void CPc_pcDlg::OnOK() 
{
	// TODO: Add extra validation here
		
	//UpdateData(TRUE);
	
	
	//isRunning = 1;
	sThread->ResumeThread();
	rThread->ResumeThread();
	
	//((CButton*)GetDlgItem())->EnableWindow(TRUE);
	
	 
}
//click
void CPc_pcDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	if(m_ctrlComm.GetPortOpen()||m_ctrlComm2.GetPortOpen()){
		m_ctrlComm.SetPortOpen(FALSE);
		m_ctrlComm2.SetPortOpen(FALSE);
	}
	
	//excelapp.Quit();
	
	rThread->PostThreadMessage(WM_SAVE,0,0);
	CDialog::OnCancel();
}

void CPc_pcDlg::OnStop() 
{
	// TODO: Add your control notification handler code here
	 //sThread->PostThreadMessage(WM_STOP,NULL,NULL);
	 //isRunning = 0;
	sThread->SuspendThread();
}


BEGIN_EVENTSINK_MAP(CPc_pcDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CPc_pcDlg)
	ON_EVENT(CPc_pcDlg, IDC_MSCOMM1, 1 /* OnComm */, OnOnCommMscomm1, VTS_NONE)
	ON_EVENT(CPc_pcDlg, IDC_MSCOMM2, 1 /* OnComm */, OnOnCommMscomm2, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CPc_pcDlg::OnOnCommMscomm1() 
{
	// TODO: Add your control notification handler code here
	
}
void CPc_pcDlg::OnOnCommMscomm2()
{
	// TODO: Add your control notification handler code here
	VARIANT variant_inp;
	COleSafeArray safearray_inp;
	LONG len,k;
	BYTE rxdata[4];
	CString *strtemp = new CString;
	
	if(m_ctrlComm2.GetCommEvent()==2){
		UpdateData(TRUE);
		variant_inp=m_ctrlComm2.GetInput();
		safearray_inp=variant_inp;
		len=safearray_inp.GetOneDimSize();
		for(k=0;k<len;k++){
			safearray_inp.GetElement(&k,rxdata+k);
		}
		int iOutcome = 0;		
		byte bLoop;
		for (int i = 0; i < 4; i++){
			bLoop = rxdata[i];
			iOutcome += (bLoop & 0XFF) << (8*i);
		}
		double result=iOutcome/1000.0;
		(*strtemp).Format("%0.2f ",result);
		//critical_section.Lock();
		rThread->PostThreadMessage(WM_START,(WPARAM)strtemp,0);
		//critical_section.Unlock();
		m_strReceive += *strtemp;
		
		UpdateData(FALSE);
	}
	
}
/************************************************************************/
/* 发送线程                                                                     */
/************************************************************************/
UINT sendThreadFunc(LPVOID lpParam){
	//SendThreadInfo* sInfo=(SendThreadInfo*)lpParam;
	CPc_pcDlg* p = (CPc_pcDlg*)lpParam;
	double tmp=2.30;
	while(TRUE){
		DoEvents();
		CString *cstr=new CString;		
		int itemp=tmp*1000;
		BYTE bytes[4];
		CByteArray array;
		array.RemoveAll();
		array.SetSize(4);
		for(int i=0;i<4;i++){
			bytes[i] = (byte)((itemp >> (8*i)) & 0XFF);
			array.SetAt(i,bytes[i]);		
		}
		p->m_ctrlComm.SetOutput(COleVariant(array));
		(*cstr).Format("%0.2f ",tmp);
		//p->m_strSend+=cstr;
		//p->UpdateData(FALSE);//坚决不能在子线程调用updatedata	
		p->SendMessage(WM_MYUPDATEDATA,(WPARAM)cstr,0);
		Sleep(1000);
		tmp+=0.01;
		
	}
	return 0;
}
/************************************************************************/
/* 接受线程:写excel表格                                                                     */
/************************************************************************/
UINT receiveThreadFunc(LPVOID lpParam){
	CPc_pcDlg* p = (CPc_pcDlg*)lpParam;
	COleVariant covOptional((long)DISP_E_PARAMNOTFOUND,VT_ERROR);
	if (::CoInitialize( NULL ) == E_INVALIDARG) 
	{ 
		AfxMessageBox(_T("初始化Com失败!"));
		return 0;
	} 
	if(!excelapp.CreateDispatch(_T("Excel.Application"),NULL)){
		AfxMessageBox(_T("创建Excel服务失败!"));
		return 0;
	}
	excelapp.SetVisible(FALSE);
	path="C:\\报表.xls";
	CFileFind fileFinder;
	if(!fileFinder.FindFile(path)){
		AfxMessageBox("没有找到模板文档，请自行查找：");
		CFileDialog filedlg(TRUE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
						" 模板(*.xls)|*.xls||",NULL);
		if(IDOK==filedlg.DoModal()){
			path=filedlg.GetPathName();
		}
	}
	TRY 
	{
		workbooks=excelapp.GetWorkbooks();
		workbook=workbooks.Open(path,covOptional, covOptional, covOptional,covOptional, 
								covOptional, covOptional, covOptional,covOptional,covOptional, 
								covOptional, covOptional, covOptional,covOptional,covOptional);
		worksheets=workbook.GetWorksheets();
		worksheet=worksheets.GetItem(_variant_t("首页"));
		excelrange=worksheet.GetCells();
	}
	CATCH (CMemoryException, e)
	{
		AfxMessageBox("操作失败！");
		return 0;
	}
	END_CATCH
	
	while(true){
		MSG msg;
		BOOL result;
		//critical_section.Lock();
		while(::PeekMessage(&msg,NULL,0,0,PM_NOREMOVE)){
			result=::GetMessage(&msg,NULL,0,0);	
			
			if(result==0){
				::PostQuitMessage(msg.lParam);
				break;
			}else if(result ==-1){
				
			}else{
				if(msg.message==WM_START){
					CString* str = (CString*)msg.wParam;					
					//操作模板路径					
					TRY 
					{
						//char date[20];
						//GetSystemTime(date);
						//sprintf(date,"%s%d","A",i);
						excelrange.SetItem(_variant_t((long)i++),_variant_t((long)2),_variant_t(*str));				
					}
					CATCH (CMemoryException, e)
					{
						AfxMessageBox("");
						return 0;
					}
					END_CATCH
				}else if(msg.message==WM_SAVE){
					COleVariant covTrue((short)TRUE),covFalse((short)FALSE);
					workbook.Close(covTrue,COleVariant("D:\\模板输出.xls"),covOptional);
					//excelapp.ReleaseDispatch();
					excelapp.Quit();
					CoUninitialize();
				}				
				::TranslateMessage(&msg);
				:: DispatchMessage(&msg);
			}
		}
	}
	
	return 0;
}

void DoEvents()
{
    MSG msg;
    BOOL result;
	
    while ( ::PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE ) )
    {
		
        result = ::GetMessage(&msg, NULL, 0, 0);
        if (result == 0) // WM_QUIT
        {                
            ::PostQuitMessage(msg.wParam);
            break;
        }
        else if (result == -1)
        {
			// Handle errors/exit application, etc.
        }
        else 
        {
			isRunning=0;
            ::TranslateMessage(&msg);
            :: DispatchMessage(&msg);
        }
    }
}
/************************************************************************/
/* 保存设置                                                                     */
/************************************************************************/
void CPc_pcDlg::OnSaveSetting() 
{
	// TODO: Add your control notification handler code here
	if(m_ctrlComm.GetPortOpen()||m_ctrlComm2.GetPortOpen()){
		m_ctrlComm.SetPortOpen(FALSE);
		m_ctrlComm2.SetPortOpen(FALSE);
	}
	CString portName1,portName2,buffer1,buffer2,databit1,databit2,stopbit1,stopbit2,paritybit1,paritybit2,baud1,baud2;
	m_port1.GetLBText(m_port1.GetCurSel(),portName1);
	m_port2.GetLBText(m_port2.GetCurSel(),portName2);
	//获取串口号
	int port1=0,port2=0,temp;
	for(int i=portName1.GetLength()-1;i>=3;i--){
		char a=portName1.GetAt(i)-'0';
		temp =(int)a;
		temp=temp*((int)pow(10,i-3));
	}
	port1=temp;
	for(i=portName2.GetLength()-1;i>=3;i--){
		char b=portName2.GetAt(i)-'0';
		temp=b;
		temp=temp*((int)pow(10,i-3));
	}
	port2=temp;
	
	if(port1==0||port2==0){
		AfxMessageBox("请先选择串口！");
		return ;
	}
	//获取属性值
	m_baud_rate1.GetLBText(m_baud_rate1.GetCurSel(),baud1);
	m_baud_rate2.GetLBText(m_baud_rate2.GetCurSel(),baud2);

	m_parity_bit1.GetLBText(m_parity_bit1.GetCurSel(),paritybit1);
	m_parity_bit2.GetLBText(m_parity_bit2.GetCurSel(),paritybit2);

	m_data_bit1.GetLBText(m_data_bit1.GetCurSel(),databit1);
	m_data_bit2.GetLBText(m_data_bit2.GetCurSel(),databit2);
	
	m_stop_bit1.GetLBText(m_stop_bit1.GetCurSel(),stopbit1);
	m_stop_bit2.GetLBText(m_stop_bit2.GetCurSel(),stopbit2);
	
	m_buffer_size1.GetLBText(m_buffer_size1.GetCurSel(),buffer1);
	m_buffer_size2.GetLBText(m_buffer_size2.GetCurSel(),buffer2);
	
	CString setting1,setting2;
	
	setting1=baud1 + "," + paritybit1.GetAt(0) + "," + databit1 + "," + stopbit1;
	setting2=baud2 + "," + paritybit2.GetAt(0) + "," + databit2 + "," + stopbit2;
	
	m_ctrlComm.SetCommPort(port1);
	m_ctrlComm.SetInputMode(1);
	m_ctrlComm.SetInBufferSize((short)atoi(buffer1));
	m_ctrlComm.SetOutBufferSize((short)atoi(buffer1));
	m_ctrlComm.SetSettings(setting1);	
	m_ctrlComm.SetPortOpen(TRUE);         //打开端口
	
	if(!m_ctrlComm.GetPortOpen()){
		AfxMessageBox("打开端口2失败！");
		return ;
	}else{
		m_ctrlComm.SetRThreshold(4);
		m_ctrlComm.SetInputLen(0);
		m_ctrlComm.GetInput();
	}
	
	m_ctrlComm2.SetCommPort(port2);
	m_ctrlComm2.SetInputMode(1);
	m_ctrlComm2.SetInBufferSize((short)atoi(buffer2));
	m_ctrlComm2.SetSettings(setting2);	
	m_ctrlComm2.SetPortOpen(TRUE);         //打开端口
	
	if(!m_ctrlComm2.GetPortOpen()){
		AfxMessageBox("打开端口3失败！");
		return ;
	}else{
		m_ctrlComm2.SetRThreshold(4);
		m_ctrlComm2.SetInputLen(0);
		m_ctrlComm2.GetInput();
	}
	if(m_ctrlComm.GetPortOpen()&&m_ctrlComm2.GetPortOpen()){
		MessageBox("设置保存成功！","Success");
	}else
		return ;
	((CButton*)GetDlgItem(IDOK))->EnableWindow(TRUE);
}
