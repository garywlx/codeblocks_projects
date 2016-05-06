// FileManipulate.h : main header file for the FILEMANIPULATE application
//

#if !defined(AFX_FILEMANIPULATE_H__FF91B8D1_E1D2_44B1_A604_C5CE5A2E5EAC__INCLUDED_)
#define AFX_FILEMANIPULATE_H__FF91B8D1_E1D2_44B1_A604_C5CE5A2E5EAC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFileManipulateApp:
// See FileManipulate.cpp for the implementation of this class
//

class CFileManipulateApp : public CWinApp
{
public:
	CFileManipulateApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileManipulateApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFileManipulateApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEMANIPULATE_H__FF91B8D1_E1D2_44B1_A604_C5CE5A2E5EAC__INCLUDED_)
