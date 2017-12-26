
// Exercise_1_3Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CExercise_1_3Dlg �Ի���
class CExercise_1_3Dlg : public CDialogEx
{
// ����
public:
	CExercise_1_3Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXERCISE_1_3_DIALOG };

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
	CStatic m_CurItem;
	CComboBox m_Catalog;
	CListBox m_List;
    CArray<CString> m_ArrayFruit;
    CArray<CString> m_ArrayStudyMaterial;
private:
    void InitData();
public:
    afx_msg void OnCbnSelchangeCatalogCombo();
    afx_msg void OnLbnSelchangeListList();
};
