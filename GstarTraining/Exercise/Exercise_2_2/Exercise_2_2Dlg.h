
// Exercise_2_2Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CExercise_2_2Dlg �Ի���
class CExercise_2_2Dlg : public CDialogEx
{
// ����
public:
	CExercise_2_2Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXERCISE_2_2_DIALOG };

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
    afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
private:
    int m_iSpeed;
    int m_iColor[3];
    CBrush m_hbrCtl;
};
