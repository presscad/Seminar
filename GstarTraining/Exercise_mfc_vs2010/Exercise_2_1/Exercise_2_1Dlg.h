
// Exercise_2_1Dlg.h : ͷ�ļ�
//

#pragma once


// CExercise_2_1Dlg �Ի���
class CExercise_2_1Dlg : public CDialogEx
{
// ����
public:
	CExercise_2_1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXERCISE_2_1_DIALOG };

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
    int m_iOper;
    double m_dVal1;
    double m_dVal2;
    double m_dResult;
public:
    afx_msg void OnBnClickedCalcBtn();
    virtual void OnOK();
};
