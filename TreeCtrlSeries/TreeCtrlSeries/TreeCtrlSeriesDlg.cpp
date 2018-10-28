// TreeCtrlSeriesDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TreeCtrlSeries.h"
#include "TreeCtrlSeriesDlg.h"

#include "rapidjson/document.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTreeCtrlSeriesDlg �Ի���




CTreeCtrlSeriesDlg::CTreeCtrlSeriesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTreeCtrlSeriesDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    m_imgList.Create(24, 24, ILC_COLOR32, 0, 1);
    m_imgList.Add(m_hIcon);
}

void CTreeCtrlSeriesDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_TREE, m_tree);
}

BEGIN_MESSAGE_MAP(CTreeCtrlSeriesDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
    ON_BN_CLICKED(IDC_BTN_SAVE, &CTreeCtrlSeriesDlg::OnBnClickedBtnSave)
END_MESSAGE_MAP()


// CTreeCtrlSeriesDlg ��Ϣ�������

BOOL CTreeCtrlSeriesDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    m_tree.SetImageList(&m_imgList, LVSIL_NORMAL);

    HTREEITEM hRoot = m_tree.InsertItem(_T("Root"), 0, 0, TVI_ROOT);
    HTREEITEM hSubRoot = m_tree.InsertItem(_T("SubRoot"), 0, 0, hRoot);
    m_tree.InsertItem(_T("Leaf1"), 0, 0, hRoot);
    m_tree.InsertItem(_T("Leaf2"), 0, 0, hSubRoot);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTreeCtrlSeriesDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
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
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CTreeCtrlSeriesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTreeCtrlSeriesDlg::OnBnClickedBtnSave()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    rapidjson::Document doc;
    const char json[] = " { \"hello\" : \"world\", \"t\" : true , \"f\" : false, \"n\": null, \"i\":123, \"pi\": 3.1416, \"a\":[1, 2, 3, 4] } ";
    doc.Parse(json);
}
