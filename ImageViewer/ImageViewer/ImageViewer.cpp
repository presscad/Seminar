// ImageViewer.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "ImageViewer.h"
#include "ImageViewerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageViewerApp

BEGIN_MESSAGE_MAP(CImageViewerApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CImageViewerApp ����

CImageViewerApp::CImageViewerApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CImageViewerApp ����

CImageViewerApp theApp;


// CImageViewerApp ��ʼ��

BOOL CImageViewerApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CImageViewerDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˴����ô����ʱ�á�ȷ�������ر�
		//  �Ի���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ�á�ȡ�������ر�
		//  �Ի���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}


HBITMAP stretchImage(const HBITMAP hBmpSrc, int nWidth, int nHeight, bool bZoomIn/* = false*/)
{
    if (hBmpSrc == NULL) return NULL;

    BITMAP bmp;
    ::GetObject(hBmpSrc, sizeof(BITMAP), &bmp);
    int nWidthSrc = bmp.bmWidth, nHeightSrc = bmp.bmHeight;
    double dScale = min((double)nWidth/nWidthSrc, (double)nHeight/nHeightSrc);
    int nWidthDst = (dScale>1 && !bZoomIn) ? nWidthSrc : int(nWidthSrc*dScale);
    int nHeightDst = (dScale>1 && !bZoomIn) ? nHeightSrc : int(nHeightSrc*dScale);
    int nX = (nWidth - nWidthDst)/2;
    int nY = (nHeight - nHeightDst)/2;

    HDC hdc = ::GetDC(NULL);

    // source bitmap
    HDC hMenDCSrc = ::CreateCompatibleDC(hdc);
    HBITMAP hOldBmpSrc = (HBITMAP) ::SelectObject(hMenDCSrc, hBmpSrc);

    // destination bitmap
    HDC hMemDCDst = ::CreateCompatibleDC(hdc);
    HBITMAP hBmpDst = ::CreateCompatibleBitmap(hdc, nWidth, nHeight);
    HBITMAP hOldBmpDst = (HBITMAP) ::SelectObject(hMemDCDst, hBmpDst);

    ::SetStretchBltMode(hMemDCDst, HALFTONE);
    ::SetBrushOrgEx(hMemDCDst, 0, 0, NULL);
    ::StretchBlt(hMemDCDst, nX, nY, nWidthDst, nHeightDst,
        hMenDCSrc, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);

    ::SelectObject(hMemDCDst, hOldBmpDst);
    ::SelectObject(hMenDCSrc, hOldBmpSrc);
    ::ReleaseDC(NULL, hdc);
    ::DeleteDC(hMemDCDst);
    ::DeleteDC(hMenDCSrc);

    return hBmpDst;
}