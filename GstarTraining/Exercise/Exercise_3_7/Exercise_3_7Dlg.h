
// Exercise_3_7Dlg.h : ͷ�ļ�
//

#pragma once


// CExercise_3_7Dlg �Ի���
class CExercise_3_7Dlg : public CDialogEx
{
// ����
public:
	CExercise_3_7Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXERCISE_3_7_DIALOG };

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
    afx_msg void OnBnClickedInstallBtn();
    afx_msg void OnBnClickedUninstallBtn();
    
};
