
// Exercise_4_4Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Exercise_4_4.h"
#include "Exercise_4_4Dlg.h"
#include "afxdialogex.h"
#include "DBAccess.h"
#include "AddInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise_4_4Dlg �Ի���




CExercise_4_4Dlg::CExercise_4_4Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExercise_4_4Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExercise_4_4Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LISTVIEW, m_LV);
}

BEGIN_MESSAGE_MAP(CExercise_4_4Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_ADD_BTN, &CExercise_4_4Dlg::OnBnClickedAddBtn)
    ON_BN_CLICKED(IDC_REMOVE_BTN, &CExercise_4_4Dlg::OnBnClickedRemoveBtn)
END_MESSAGE_MAP()


// CExercise_4_4Dlg ��Ϣ�������

BOOL CExercise_4_4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    m_LV.InsertColumn(0, _T("��ַ"), LVCFMT_LEFT, 60);
    m_LV.InsertColumn(0, _T("����"), LVCFMT_LEFT, 40);
    m_LV.InsertColumn(0, _T("�Ա�"), LVCFMT_LEFT, 40);
    m_LV.InsertColumn(0, _T("����"), LVCFMT_LEFT, 60);
    m_LV.InsertColumn(0, _T("���"), LVCFMT_LEFT, 40);

    m_LV.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

    QueryData();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CExercise_4_4Dlg::OnPaint()
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
HCURSOR CExercise_4_4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CExercise_4_4Dlg::QueryData()
{
    m_LV.DeleteAllItems();

    DBAccess dbAccess;
    CAdoRecordSet recordSet;
    if (!dbAccess.executeQuery(_T("SELECT * FROM PERSONINFO"), recordSet))
        return FALSE;

    CString strBuf;
    recordSet.MoveLast();
    while (!recordSet.IsBOF()) {
        recordSet.GetCollect(_T("ID"), strBuf);
        m_LV.InsertItem(0, strBuf);
        recordSet.GetCollect(_T("UserName"), strBuf);
        m_LV.SetItemText(0, 1, strBuf);
        recordSet.GetCollect(_T("Sex"), strBuf);
        m_LV.SetItemText(0, 2, strBuf);
        recordSet.GetCollect(_T("Age"), strBuf);
        m_LV.SetItemText(0, 3, strBuf);
        recordSet.GetCollect(_T("Addr"), strBuf);
        m_LV.SetItemText(0, 4, strBuf);
        recordSet.MovePrevious();
    }

    recordSet.Close();

    return TRUE;
}



void CExercise_4_4Dlg::OnBnClickedAddBtn()
{
    CAddInfoDlg addInfoDlg;
    if (IDOK == addInfoDlg.DoModal()) {
        CString sql(_T("INSERT INTO PersonInfo(UserName,Sex,Age,Addr) VALUES(\'"));
        sql += addInfoDlg.m_strName;
        sql += _T("\',\'");
        sql += addInfoDlg.m_strSex;
        sql += _T("\',\'");
        sql += addInfoDlg.m_strAge;
        sql += _T("\',\'");
        sql += addInfoDlg.m_strAddr;
        sql += _T("\')");

        DBAccess dbAccess;
        if (dbAccess.executeNonQuery(sql) > 0) {
            AfxMessageBox(_T("�ɹ����һ���û���Ϣ��"));
            QueryData();
        }
        else
            AfxMessageBox(_T("�û���Ϣ���ʧ�ܣ�"));
    }
}


void CExercise_4_4Dlg::OnBnClickedRemoveBtn()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    int iRowId = m_LV.GetSelectionMark();
    if (-1 == iRowId) return;

    CString strPersonId = m_LV.GetItemText(iRowId, 0);
    {
        DBAccess dbAccess;
        CString sql;
        sql.Format(_T("DELETE FROM PersonInfo WHERE ID=%d"), _ttoi(strPersonId));
        dbAccess.executeNonQuery(sql);
    }

    QueryData();
}
