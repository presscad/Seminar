
// Exercise_2_6Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Exercise_2_6.h"
#include "Exercise_2_6Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise_2_6Dlg �Ի���




CExercise_2_6Dlg::CExercise_2_6Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExercise_2_6Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExercise_2_6Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_INFO_LV, m_lvInfo);
}

BEGIN_MESSAGE_MAP(CExercise_2_6Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CExercise_2_6Dlg ��Ϣ�������

BOOL CExercise_2_6Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    //�����б���
    m_lvInfo.InsertColumn(0, _T("��ַ"), LVCFMT_LEFT, 80);
    m_lvInfo.InsertColumn(0, _T("����"), LVCFMT_LEFT, 50);
    m_lvInfo.InsertColumn(0, _T("����"), LVCFMT_LEFT, 80);

    //����Item
    m_lvInfo.InsertItem(0, _T("��С��"));
    m_lvInfo.InsertItem(0, _T("����ΰ"));

    //����SubItem
    m_lvInfo.SetItemText(0, 1, _T("23"));
    m_lvInfo.SetItemText(0, 2, _T("����"));
    m_lvInfo.SetItemText(1, 1, _T("25"));
    m_lvInfo.SetItemText(1, 2, _T("����"));

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CExercise_2_6Dlg::OnPaint()
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
HCURSOR CExercise_2_6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

