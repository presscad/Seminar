
// Exercise_3_6Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Exercise_3_6.h"
#include "Exercise_3_6Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise_3_6Dlg �Ի���

#define WM_NOTIFYICON (WM_USER + 100)



CExercise_3_6Dlg::CExercise_3_6Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExercise_3_6Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    memset(&m_nid, 0, sizeof(NOTIFYICONDATA));
}

void CExercise_3_6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExercise_3_6Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_MESSAGE(WM_NOTIFYICON, &CExercise_3_6Dlg::OnNotifyIcon)
    ON_WM_DESTROY()
    ON_COMMAND(ID_SHOW, &CExercise_3_6Dlg::OnShow)
    ON_COMMAND(ID_EXIT, &CExercise_3_6Dlg::OnExit)
    ON_BN_CLICKED(IDOK, &CExercise_3_6Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CExercise_3_6Dlg ��Ϣ�������

BOOL CExercise_3_6Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    m_nid.cbSize = sizeof(NOTIFYICONDATA);
    m_nid.uID = IDR_MAINFRAME;
    m_nid.hWnd = GetSafeHwnd();
    m_nid.hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME));
    _tcscpy(m_nid.szTip, _T("������ʾ����"));
    m_nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
    m_nid.uCallbackMessage = WM_NOTIFYICON;

    Shell_NotifyIcon(NIM_ADD, &m_nid);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CExercise_3_6Dlg::OnPaint()
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
HCURSOR CExercise_3_6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

LRESULT CExercise_3_6Dlg::OnNotifyIcon(WPARAM wParam, LPARAM lParam)
{
    if (IDR_MAINFRAME != wParam)
        return 1;

    switch (lParam) {
    case WM_LBUTTONUP:
            SetForegroundWindow();
            ShowWindow(SW_SHOWNORMAL);
        break;

    case WM_RBUTTONUP:
        {
            CMenu menu;
            menu.LoadMenu(IDR_MENU);
            CPoint point;
            GetCursorPos(&point);
            CMenu *pSubMenu = menu.GetSubMenu(0);
            SetForegroundWindow(); //������̲˵�����ʧ
            pSubMenu->TrackPopupMenu(TPM_LEFTBUTTON, point.x, point.y, this);
            PostMessage(WM_NULL,0,0); //������̲˵�����ʧ
            menu.DestroyMenu();
        }

    default:
        break;
    }
    return 0;
}



void CExercise_3_6Dlg::OnDestroy()
{
    CDialogEx::OnDestroy();

    // TODO: �ڴ˴������Ϣ����������

    Shell_NotifyIcon(NIM_DELETE, &m_nid);
}


void CExercise_3_6Dlg::OnShow()
{
    SetForegroundWindow();
    ShowWindow(SW_SHOWNORMAL);
}


void CExercise_3_6Dlg::OnExit()
{
    PostQuitMessage(0);
}


void CExercise_3_6Dlg::OnBnClickedOk()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    //if (IDYES == MessageBox(_T("��С�������½������𣿷���ֱ���˳���"),
    //    NULL, MB_YESNO | MB_ICONQUESTION)) {
            ShowWindow(SW_HIDE);
            m_nid.uFlags |= NIF_INFO;
            m_nid.uTimeout = 1000;
            m_nid.dwInfoFlags = 1;
            _tcscpy(m_nid.szInfo, _T("����С��������"));
            _tcscpy(m_nid.szInfoTitle, _T("������ʾ"));
            Shell_NotifyIcon(NIM_MODIFY, &m_nid);
            return;
    //}

    CDialogEx::OnOK();
}
