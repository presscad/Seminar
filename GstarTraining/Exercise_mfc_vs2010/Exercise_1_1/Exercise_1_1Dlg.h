
// Exercise_1_1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CExercise_1_1Dlg �Ի���
class CExercise_1_1Dlg : public CDialogEx
{
// ����
public:
	CExercise_1_1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXERCISE_1_1_DIALOG };

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
	afx_msg void OnEnChangeTxt1Edt();
private:
	CEdit m_txt1; //Edit Control 1
	CEdit m_txt2; //Edit Control 2
public:
	afx_msg void OnEnChangeTxt2Edt();
};
