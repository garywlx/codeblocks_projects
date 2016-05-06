// SerialSDIView.cpp : implementation of the CSerialSDIView class
//

#include "stdafx.h"
#include "SerialSDI.h"

#include "SerialSDIDoc.h"
#include "SerialSDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSerialSDIView

IMPLEMENT_DYNCREATE(CSerialSDIView, CFormView)

BEGIN_MESSAGE_MAP(CSerialSDIView, CFormView)
	//{{AFX_MSG_MAP(CSerialSDIView)
	ON_EN_CHANGE(IDC_EDIT_NAME, OnChangeEditName)
	ON_EN_CHANGE(IDC_EDIT_SHUXUE, OnChangeEditShuxue)
	ON_EN_CHANGE(IDC_EDIT_YUWEN, OnChangeEditYuwen)
	ON_EN_CHANGE(IDC_EDIT_TOTAL, OnChangeEditTotal)
	ON_EN_CHANGE(IDC_EDIT_ZONGHE, OnChangeEditZonghe)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSerialSDIView construction/destruction

CSerialSDIView::CSerialSDIView()
	: CFormView(CSerialSDIView::IDD)
{
	//{{AFX_DATA_INIT(CSerialSDIView)
	m_strName = _T("");
	m_fYuwen = 0.0f;
	m_fTotal = 0.0f;
	m_fShuxue = 0.0f;
	m_fZonghe = 0.0f;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CSerialSDIView::~CSerialSDIView()
{
}

void CSerialSDIView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSerialSDIView)
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_SHUXUE, m_fYuwen);
	DDX_Text(pDX, IDC_EDIT_TOTAL, m_fTotal);
	DDX_Text(pDX, IDC_EDIT_YUWEN, m_fShuxue);
	DDX_Text(pDX, IDC_EDIT_ZONGHE, m_fZonghe);
	//}}AFX_DATA_MAP
}

BOOL CSerialSDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CSerialSDIView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	//初始化成员变量
	
	CSerialSDIDoc *pDoc=GetDocument();
	m_strName =pDoc->strName;
//	m_fYuwen=pDoc->fYuwen;
//	m_fShuxue=pDoc->fShuxue;
//	m_fZonghe=pDoc->fZonghe;
//	m_fTotal=pDoc->ftotal;
	
	UpdateData(FALSE);


}

/////////////////////////////////////////////////////////////////////////////
// CSerialSDIView printing

BOOL CSerialSDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSerialSDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSerialSDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CSerialSDIView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CSerialSDIView diagnostics

#ifdef _DEBUG
void CSerialSDIView::AssertValid() const
{
	CFormView::AssertValid();
}

void CSerialSDIView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CSerialSDIDoc* CSerialSDIView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSerialSDIDoc)));
	return (CSerialSDIDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSerialSDIView message handlers

void CSerialSDIView::OnChangeEditName() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CSerialSDIDoc *pDoc=GetDocument();
	UpdateData(TRUE);
	if(strcmp(pDoc->strName,m_strName)){
		pDoc->strName=m_strName;
		pDoc->SetModifiedFlag(TRUE);
		
	}
	
}

void CSerialSDIView::OnChangeEditShuxue() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CSerialSDIDoc *pDoc=GetDocument();
	UpdateData(TRUE);
	if(pDoc->fShuxue!=m_fShuxue){
		pDoc->fShuxue=m_fShuxue;
		m_fTotal=m_fYuwen+m_fShuxue+m_fZonghe;
		pDoc->fZonghe=m_fZonghe;
		pDoc->SetModifiedFlag(TRUE);
		UpdateData(FALSE);
	}
	
}

void CSerialSDIView::OnChangeEditYuwen() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CSerialSDIDoc *pDoc=GetDocument();
	UpdateData(TRUE);
	if(pDoc->fYuwen!=m_fYuwen){
		pDoc->fYuwen=m_fYuwen;
		m_fTotal=m_fYuwen+m_fShuxue+m_fZonghe;
		pDoc->fYuwen=m_fYuwen;
		pDoc->SetModifiedFlag(TRUE);
		UpdateData(FALSE);
	}
}

void CSerialSDIView::OnChangeEditTotal() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CSerialSDIView::OnChangeEditZonghe() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CSerialSDIDoc *pDoc=GetDocument();
	UpdateData(TRUE);
	if(pDoc->fZonghe!=m_fZonghe){
		pDoc->fYuwen=m_fYuwen;
		m_fTotal=m_fYuwen+m_fShuxue+m_fZonghe;
		pDoc->fZonghe=m_fZonghe;
		pDoc->SetModifiedFlag(TRUE);
		UpdateData(FALSE);
	}
}
