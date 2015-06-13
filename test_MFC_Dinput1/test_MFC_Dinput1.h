// test_MFC_Dinput1.h : main header file for the TEST_MFC_DINPUT1 application
//

#if !defined(AFX_TEST_MFC_DINPUT1_H__21EC445F_D2A3_4362_AC4D_28CBF0173C29__INCLUDED_)
#define AFX_TEST_MFC_DINPUT1_H__21EC445F_D2A3_4362_AC4D_28CBF0173C29__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest_MFC_Dinput1App:
// See test_MFC_Dinput1.cpp for the implementation of this class
//

class CTest_MFC_Dinput1App : public CWinApp
{
public:
	CTest_MFC_Dinput1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_MFC_Dinput1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTest_MFC_Dinput1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_MFC_DINPUT1_H__21EC445F_D2A3_4362_AC4D_28CBF0173C29__INCLUDED_)
