
// Exercise_3_6Dlg.h : ͷ�ļ�
//

#pragma once


// CExercise_3_6Dlg �Ի���
class CExercise_3_6Dlg : public CDialogEx
{
// ����
public:
	CExercise_3_6Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXERCISE_3_6_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
    afx_msg LRESULT OnNotifyIcon(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

private:
    NOTIFYICONDATA m_nid;
public:
    afx_msg void OnDestroy();
    afx_msg void OnShow();
    afx_msg void OnExit();
    afx_msg void OnBnClickedOk();
};
