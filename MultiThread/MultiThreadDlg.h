// MultiThreadDlg.h : header file
//

#if !defined(AFX_MULTITHREADDLG_H__8E3C4593_C3B2_4592_A294_F135CE027536__INCLUDED_)
#define AFX_MULTITHREADDLG_H__8E3C4593_C3B2_4592_A294_F135CE027536__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMultiThreadDlg dialog
struct threadInfo{
	UINT nMilliSecond;
	CProgressCtrl* pctrlProgress;

};
UINT ThreadFunc(LPVOID lpParam);
class CMultiThreadDlg : public CDialog
{
// Construction
public:
	CMultiThreadDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMultiThreadDlg)
	enum { IDD = IDD_MULTITHREAD_DIALOG };
	CProgressCtrl	m_ctrlProgress;
	int		m_nMilliSecond;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThreadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CWinThread* pThread;
	// Generated message map functions
	//{{AFX_MSG(CMultiThreadDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	afx_msg void OnCreate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREADDLG_H__8E3C4593_C3B2_4592_A294_F135CE027536__INCLUDED_)
