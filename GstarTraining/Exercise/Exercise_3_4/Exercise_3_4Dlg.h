
// Exercise_3_4Dlg.h : ͷ�ļ�
//

#pragma once


// CExercise_3_4Dlg �Ի���
class CExercise_3_4Dlg : public CDialogEx
{
// ����
public:
	CExercise_3_4Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXERCISE_3_4_DIALOG };

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
    CString m_strText;
public:
    afx_msg void OnBnClickedSortBtn();

private:
    void SplitStringToDoubleArray(LPCTSTR szSrc, LPCTSTR szDelim, CArray<double> &dArray);
    void SortDoubleArray(CArray<double> &dArray);
};
