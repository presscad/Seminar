// ImageViewerDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "ImgView.h"


// CImageViewerDlg �Ի���
class CImageViewerDlg : public CDialog
{
// ����
public:
	CImageViewerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_IMAGEVIEWER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
    HACCEL m_hAccel;
    CListCtrl m_listPreview;
    CImageList m_imageList;
    CImgView m_staticView;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    afx_msg void OnOpen();
    afx_msg void OnLvnItemchangedListPreview(NMHDR *pNMHDR, LRESULT *pResult);
};
