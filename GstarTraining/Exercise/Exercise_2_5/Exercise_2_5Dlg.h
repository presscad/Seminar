
// Exercise_2_5Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"

struct PersonInfo
{
    CString strName;
    CString strSex;
    int iAge;
};


// CExercise_2_5Dlg �Ի���
class CExercise_2_5Dlg : public CDialogEx
{
// ����
public:
	CExercise_2_5Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXERCISE_2_5_DIALOG };

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
    CTreeCtrl m_treeInfo;
    PersonInfo personInfo[2];
public:
    afx_msg void OnNMClickInfoTree(NMHDR *pNMHDR, LRESULT *pResult);
};
