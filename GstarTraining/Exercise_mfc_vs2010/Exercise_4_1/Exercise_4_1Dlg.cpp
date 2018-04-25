
// Exercise_4_1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Exercise_4_1.h"
#include "Exercise_4_1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise_4_1Dlg �Ի���




CExercise_4_1Dlg::CExercise_4_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExercise_4_1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExercise_4_1Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST, m_listbox);
}

BEGIN_MESSAGE_MAP(CExercise_4_1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CExercise_4_1Dlg ��Ϣ�������

BOOL CExercise_4_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    m_listbox.AddString(_T("SendMessage1"));
    m_listbox.AddString(_T("SendMessage2"));
    m_listbox.AddString(_T("SendMessage3"));
    m_listbox.AddString(_T("SendMessage4"));
    m_listbox.AddString(_T("SendMessage5"));
    m_listbox.AddString(_T("SendMessage6"));

    m_listbox.AddItemIconColor(RGB(255,0,0));
    m_listbox.AddItemIconColor(RGB(255,255,0));
    m_listbox.AddItemIconColor(RGB(255,0,255));
    m_listbox.AddItemIconColor(RGB(0,255,0));
    m_listbox.AddItemIconColor(RGB(0,255,255));
    m_listbox.AddItemIconColor(RGB(0,0,255));

    m_listbox.SetIconWidth(20);
    m_listbox.SetHighlightColor(RGB(204,232,255));

    m_listbox.SetCurSel(0);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CExercise_4_1Dlg::OnPaint()
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
HCURSOR CExercise_4_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

