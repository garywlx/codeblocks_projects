// SerialSDIView.h : interface of the CSerialSDIView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERIALSDIVIEW_H__CAA46F2C_CDC4_44D5_81F9_1EDD86870814__INCLUDED_)
#define AFX_SERIALSDIVIEW_H__CAA46F2C_CDC4_44D5_81F9_1EDD86870814__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSerialSDIView : public CFormView
{
protected: // create from serialization only
	CSerialSDIView();
	DECLARE_DYNCREATE(CSerialSDIView)

public:
	//{{AFX_DATA(CSerialSDIView)
	enum { IDD = IDD_SERIALSDI_FORM };
	CString	m_strName;
	float	m_fYuwen;
	float	m_fTotal;
	float	m_fShuxue;
	float	m_fZonghe;
	//}}AFX_DATA

// Attributes
public:
	CSerialSDIDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSerialSDIView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSerialSDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSerialSDIView)
	afx_msg void OnChangeEditName();
	afx_msg void OnChangeEditShuxue();
	afx_msg void OnChangeEditYuwen();
	afx_msg void OnChangeEditTotal();
	afx_msg void OnChangeEditZonghe();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SerialSDIView.cpp
inline CSerialSDIDoc* CSerialSDIView::GetDocument()
   { return (CSerialSDIDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERIALSDIVIEW_H__CAA46F2C_CDC4_44D5_81F9_1EDD86870814__INCLUDED_)
