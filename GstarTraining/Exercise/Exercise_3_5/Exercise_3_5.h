
// Exercise_3_5.h : Exercise_3_5 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CExercise_3_5App:
// �йش����ʵ�֣������ Exercise_3_5.cpp
//

class CExercise_3_5App : public CWinApp
{
public:
	CExercise_3_5App();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExercise_3_5App theApp;
