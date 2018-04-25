
// Exercise_2_5Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Exercise_2_5.h"
#include "Exercise_2_5Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise_2_5Dlg �Ի���




CExercise_2_5Dlg::CExercise_2_5Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExercise_2_5Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

    personInfo[0].iAge = 45, personInfo[0].strName = _T("����"), personInfo[0].strSex = _T("��");
    personInfo[1].iAge = 30, personInfo[1].strName = _T("����"), personInfo[1].strSex = _T("��");
}

void CExercise_2_5Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_INFO_TREE, m_treeInfo);
}

BEGIN_MESSAGE_MAP(CExercise_2_5Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_NOTIFY(NM_CLICK, IDC_INFO_TREE, &CExercise_2_5Dlg::OnNMClickInfoTree)
END_MESSAGE_MAP()


// CExercise_2_5Dlg ��Ϣ�������

BOOL CExercise_2_5Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    HTREEITEM hPatent, hChild;
    hPatent = m_treeInfo.InsertItem(_T("��2001��"));

    hChild = m_treeInfo.InsertItem(personInfo[0].strName, hPatent);
    m_treeInfo.SetItemData(hChild, (DWORD_PTR) &personInfo[0]);
    hChild = m_treeInfo.InsertItem(personInfo[1].strName, hPatent);
    m_treeInfo.SetItemData(hChild, (DWORD_PTR) &personInfo[1]);

    m_treeInfo.InsertItem(_T("��2002��"));

    m_treeInfo.Expand(hPatent, TVE_EXPAND);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CExercise_2_5Dlg::OnPaint()
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
HCURSOR CExercise_2_5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExercise_2_5Dlg::OnNMClickInfoTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������

    CPoint pt;
    UINT uFlag = 0;
    GetCursorPos(&pt);
    m_treeInfo.ScreenToClient(&pt);
    HTREEITEM hItemSel = m_treeInfo.GetSelectedItem();
    HTREEITEM hItemHistTest = m_treeInfo.HitTest(pt, &uFlag);

    if (hItemHistTest) {
        if (hItemHistTest == hItemSel) return;

        if (TVHT_ONITEM & uFlag) {
            PersonInfo *pPersonInfo = (PersonInfo*) m_treeInfo.GetItemData(hItemHistTest);
            CEdit *pEdtName = (CEdit*) GetDlgItem(IDC_NAME_EDT);
            CEdit *pEdtSex = (CEdit*) GetDlgItem(IDC_SEX_EDT);
            CEdit *pEdtAge = (CEdit*) GetDlgItem(IDC_AGE_EDT);
            if (pPersonInfo) {
                pEdtName->SetWindowText(pPersonInfo->strName);
                pEdtSex->SetWindowText(pPersonInfo->strSex);
                CString strBuf;
                strBuf.Format(_T("%d"), pPersonInfo->iAge);
                pEdtAge->SetWindowText(strBuf);
            }
            else {
                pEdtName->SetWindowText(_T(""));
                pEdtSex->SetWindowText(_T(""));
                pEdtAge->SetWindowText(_T(""));
            }
        }
    }

    *pResult = 0;
}
