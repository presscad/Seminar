
// Exercise_4_2.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CExercise_4_2App:
// �йش����ʵ�֣������ Exercise_4_2.cpp
//

class CExercise_4_2App : public CWinApp
{
public:
	CExercise_4_2App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CExercise_4_2App theApp;