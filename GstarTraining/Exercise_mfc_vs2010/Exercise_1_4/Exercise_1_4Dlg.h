
// Exercise_1_4Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CExercise_1_4Dlg �Ի���
class CExercise_1_4Dlg : public CDialogEx
{
// ����
public:
	CExercise_1_4Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXERCISE_1_4_DIALOG };

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
    int m_iRadio;
    afx_msg void OnCheckRadioButton(UINT uId);
};
