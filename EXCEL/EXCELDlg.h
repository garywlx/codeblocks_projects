// EXCELDlg.h : header file
//

#if !defined(AFX_EXCELDLG_H__97E85B3E_13C4_4DA3_97E6_5FE7A8CA6A42__INCLUDED_)
#define AFX_EXCELDLG_H__97E85B3E_13C4_4DA3_97E6_5FE7A8CA6A42__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEXCELDlg dialog

class CEXCELDlg : public CDialog
{
// Construction
public:
	CEXCELDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEXCELDlg)
	enum { IDD = IDD_EXCEL_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEXCELDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEXCELDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddexceldata();
	virtual void OnCancel();
	afx_msg void OnRelease();
	afx_msg void OnSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXCELDLG_H__97E85B3E_13C4_4DA3_97E6_5FE7A8CA6A42__INCLUDED_)
