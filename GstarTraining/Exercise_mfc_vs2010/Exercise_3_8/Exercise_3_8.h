
// Exercise_3_8.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CExercise_3_8App:
// �йش����ʵ�֣������ Exercise_3_8.cpp
//

class CExercise_3_8App : public CWinApp
{
public:
	CExercise_3_8App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CExercise_3_8App theApp;