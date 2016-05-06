// pc_pc.h : main header file for the PC_PC application
//

#if !defined(AFX_PC_PC_H__591DE508_FD49_47E5_9049_EA0D5AA3F44A__INCLUDED_)
#define AFX_PC_PC_H__591DE508_FD49_47E5_9049_EA0D5AA3F44A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPc_pcApp:
// See pc_pc.cpp for the implementation of this class
//

class CPc_pcApp : public CWinApp
{
public:
	CPc_pcApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPc_pcApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPc_pcApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PC_PC_H__591DE508_FD49_47E5_9049_EA0D5AA3F44A__INCLUDED_)
