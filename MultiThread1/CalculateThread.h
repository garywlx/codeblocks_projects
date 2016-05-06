#if !defined(AFX_CALCULATETHREAD_H__2D12428A_E3BA_4D44_A9C5_77AE9C28B536__INCLUDED_)
#define AFX_CALCULATETHREAD_H__2D12428A_E3BA_4D44_A9C5_77AE9C28B536__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CalculateThread.h : header file
//
#define WM_CALCULATE WM_USER+1


/////////////////////////////////////////////////////////////////////////////
// CCalculateThread thread

class CCalculateThread : public CWinThread
{
	DECLARE_DYNCREATE(CCalculateThread)
protected:
	CCalculateThread();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalculateThread)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CCalculateThread();
	afx_msg LONG OnCalculate(UINT wParam,LONG lParam);
	// Generated message map functions
	//{{AFX_MSG(CCalculateThread)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALCULATETHREAD_H__2D12428A_E3BA_4D44_A9C5_77AE9C28B536__INCLUDED_)
