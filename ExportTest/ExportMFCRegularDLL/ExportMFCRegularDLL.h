// ExportMFCRegularDLL.h : ExportMFCRegularDLL DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CExportMFCRegularDLLApp
// �йش���ʵ�ֵ���Ϣ������� ExportMFCRegularDLL.cpp
//

class CExportMFCRegularDLLApp : public CWinApp
{
public:
	CExportMFCRegularDLLApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
