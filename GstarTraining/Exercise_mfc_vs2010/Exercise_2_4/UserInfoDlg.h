#pragma once

class CExercise_2_4Dlg;

// CUserInfoDlg �Ի���

class CUserInfoDlg : public CDialogEx
{
    friend CExercise_2_4Dlg;

	DECLARE_DYNAMIC(CUserInfoDlg)

public:
	CUserInfoDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUserInfoDlg();

// �Ի�������
	enum { IDD = IDD_INFO_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedIDOk();
private:
    CString m_strName;
    CString m_strSex;
    int m_iAge;
};
