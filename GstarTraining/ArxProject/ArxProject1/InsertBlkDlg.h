#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "staticex.h"

class CArxProject1App;
// CInsertBlkDlg �Ի���

class CInsertBlkDlg : public CDialogEx
{
    friend CArxProject1App;

	DECLARE_DYNAMIC(CInsertBlkDlg)

public:
	CInsertBlkDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInsertBlkDlg();

// �Ի�������
	enum { IDD = IDD_INSERT_BLK_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
    CComboBox m_comboBlkName;
    CListCtrl m_listAttr;
    CEdit m_editValue;
    AcDbObjectId m_blkDefId;  //�鶨���Id
    CArray<CArxProjectHelper::BlockAttribute> m_aBlkAttr;
    HBITMAP m_hBmp;
public:
    virtual BOOL OnInitDialog();
    afx_msg void OnCbnSelchangeComboBlkname();
    afx_msg void OnLvnItemchangedListAttr(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnEnChangeEditValue();
    afx_msg void OnBnClickedOk();
private:
    CStaticEx m_pic;
};
