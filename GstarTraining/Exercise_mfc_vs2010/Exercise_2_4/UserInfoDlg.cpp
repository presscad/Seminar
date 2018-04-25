// UserInfo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Exercise_2_4.h"
#include "UserInfoDlg.h"
#include "afxdialogex.h"


// CUserInfoDlg �Ի���

IMPLEMENT_DYNAMIC(CUserInfoDlg, CDialogEx)

CUserInfoDlg::CUserInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CUserInfoDlg::IDD, pParent)
    , m_strName(_T(""))
    , m_strSex(_T(""))
    , m_iAge(0)
{

}

CUserInfoDlg::~CUserInfoDlg()
{
}

void CUserInfoDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_NAME_EDT, m_strName);
    DDX_Text(pDX, IDC_SEX_EDT, m_strSex);
    DDV_MaxChars(pDX, m_strSex, 1);
    DDX_Text(pDX, IDC_AGE_EDT, m_iAge);
	DDV_MinMaxInt(pDX, m_iAge, 0, 120);
}


BEGIN_MESSAGE_MAP(CUserInfoDlg, CDialogEx)
    ON_BN_CLICKED(IDOK, &CUserInfoDlg::OnBnClickedIDOk)
END_MESSAGE_MAP()


// CUserInfoDlg ��Ϣ�������
void CUserInfoDlg::OnBnClickedIDOk()
{
    if (!UpdateData(TRUE)) return;

    if (m_strName.IsEmpty()) {
        AfxMessageBox(_T("��������Ϊ�գ�"), MB_ICONERROR);
        GetDlgItem(IDC_NAME_EDT)->GetFocus();
        return;
    }

    if (_T("��") != m_strSex && _T("Ů") != m_strSex) {
        AfxMessageBox(_T("��������ȷ���Ա���/Ů"), MB_ICONERROR);
        GetDlgItem(IDC_SEX_EDT)->GetFocus();
        return;
    }
    
    /*CDialogEx::OnOK();*/
    EndDialog(IDOK);
}