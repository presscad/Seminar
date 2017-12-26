
// Exercise_4_2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Exercise_4_2.h"
#include "Exercise_4_2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise_4_2Dlg �Ի���

int CALLBACK EnumFontFamExProc(
    const LOGFONT    *lpelfe,
    const TEXTMETRIC *lpntme,
    DWORD      FontType,
    LPARAM     lParam
    );


CExercise_4_2Dlg::CExercise_4_2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExercise_4_2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExercise_4_2Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO, m_Combo);
}

BEGIN_MESSAGE_MAP(CExercise_4_2Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_CBN_SELCHANGE(IDC_COMBO, &CExercise_4_2Dlg::OnCbnSelchangeCombo)
END_MESSAGE_MAP()


// CExercise_4_2Dlg ��Ϣ�������

BOOL CExercise_4_2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    HDC hdc = ::GetDC(GetSafeHwnd());
    LOGFONT lf = {0};
    lf.lfCharSet = DEFAULT_CHARSET;


    ::EnumFontFamiliesEx(hdc, &lf, EnumFontFamExProc, (LPARAM) &m_Combo, 0);

    ::ReleaseDC(GetSafeHwnd(), hdc);

    m_Combo.SetCurSel(0);
    CString strBuf;
    m_Combo.GetLBText(0, strBuf);
    SetFontAndFontName(IDC_SHOW_STATIC, strBuf);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CExercise_4_2Dlg::OnPaint()
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
HCURSOR CExercise_4_2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CExercise_4_2Dlg::SetFontAndFontName(int iCtrlId, LPCTSTR szFontName)
{
    CWnd *pCtrl = GetDlgItem(iCtrlId);
    ASSERT(pCtrl);

    LOGFONT lf = {0};
    CFont newFont;
    CFont *pFont = pCtrl->GetFont();
    pFont->GetLogFont(&lf);
    _tcscpy(lf.lfFaceName, szFontName);
    newFont.CreateFontIndirect(&lf);
    pCtrl->SetFont(&newFont);
    pCtrl->SetWindowText(szFontName);
}

int CALLBACK EnumFontFamExProc(const LOGFONT *lpelfe, const TEXTMETRIC *lpntme, DWORD FontType, LPARAM  lParam)
{
    CComboBox *pCombo = (CComboBox *) lParam;
    pCombo->AddString(lpelfe->lfFaceName);

    return TRUE;
}



void CExercise_4_2Dlg::OnCbnSelchangeCombo()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CString strBuf;
    m_Combo.GetLBText(m_Combo.GetCurSel(), strBuf);
    SetFontAndFontName(IDC_SHOW_STATIC, strBuf);
}
