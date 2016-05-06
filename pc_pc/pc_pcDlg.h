// pc_pcDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mscomm2.h"
//}}AFX_INCLUDES

#if !defined(AFX_PC_PCDLG_H__20235F6C_708A_497B_8EAA_65A95D276D28__INCLUDED_)
#define AFX_PC_PCDLG_H__20235F6C_708A_497B_8EAA_65A95D276D28__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define WM_STOP WM_USER+1
#define WM_START WM_USER+2
#define WM_SAVE WM_USER+3
#define WM_MYUPDATEDATA WM_USER+100
/////////////////////////////////////////////////////////////////////////////
// CPc_pcDlg dialog
//发送进程信息
struct SendThreadInfo{
	CMSComm* mctrlComm1;
	CString* strSend;
};
//接受线程信息
struct ReceiveThreadInfo{
	CMSComm* mctrlComm2;
	CString* strReceive;
};
UINT sendThreadFunc(LPVOID lpParam);
UINT receiveThreadFunc(LPVOID lpParam);
class CPc_pcDlg : public CDialog
{
// Construction
public:
	CPc_pcDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPc_pcDlg)
	enum { IDD = IDD_PC_PC_DIALOG };
	CComboBox	m_stop_bit2;
	CComboBox	m_stop_bit1;
	CComboBox	m_parity_bit2;
	CComboBox	m_parity_bit1;
	CComboBox	m_data_bit2;
	CComboBox	m_data_bit1;
	CComboBox	m_buffer_size2;
	CComboBox	m_buffer_size1;
	CComboBox	m_baud_rate2;
	CComboBox	m_port2;
	CComboBox	m_port1;
	CComboBox	m_baud_rate1;
	CMSComm	m_ctrlComm;
	CString	m_strReceive;
	CString	m_strSend;
	CMSComm	m_ctrlComm2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPc_pcDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CWinThread* sThread;
	CWinThread* rThread;
	// Generated message map functions
	//{{AFX_MSG(CPc_pcDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnOnCommMscomm1();
	afx_msg void OnOnCommMscomm2();
	afx_msg void OnStop();
	afx_msg void OnSaveSetting();
	DECLARE_EVENTSINK_MAP()
	afx_msg  LRESULT OnUpdateSendData(WPARAM wParam,LPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PC_PCDLG_H__20235F6C_708A_497B_8EAA_65A95D276D28__INCLUDED_)
