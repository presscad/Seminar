
// Exercise_3_2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Exercise_3_2.h"
#include "Exercise_3_2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise_3_2Dlg �Ի���




CExercise_3_2Dlg::CExercise_3_2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExercise_3_2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExercise_3_2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExercise_3_2Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CExercise_3_2Dlg ��Ϣ�������

BOOL CExercise_3_2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    //ULARGE_INTEGER uliFreeBytesAvailableToCaller = {0};
    ULARGE_INTEGER uliTotalNumberOfBytes = {0};
    ULARGE_INTEGER uliTotalNumberOfFreeBytes = {0};

    //DWORD diskInfo = GetLogicalDrives();
    //int diskCount = 0;
    //while (diskInfo) {
    //    if (1 & diskInfo)
    //        ++diskCount;

    //    diskInfo >>= 1;
    //}

    BOOL bRet = GetDiskFreeSpaceEx(NULL, NULL,
        &uliTotalNumberOfBytes, &uliTotalNumberOfFreeBytes);

    CString strFree, strTotal;
    if (bRet) {
        FormatString(uliTotalNumberOfFreeBytes.QuadPart, strFree);
        FormatString(uliTotalNumberOfBytes.QuadPart, strTotal);

        strFree += _T(" �ֽ�");
        strTotal += _T(" �ֽ�");
    }
    else {
        strFree = _T("N/A �ֽ�");
        strTotal = _T("N/A �ֽ�");
    }
    
    SetDlgItemText(IDC_FREE_STATIC, strFree);
    SetDlgItemText(IDC_TOTAL_STATIC, strTotal);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CExercise_3_2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CExercise_3_2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CExercise_3_2Dlg::FormatString(ULONGLONG ullNumber, CString &strResult)
{
    strResult.Empty();

    CString strBuf;

    do {
        strBuf.Format(_T("%d"), ullNumber % 1000);
        strResult = strBuf + strResult;
        if (ullNumber /= 1000)
            strResult = _T(",") + strResult;
    } while (ullNumber);
    
}

