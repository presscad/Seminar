
// Exercise_3_8Dlg.h : ͷ�ļ�
//

#pragma once


// CExercise_3_8Dlg �Ի���
class CExercise_3_8Dlg : public CDialogEx
{
// ����
public:
	CExercise_3_8Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXERCISE_3_8_DIALOG };

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
    CWinThread *m_thread[3];
    int m_nId[3];
    int m_iThreadIndex;
    static ULONG m_ulData;
    static CMutex m_mutex;
    static BOOL m_bDestroy;

private:
    static UINT ThreadFun(LPVOID pParam);
public:
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    afx_msg LRESULT OnUpdateValue(WPARAM wParam, LPARAM lParam);
    afx_msg void OnDestroy();
};
