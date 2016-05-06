// SerialSDIDoc.h : interface of the CSerialSDIDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERIALSDIDOC_H__6498BBAC_5186_47AD_B2C1_C4DC2A8B370D__INCLUDED_)
#define AFX_SERIALSDIDOC_H__6498BBAC_5186_47AD_B2C1_C4DC2A8B370D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSerialSDIDoc : public CDocument
{
protected: // create from serialization only
	CSerialSDIDoc();
	DECLARE_DYNCREATE(CSerialSDIDoc)

// Attributes
public:
	CString strName;
	float fYuwen;
	float fShuxue;
	float fZonghe;
	float ftotal;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSerialSDIDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSerialSDIDoc();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	
// Generated message map functions
protected:
	//{{AFX_MSG(CSerialSDIDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERIALSDIDOC_H__6498BBAC_5186_47AD_B2C1_C4DC2A8B370D__INCLUDED_)
