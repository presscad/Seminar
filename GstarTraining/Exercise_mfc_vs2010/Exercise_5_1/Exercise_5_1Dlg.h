
// Exercise_5_1Dlg.h : ͷ�ļ�
//

#pragma once


// CExercise_5_1Dlg �Ի���
class CExercise_5_1Dlg : public CDialogEx
{
// ����
public:
	CExercise_5_1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXERCISE_5_1_DIALOG };

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
    afx_msg void OnBnClickedLoadBtn();
    afx_msg void OnBnClickedSaveBtn();
    afx_msg void OnPopupMenuClicked(UINT uId);
    afx_msg void OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu);
    afx_msg void OnSetFocus(CWnd* pOldWnd);

private:
    HANDLE m_hAccel;

public:
    virtual BOOL PreTranslateMessage(MSG* pMsg);
};
