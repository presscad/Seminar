
// Exercise_1_4Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Exercise_1_4.h"
#include "Exercise_1_4Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise_1_4Dlg �Ի���




CExercise_1_4Dlg::CExercise_1_4Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExercise_1_4Dlg::IDD, pParent)
    , m_iRadio(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExercise_1_4Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Radio(pDX, IDC_NAME_RD, m_iRadio);
}

BEGIN_MESSAGE_MAP(CExercise_1_4Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_CONTROL_RANGE(BN_CLICKED, IDC_NAME_RD, IDC_SEX_RD, OnCheckRadioButton)
END_MESSAGE_MAP()


// CExercise_1_4Dlg ��Ϣ�������

BOOL CExercise_1_4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    CComboBox *pCombo = (CComboBox*) GetDlgItem(IDC_SEX_CB);
    pCombo->AddString(_T("��"));
    pCombo->AddString(_T("Ů"));
    pCombo->SetCurSel(0);
    pCombo->EnableWindow(FALSE);

    GetDlgItem(IDC_NAME_EDT)->SetFocus();

	return FALSE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CExercise_1_4Dlg::OnPaint()
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
HCURSOR CExercise_1_4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CExercise_1_4Dlg::OnCheckRadioButton(UINT uId)
{
    switch (uId)
    {
    case IDC_NAME_RD:
        GetDlgItem(IDC_SEX_CB)->EnableWindow(FALSE);
        GetDlgItem(IDC_NAME_EDT)->EnableWindow(TRUE);
        GetDlgItem(IDC_NAME_EDT)->SetFocus();
        break;

    case IDC_SEX_RD:
        GetDlgItem(IDC_SEX_CB)->EnableWindow(TRUE);
        GetDlgItem(IDC_NAME_EDT)->EnableWindow(FALSE);
        GetDlgItem(IDC_SEX_CB)->SetFocus();
        break;

    default:
        break;
    }
}

