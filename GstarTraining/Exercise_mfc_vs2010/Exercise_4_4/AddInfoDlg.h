#pragma once

class CExercise_4_4Dlg;
// CAddInfoDlg �Ի���

class CAddInfoDlg : public CDialogEx
{
    friend CExercise_4_4Dlg;
	DECLARE_DYNAMIC(CAddInfoDlg)

public:
	CAddInfoDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddInfoDlg();

// �Ի�������
	enum { IDD = IDD_ADDINFO_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnInitDialog();
private:
    CString m_strName;
    CString m_strSex;
    CString m_strAge;
    CString m_strAddr;
public:
    afx_msg void OnBnClickedOk();
   
};
