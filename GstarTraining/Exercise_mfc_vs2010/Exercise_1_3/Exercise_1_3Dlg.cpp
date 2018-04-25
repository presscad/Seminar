
// Exercise_1_3Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Exercise_1_3.h"
#include "Exercise_1_3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CExercise_1_3Dlg �Ի���


CExercise_1_3Dlg::CExercise_1_3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExercise_1_3Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExercise_1_3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CURITEM_STATIC, m_CurItem);
	DDX_Control(pDX, IDC_CATALOG_COMBO, m_Catalog);
	DDX_Control(pDX, IDC_LIST_LIST, m_List);
}

BEGIN_MESSAGE_MAP(CExercise_1_3Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_CBN_SELCHANGE(IDC_CATALOG_COMBO, &CExercise_1_3Dlg::OnCbnSelchangeCatalogCombo)
    ON_LBN_SELCHANGE(IDC_LIST_LIST, &CExercise_1_3Dlg::OnLbnSelchangeListList)
END_MESSAGE_MAP()


// CExercise_1_3Dlg ��Ϣ�������

BOOL CExercise_1_3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

    InitData();


    m_Catalog.SetCurSel(0);
    OnCbnSelchangeCatalogCombo();
    m_List.SetCurSel(0);
    OnLbnSelchangeListList();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CExercise_1_3Dlg::OnPaint()
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
HCURSOR CExercise_1_3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CExercise_1_3Dlg::InitData()
{
    m_ArrayFruit.Add(_T("����"));
    m_ArrayFruit.Add(_T("��"));
    m_ArrayFruit.Add(_T("⨺���"));
    m_ArrayFruit.Add(_T("ƻ��"));
    m_ArrayStudyMaterial.Add(_T("�ֱ�"));
    m_ArrayStudyMaterial.Add(_T("�ʼǱ�"));
    m_ArrayStudyMaterial.Add(_T("��Ƥ"));

    m_Catalog.AddString(_T("ˮ��"));
    m_Catalog.AddString(_T("ѧϰ��Ʒ"));

    m_Catalog.SetItemDataPtr(0, (void*) &m_ArrayFruit);
    m_Catalog.SetItemDataPtr(1, (void*) &m_ArrayStudyMaterial);
}

void CExercise_1_3Dlg::OnCbnSelchangeCatalogCombo()
{
    m_List.ResetContent();
    CArray<CString> *pListItem = (CArray<CString> *) (m_Catalog.GetItemDataPtr(m_Catalog.GetCurSel()));
    int iCount = pListItem->GetCount();
    for (int i = 0; i < iCount; ++i)
        m_List.AddString(pListItem->GetAt(i));

    m_List.SetCurSel(0);
    OnLbnSelchangeListList();
}


void CExercise_1_3Dlg::OnLbnSelchangeListList()
{
    CString str;
    m_List.GetText(m_List.GetCurSel(), str);
    m_CurItem.SetWindowText(str);
}
