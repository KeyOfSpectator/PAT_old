// test_MFC_Dinput1Dlg.h : header file
//

#if !defined(AFX_TEST_MFC_DINPUT1DLG_H__004D814D_3FF7_409E_AADB_C1B2EB331331__INCLUDED_)
#define AFX_TEST_MFC_DINPUT1DLG_H__004D814D_3FF7_409E_AADB_C1B2EB331331__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest_MFC_Dinput1Dlg dialog

class CTest_MFC_Dinput1Dlg : public CDialog
{
// Construction
public:
	CTest_MFC_Dinput1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTest_MFC_Dinput1Dlg)
	enum { IDD = IDD_TEST_MFC_DINPUT1_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_MFC_Dinput1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest_MFC_Dinput1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_MFC_DINPUT1DLG_H__004D814D_3FF7_409E_AADB_C1B2EB331331__INCLUDED_)
