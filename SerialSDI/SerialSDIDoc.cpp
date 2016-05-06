// SerialSDIDoc.cpp : implementation of the CSerialSDIDoc class
//

#include "stdafx.h"
#include "SerialSDI.h"

#include "SerialSDIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSerialSDIDoc

IMPLEMENT_DYNCREATE(CSerialSDIDoc, CDocument)

BEGIN_MESSAGE_MAP(CSerialSDIDoc, CDocument)
	//{{AFX_MSG_MAP(CSerialSDIDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSerialSDIDoc construction/destruction

CSerialSDIDoc::CSerialSDIDoc()
{
	// TODO: add one-time construction code here

}

CSerialSDIDoc::~CSerialSDIDoc()
{
}

BOOL CSerialSDIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSerialSDIDoc serialization

void CSerialSDIDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar<<strName;
		ar<<fYuwen;
		ar<<fShuxue;
		ar<<fZonghe;
		ar<<ftotal;
	}
	else
	{
		// TODO: add loading code here
		ar>>strName;
		ar>>fYuwen;
		ar>>fShuxue;
		ar>>fZonghe;
		ar>>ftotal;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSerialSDIDoc diagnostics

#ifdef _DEBUG
void CSerialSDIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSerialSDIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSerialSDIDoc commands
