
// Exercise_3_6.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CExercise_3_6App:
// �йش����ʵ�֣������ Exercise_3_6.cpp
//

class CExercise_3_6App : public CWinApp
{
public:
	CExercise_3_6App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CExercise_3_6App theApp;