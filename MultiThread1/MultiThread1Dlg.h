// MultiThread1Dlg.h : header file
//

#if !defined(AFX_MULTITHREAD1DLG_H__CE8C68BB_C4CA_4BED_8B91_966F5D30A337__INCLUDED_)
#define AFX_MULTITHREAD1DLG_H__CE8C68BB_C4CA_4BED_8B91_966F5D30A337__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMultiThread1Dlg dialog
#include "CalculateThread.h"
#define WM_DISPLAY WM_USER+2
class CMultiThread1Dlg : public CDialog
{
// Construction
public:
	CMultiThread1Dlg(CWnd* pParent = NULL);	// standard constructor
	CWinThread* m_pCalculateThread;
	
// Dialog Data
	//{{AFX_DATA(CMultiThread1Dlg)
	enum { IDD = IDD_MULTITHREAD1_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThread1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	int nAdded;
	LRESULT OnDisplay(WPARAM wParam,LPARAM lParam);
	//{{AFX_MSG(CMultiThread1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnSum();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREAD1DLG_H__CE8C68BB_C4CA_4BED_8B91_966F5D30A337__INCLUDED_)
