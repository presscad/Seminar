// AddInfoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Exercise_4_4.h"
#include "AddInfoDlg.h"
#include "afxdialogex.h"


// CAddInfoDlg �Ի���

IMPLEMENT_DYNAMIC(CAddInfoDlg, CDialogEx)

CAddInfoDlg::CAddInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddInfoDlg::IDD, pParent)
    , m_strName(_T(""))
    , m_strSex(_T(""))
    , m_strAge(_T(""))
    , m_strAddr(_T(""))
{

}

CAddInfoDlg::~CAddInfoDlg()
{
}

void CAddInfoDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_NAME_EDT, m_strName);
    DDX_Text(pDX, IDC_AGE_EDT, m_strAge);
    DDX_Text(pDX, IDC_ADDR_EDT, m_strAddr);
    DDX_CBString(pDX, IDC_SEX_COMBO, m_strSex);
}


BEGIN_MESSAGE_MAP(CAddInfoDlg, CDialogEx)
    ON_BN_CLICKED(IDOK, &CAddInfoDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddInfoDlg ��Ϣ�������


BOOL CAddInfoDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // TODO:  �ڴ���Ӷ���ĳ�ʼ��
    SetDlgItemText(IDC_ID_EDT, _T("(�Զ����)"));

    return TRUE;  // return TRUE unless you set the focus to a control
    // �쳣: OCX ����ҳӦ���� FALSE
}


void CAddInfoDlg::OnBnClickedOk()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������

    CDialogEx::OnOK();
}
