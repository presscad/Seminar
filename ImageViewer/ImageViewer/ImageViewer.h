// ImageViewer.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CImageViewerApp:
// �йش����ʵ�֣������ ImageViewer.cpp
//

class CImageViewerApp : public CWinApp
{
public:
	CImageViewerApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CImageViewerApp theApp;

HBITMAP stretchImage(const HBITMAP hBmpSrc, int nWidth, int nHeight, bool bZoomIn = false);