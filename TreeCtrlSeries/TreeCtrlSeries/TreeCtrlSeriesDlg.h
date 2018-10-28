// TreeCtrlSeriesDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CTreeCtrlSeriesDlg �Ի���
class CTreeCtrlSeriesDlg : public CDialog
{
// ����
public:
	CTreeCtrlSeriesDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TREECTRLSERIES_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
    CImageList m_imgList;
    CTreeCtrl m_tree;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedBtnSave();
};
