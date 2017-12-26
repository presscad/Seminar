
// Exercise_3_4Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Exercise_3_4.h"
#include "Exercise_3_4Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise_3_4Dlg �Ի���




CExercise_3_4Dlg::CExercise_3_4Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExercise_3_4Dlg::IDD, pParent)
    , m_strText(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExercise_3_4Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDT, m_strText);
}

BEGIN_MESSAGE_MAP(CExercise_3_4Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_SORT_BTN, &CExercise_3_4Dlg::OnBnClickedSortBtn)
END_MESSAGE_MAP()


// CExercise_3_4Dlg ��Ϣ�������

BOOL CExercise_3_4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CExercise_3_4Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CExercise_3_4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CExercise_3_4Dlg::OnBnClickedSortBtn()
{
    UpdateData(TRUE);
    CArray<double> dArray;
    SplitStringToDoubleArray(m_strText, _T(" "), dArray);
    SortDoubleArray(dArray);

    m_strText.Empty();
    CString strBuf;
    int count = dArray.GetCount();
    for (int i = 0; i < count; ++i) {
        if (i <= count)
            strBuf.Format(_T("%f "), dArray[i]); 
        else
            strBuf.Format(_T("%f"), dArray[i]);

        m_strText += strBuf;
    }
    UpdateData(FALSE);
}

void CExercise_3_4Dlg::SplitStringToDoubleArray(LPCTSTR szSrc, LPCTSTR szDelim, CArray<double> &dArray)
{
    TCHAR *szBuf = new TCHAR[_tcslen(szSrc) + 1];
    _tcscpy(szBuf, szSrc);
    TCHAR *ptr = _tcstok(szBuf, szDelim);
    dArray.RemoveAll();
    while (ptr) {
        dArray.Add(_ttof(ptr));
        ptr = _tcstok(NULL, szDelim);
    }

    delete[] szBuf;
}

void CExercise_3_4Dlg::SortDoubleArray(CArray<double> &dArray)
{
    int i = 0, j = 0, count = dArray.GetCount();
    double temp;
    for (j = 0; j < count -1; ++j)
        for (i = 0; i < count - j - 1; ++i)
            if (dArray[i] > dArray[i + 1]) {
                temp = dArray[i], dArray[i] = dArray[i + 1],
                    dArray[i + 1] = temp;
            }
}
