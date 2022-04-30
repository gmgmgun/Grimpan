
// GrimpanTest.h : main header file for the GrimpanTest application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CGrimpanTestApp:
// See GrimpanTest.cpp for the implementation of this class
//

class CGrimpanTestApp : public CWinApp
{
public:
	CGrimpanTestApp() noexcept;
	ULONG_PTR m_gdiplusToken;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CGrimpanTestApp theApp;
