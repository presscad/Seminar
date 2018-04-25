
// Exercise_2_4Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Exercise_2_4.h"
#include "Exercise_2_4Dlg.h"
#include "afxdialogex.h"
#include "UserInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise_2_4Dlg �Ի���




CExercise_2_4Dlg::CExercise_2_4Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExercise_2_4Dlg::IDD, pParent)
    , m_strName(_T("")), m_strSex(_T("")), m_iAge(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExercise_2_4Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExercise_2_4Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_SHOW_BTN, &CExercise_2_4Dlg::OnBnClickedShowBtn)
END_MESSAGE_MAP()


// CExercise_2_4Dlg ��Ϣ�������

BOOL CExercise_2_4Dlg::OnInitDialog()
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

void CExercise_2_4Dlg::OnPaint()
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
HCURSOR CExercise_2_4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExercise_2_4Dlg::OnBnClickedShowBtn()
{
    
    CUserInfoDlg userInfoDlg;
    CString str;
    CEdit *pInfo = (CEdit*) GetDlgItem(IDC_INFO_EDT);
    pInfo->GetWindowText(str);

    if (!str.IsEmpty()) {
        CStringArray strArray;
        SplitString((LPCTSTR) str, _T("-"), strArray);
        if (strArray.GetCount() >= 3) {
            userInfoDlg.m_strName = m_strName = strArray[0];
            userInfoDlg.m_strSex = m_strSex = strArray[1];
            userInfoDlg.m_iAge = m_iAge = _ttoi((LPCTSTR) strArray[2]);
        }
    }

    if (IDOK == userInfoDlg.DoModal()) {
        if (userInfoDlg.m_strName.IsEmpty() || userInfoDlg.m_strSex.IsEmpty()) {
            str.Empty();
        }
        else {
            m_strName = userInfoDlg.m_strName;
            m_strSex = userInfoDlg.m_strSex;
            m_iAge = userInfoDlg.m_iAge;
            str.Format(_T("%s-%s-%d"), m_strName, m_strSex, m_iAge);
        }

        pInfo->SetWindowText(str);
    }
}

void CExercise_2_4Dlg::SplitString(LPCTSTR szSrc, LPCTSTR szDelim, CStringArray &strArray)
{
    LPTSTR szTemp = new TCHAR[_tcslen(szSrc) + 1];
    _tcscpy(szTemp, szSrc);

    LPTSTR ptr = _tcstok(szTemp, szDelim);
    strArray.RemoveAll();
    while (ptr) {
        strArray.Add(ptr);
        ptr = _tcstok(NULL, szDelim);
    }
    delete[] szTemp;
}
