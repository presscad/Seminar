
// Exercise_4_3.h : Exercise_4_3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CExercise_4_3App:
// �йش����ʵ�֣������ Exercise_4_3.cpp
//

class CExercise_4_3App : public CWinApp
{
public:
	CExercise_4_3App();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExercise_4_3App theApp;
