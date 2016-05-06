// CommThread.h : main header file for the COMMTHREAD application
//

#if !defined(AFX_COMMTHREAD_H__44C7C726_47B1_4D72_BC51_53F7A14EEBEE__INCLUDED_)
#define AFX_COMMTHREAD_H__44C7C726_47B1_4D72_BC51_53F7A14EEBEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCommThreadApp:
// See CommThread.cpp for the implementation of this class
//

class CCommThreadApp : public CWinApp
{
public:
	CCommThreadApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCommThreadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCommThreadApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMTHREAD_H__44C7C726_47B1_4D72_BC51_53F7A14EEBEE__INCLUDED_)
