
// Exercise_2_4Dlg.h : ͷ�ļ�
//

#pragma once


// CExercise_2_4Dlg �Ի���
class CExercise_2_4Dlg : public CDialogEx
{
// ����
public:
	CExercise_2_4Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXERCISE_2_4_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedShowBtn();

private:
    void SplitString(LPCTSTR szSrc, LPCTSTR szDelim, CStringArray &strArray);

private:
    CString m_strName;
    CString m_strSex;
    int m_iAge;
};
