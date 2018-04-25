
// Exercise_3_8Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Exercise_3_8.h"
#include "Exercise_3_8Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise_3_8Dlg �Ի���

#define WM_UPDATEVALUE (WM_USER + 100)


CExercise_3_8Dlg::CExercise_3_8Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExercise_3_8Dlg::IDD, pParent)
    , m_iThreadIndex(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    for (int i = 0; i < 3; ++i)
        m_nId[i] = i + IDC_THRD1_STATIC;
}

void CExercise_3_8Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExercise_3_8Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_WM_TIMER()
    ON_MESSAGE(WM_UPDATEVALUE, &CExercise_3_8Dlg::OnUpdateValue)
    ON_WM_DESTROY()
END_MESSAGE_MAP()


// CExercise_3_8Dlg ��Ϣ�������

BOOL CExercise_3_8Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    SetTimer(1, 1000, NULL);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CExercise_3_8Dlg::OnPaint()
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
HCURSOR CExercise_3_8Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

ULONG CExercise_3_8Dlg::m_ulData = 0;
CMutex CExercise_3_8Dlg::m_mutex;
BOOL CExercise_3_8Dlg::m_bDestroy = FALSE;

UINT CExercise_3_8Dlg::ThreadFun(LPVOID pParam)
{
    int *pId = (int*) pParam;
    while (TRUE) {
        WaitForSingleObject(m_mutex.m_hObject, INFINITE);
        if (!m_bDestroy) {
            InterlockedIncrement(&m_ulData);
            ::SendMessage(AfxGetMainWnd()->m_hWnd, WM_UPDATEVALUE, 0, (LPARAM) *pId);
            Sleep(3000);
        }
        else {
            m_mutex.Unlock();
            break;
        }
        m_mutex.Unlock();
    }
    
    return 0;
}


void CExercise_3_8Dlg::OnTimer(UINT_PTR nIDEvent)
{
    SetDlgItemText(m_nId[m_iThreadIndex], _T("����"));
    m_thread[m_iThreadIndex] = AfxBeginThread(ThreadFun, (LPVOID) &m_nId[m_iThreadIndex]);
    
    if (++m_iThreadIndex >= 3)
        KillTimer(1);

    CDialogEx::OnTimer(nIDEvent);
}

LRESULT CExercise_3_8Dlg::OnUpdateValue(WPARAM wParam, LPARAM lParam)
{
    SetDlgItemInt(IDC_NUM_EDT, m_ulData, FALSE);
    SetDlgItemText(IDC_THRD1_STATIC, IDC_THRD1_STATIC == lParam ? _T("����") : _T("�ȴ�"));
    SetDlgItemText(IDC_THRD2_STATIC, IDC_THRD2_STATIC == lParam ? _T("����") : _T("�ȴ�"));
    SetDlgItemText(IDC_THRD3_STATIC, IDC_THRD3_STATIC == lParam ? _T("����") : _T("�ȴ�"));
    return 0;
}


void CExercise_3_8Dlg::OnDestroy()
{
    CDialogEx::OnDestroy();

    // TODO: �ڴ˴������Ϣ����������
    m_bDestroy = TRUE;
    HANDLE hThread[] = {m_thread[0]->m_hThread,
        m_thread[1]->m_hThread, m_thread[2]->m_hThread};

    WaitForMultipleObjects(3, hThread, TRUE, INFINITE);
}
