// CommThreadDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mscomm.h"
//}}AFX_INCLUDES

#if !defined(AFX_COMMTHREADDLG_H__86855828_070C_420A_A538_FACE4E0DED28__INCLUDED_)
#define AFX_COMMTHREADDLG_H__86855828_070C_420A_A538_FACE4E0DED28__INCLUDED_
#define WM_STOP WM_USER + 1
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCommThreadDlg dialog

class CCommThreadDlg : public CDialog
{
// Construction
public:
	CCommThreadDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCommThreadDlg)
	enum { IDD = IDD_COMMTHREAD_DIALOG };
	CString	m_nSendtr;
	CString	m_nReceiveStr;
	CMSComm	m_CtrlSend;
	CMSComm	m_CtrlReceive;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCommThreadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCommThreadDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOnCommMscomm1();
	afx_msg void OnOnCommMscomm2();
	afx_msg void OnSend();
	afx_msg void OnCancel();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMTHREADDLG_H__86855828_070C_420A_A538_FACE4E0DED28__INCLUDED_)
