// SerialSDI.h : main header file for the SERIALSDI application
//

#if !defined(AFX_SERIALSDI_H__FCB7E3E3_5041_49B9_84CE_C47C08FCE619__INCLUDED_)
#define AFX_SERIALSDI_H__FCB7E3E3_5041_49B9_84CE_C47C08FCE619__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSerialSDIApp:
// See SerialSDI.cpp for the implementation of this class
//

class CSerialSDIApp : public CWinApp
{
public:
	CSerialSDIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSerialSDIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSerialSDIApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERIALSDI_H__FCB7E3E3_5041_49B9_84CE_C47C08FCE619__INCLUDED_)
