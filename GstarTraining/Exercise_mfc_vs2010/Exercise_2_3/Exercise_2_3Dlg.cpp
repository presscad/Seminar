
// Exercise_2_3Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Exercise_2_3.h"
#include "Exercise_2_3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise_2_3Dlg �Ի���




CExercise_2_3Dlg::CExercise_2_3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExercise_2_3Dlg::IDD, pParent)
    , m_strFontName(_T("����")), m_clr(RGB(0,0,0)), m_clrBrush(m_clr)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExercise_2_3Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_FONTNAME_STATIC, m_strFontName);
    DDX_Control(pDX, IDC_RESULT_STATIC, m_ResultCtl);
}

BEGIN_MESSAGE_MAP(CExercise_2_3Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_SETFONT_BTN, &CExercise_2_3Dlg::OnBnClickedSetfontBtn)
    ON_BN_CLICKED(IDC_SETCLR_BTN, &CExercise_2_3Dlg::OnBnClickedSetclrBtn)
    ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CExercise_2_3Dlg ��Ϣ�������

BOOL CExercise_2_3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    CFont *pFont = m_ResultCtl.GetFont();
    LOGFONT lf;
    pFont->GetLogFont(&lf);
    _tcscpy(lf.lfFaceName, m_strFontName);
    m_Font.CreateFontIndirect(&lf);
    m_ResultCtl.SetFont(&m_Font);


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CExercise_2_3Dlg::OnPaint()
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
HCURSOR CExercise_2_3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExercise_2_3Dlg::OnBnClickedSetfontBtn()
{
    LOGFONT lf;
    m_Font.GetLogFont(&lf);
    CFontDialog fontDlg(&lf);
    fontDlg.m_cf.rgbColors = m_clr;
    
    if (IDOK == fontDlg.DoModal()) {
        //����
        m_Font.DeleteObject();
        m_Font.CreateFontIndirect(fontDlg.m_cf.lpLogFont);
        m_strFontName = fontDlg.m_cf.lpLogFont->lfFaceName;
        m_ResultCtl.SetFont(&m_Font);
        UpdateData(FALSE);

        //��ɫ
        m_clr = fontDlg.GetColor();
        m_clrBrush.DeleteObject();
        m_clrBrush.CreateSolidBrush(m_clr);
        
        m_ResultCtl.Invalidate();
        GetDlgItem(IDC_CLR_STATIC)->Invalidate();
    }
}


void CExercise_2_3Dlg::OnBnClickedSetclrBtn()
{
    CColorDialog clrDlg(m_clr);
    if (IDOK == clrDlg.DoModal()) {
        m_clr = clrDlg.m_cc.rgbResult;
        m_clrBrush.DeleteObject();
        m_clrBrush.CreateSolidBrush(m_clr);
        m_ResultCtl.Invalidate();
        GetDlgItem(IDC_CLR_STATIC)->Invalidate();
    }
}


HBRUSH CExercise_2_3Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

    // TODO:  �ڴ˸��� DC ���κ�����

    // TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
    switch (pWnd->GetDlgCtrlID()) {
    case IDC_CLR_STATIC:
        hbr = (HBRUSH) m_clrBrush.GetSafeHandle();
        break;
    case IDC_RESULT_STATIC:
        pDC->SetTextColor(m_clr);
    default:
        break;
    }

    return hbr;
}
