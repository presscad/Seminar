
// Exercise_3_3Dlg.h : ͷ�ļ�
//

#pragma once


// CExercise_3_3Dlg �Ի���
class CExercise_3_3Dlg : public CDialogEx
{
// ����
public:
	CExercise_3_3Dlg(CWnd* pParent = NULL);	// ��׼���캯��
    ~CExercise_3_3Dlg();

// �Ի�������
	enum { IDD = IDD_EXERCISE_3_3_DIALOG };

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
private:
    HBITMAP m_hBitmap;
    int m_cx, m_cy;
    int m_cxBmp, m_cyBmp;
private:
    BOOL SaveBitmapToFile(HBITMAP hBitmap, LPCTSTR lpszFileName);
};
