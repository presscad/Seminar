
// Exercise_2_3Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CExercise_2_3Dlg �Ի���
class CExercise_2_3Dlg : public CDialogEx
{
// ����
public:
	CExercise_2_3Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXERCISE_2_3_DIALOG };

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
    afx_msg void OnBnClickedSetfontBtn();

private:
    CFont m_Font;
    CString m_strFontName;
    COLORREF m_clr;
    CBrush m_clrBrush;
    CStatic m_ResultCtl;
public:
    afx_msg void OnBnClickedSetclrBtn();
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
