// TreeCtrlSeries.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTreeCtrlSeriesApp:
// �йش����ʵ�֣������ TreeCtrlSeries.cpp
//

class CTreeCtrlSeriesApp : public CWinApp
{
public:
	CTreeCtrlSeriesApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTreeCtrlSeriesApp theApp;