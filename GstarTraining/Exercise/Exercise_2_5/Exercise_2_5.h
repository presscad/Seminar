
// Exercise_2_5.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CExercise_2_5App:
// �йش����ʵ�֣������ Exercise_2_5.cpp
//

class CExercise_2_5App : public CWinApp
{
public:
	CExercise_2_5App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CExercise_2_5App theApp;