
// Exercise_2_6Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CExercise_2_6Dlg �Ի���
class CExercise_2_6Dlg : public CDialogEx
{
// ����
public:
	CExercise_2_6Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXERCISE_2_6_DIALOG };

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
    CListCtrl m_lvInfo;
};
