// FileManipulateDlg.h : header file
//

#if !defined(AFX_FILEMANIPULATEDLG_H__4DC2FB4A_7EBF_4195_8E92_B8723687FE40__INCLUDED_)
#define AFX_FILEMANIPULATEDLG_H__4DC2FB4A_7EBF_4195_8E92_B8723687FE40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFileManipulateDlg dialog

class CFileManipulateDlg : public CDialog
{
// Construction
public:
	CFileManipulateDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFileManipulateDlg)
	enum { IDD = IDD_FILEMANIPULATE_DIALOG };
	CString	m_szSrcFile;
	CString	m_szDstFile;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileManipulateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFileManipulateDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCopy();
	afx_msg void OnMove();
	afx_msg void OnOpensrc();
	afx_msg void OnOpendst();
	afx_msg void OnDel();
	afx_msg void OnCancle();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEMANIPULATEDLG_H__4DC2FB4A_7EBF_4195_8E92_B8723687FE40__INCLUDED_)
