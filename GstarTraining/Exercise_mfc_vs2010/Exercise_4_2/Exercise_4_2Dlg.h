
// Exercise_4_2Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CExercise_4_2Dlg �Ի���
class CExercise_4_2Dlg : public CDialogEx
{
// ����
public:
	CExercise_4_2Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXERCISE_4_2_DIALOG };

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
    CComboBox m_Combo;

private:
    void SetFontAndFontName(int iCtrlId, LPCTSTR szFontName);
public:
    afx_msg void OnCbnSelchangeCombo();
};
