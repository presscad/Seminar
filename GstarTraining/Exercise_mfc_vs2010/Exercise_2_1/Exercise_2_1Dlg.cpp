
// Exercise_2_1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Exercise_2_1.h"
#include "Exercise_2_1Dlg.h"
#include "afxdialogex.h"
#include "Calculation.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise_2_1Dlg �Ի���




CExercise_2_1Dlg::CExercise_2_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExercise_2_1Dlg::IDD, pParent)
    , m_iOper(0)
    , m_dVal1(0)
    , m_dVal2(0)
    , m_dResult(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExercise_2_1Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Radio(pDX, IDC_ADD_RD, m_iOper);
    DDX_Text(pDX, IDC_VALUE1_EDT, m_dVal1);
    DDX_Text(pDX, IDC_VALUE2_EDT, m_dVal2);
    DDX_Text(pDX, IDC_RESULT_STATIC, m_dResult);
}

BEGIN_MESSAGE_MAP(CExercise_2_1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_CALC_BTN, &CExercise_2_1Dlg::OnBnClickedCalcBtn)
END_MESSAGE_MAP()


// CExercise_2_1Dlg ��Ϣ�������

BOOL CExercise_2_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CExercise_2_1Dlg::OnPaint()
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
HCURSOR CExercise_2_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExercise_2_1Dlg::OnBnClickedCalcBtn()
{
    GetDlgItem(IDC_RESULT_STATIC)->SetWindowText(_T("0"));
    UpdateData(TRUE);
    CCalculation calculation(m_dVal1, m_dVal2);
    switch (m_iOper) {
    case 0:
        calculation.Add(m_dResult);
        break;
    case 1:
        calculation.Subtract(m_dResult);
        break;
    case 2:
        calculation.Multiply(m_dResult);
        break;
    case 3:
        if (!calculation.Divide(m_dResult)) {
            AfxMessageBox(_T("���������������Ϊ�㣡"));
            GetDlgItem(IDC_RESULT_STATIC)->SetWindowText(_T("N/A"));
            return;
        }
        else break;
    default:
        break;
    }
    UpdateData(FALSE);
}


void CExercise_2_1Dlg::OnOK()
{
    // TODO: �ڴ����ר�ô����/����û���
    EndDialog(IDOK);

    //CDialogEx::OnOK();
}
