
// Exercise_1_2Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CExercise_1_2Dlg �Ի���
class CExercise_1_2Dlg : public CDialogEx
{
// ����
public:
	CExercise_1_2Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_Exercise_1_2_DIALOG };

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
	afx_msg void OnBnClickedAddBtn();
	afx_msg void OnBnClickedRemoveBtn();
	afx_msg void OnBnClickedAddallBtn();
	afx_msg void OnBnClickedClearBtn();
private:
	CListBox m_StuInfoField;
	CListBox m_ReportField;
};
