
// Exercise_4_4Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CExercise_4_4Dlg �Ի���
class CExercise_4_4Dlg : public CDialogEx
{
// ����
public:
	CExercise_4_4Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXERCISE_4_4_DIALOG };

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
    CListCtrl m_LV;

private:
    BOOL QueryData();
public:
    afx_msg void OnBnClickedAddBtn();
    afx_msg void OnBnClickedRemoveBtn();
};
