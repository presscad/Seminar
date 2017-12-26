
// Exercise_1_2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Exercise_1_2.h"
#include "Exercise_1_2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise_1_2Dlg �Ի���




CExercise_1_2Dlg::CExercise_1_2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExercise_1_2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExercise_1_2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STUINFOFIELD_LIST, m_StuInfoField);
	DDX_Control(pDX, IDC_REPORTFIELD_LIST, m_ReportField);
}

BEGIN_MESSAGE_MAP(CExercise_1_2Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD_BTN, &CExercise_1_2Dlg::OnBnClickedAddBtn)
	ON_BN_CLICKED(IDC_REMOVE_BTN, &CExercise_1_2Dlg::OnBnClickedRemoveBtn)
	ON_BN_CLICKED(IDC_ADDALL_BTN, &CExercise_1_2Dlg::OnBnClickedAddallBtn)
	ON_BN_CLICKED(IDC_CLEAR_BTN, &CExercise_1_2Dlg::OnBnClickedClearBtn)
END_MESSAGE_MAP()


// CExercise_1_2Dlg ��Ϣ�������

BOOL CExercise_1_2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_StuInfoField.AddString(_T("��ַ"));
	m_StuInfoField.AddString(_T("�绰"));
	m_StuInfoField.AddString(_T("����"));
	m_StuInfoField.AddString(_T("�Ա�"));
	m_StuInfoField.AddString(_T("ѧ��"));

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CExercise_1_2Dlg::OnPaint()
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
HCURSOR CExercise_1_2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExercise_1_2Dlg::OnBnClickedAddBtn()
{
	int index = m_StuInfoField.GetCurSel();
	if (-1 == index) return;

    CString strStuInfoField, strReportField;
    m_StuInfoField.GetText(index, strStuInfoField);

    int count = m_ReportField.GetCount();

    for (int i = 0; i < count; ++i) {
        m_ReportField.GetText(i, strReportField);
        if (strReportField == strStuInfoField) {
            AfxMessageBox(_T("��ѡ�ֶ�����ӣ�"), MB_ICONWARNING);
            return;
        }
    }

    m_ReportField.AddString((LPCTSTR) strStuInfoField);
}


void CExercise_1_2Dlg::OnBnClickedRemoveBtn()
{
	m_ReportField.DeleteString(m_ReportField.GetCurSel());
}


void CExercise_1_2Dlg::OnBnClickedAddallBtn()
{
    m_ReportField.ResetContent();
	int count = m_StuInfoField.GetCount();
	for (int i = 0; i < count; ++i) {
		CString str;
		m_StuInfoField.GetText(i, str);
		m_ReportField.AddString((LPCTSTR) str);
	}
}


void CExercise_1_2Dlg::OnBnClickedClearBtn()
{
	//int count = m_ReportField.GetCount();
	//for (int i = count - 1; i >= 0; --i) {
	//	m_ReportField.DeleteString(i);
	//}
    m_ReportField.ResetContent();
}
