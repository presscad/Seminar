
// Exercise_3_2Dlg.h : ͷ�ļ�
//

#pragma once


// CExercise_3_2Dlg �Ի���
class CExercise_3_2Dlg : public CDialogEx
{
// ����
public:
	CExercise_3_2Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXERCISE_3_2_DIALOG };

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
    void FormatString(ULONGLONG ullNumber, CString &strResult);
};
