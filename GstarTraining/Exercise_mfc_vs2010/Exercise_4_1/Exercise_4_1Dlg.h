
// Exercise_4_1Dlg.h : ͷ�ļ�
//

#pragma once
#include "colorlistbox.h"


// CExercise_4_1Dlg �Ի���
class CExercise_4_1Dlg : public CDialogEx
{
// ����
public:
	CExercise_4_1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXERCISE_4_1_DIALOG };

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
    CColorListBox m_listbox;
};
