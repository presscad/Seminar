
// Exercise_3_1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CExercise_3_1Dlg �Ի���
class CExercise_3_1Dlg : public CDialogEx
{
// ����
public:
	CExercise_3_1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXERCISE_3_1_DIALOG };

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
private:
    CProgressCtrl m_process;
    int m_iPos;
public:
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    afx_msg void OnDestroy();
};
