
// Exercise_5_1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Exercise_5_1.h"
#include "Exercise_5_1Dlg.h"
#include "afxdialogex.h"
#include <locale.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise_5_1Dlg �Ի���

#ifdef _UNICODE
#define CF_TCHARTEXT CF_UNICODETEXT
#else
#define CF_TCHARTEXT CF_TEXT
#endif



CExercise_5_1Dlg::CExercise_5_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExercise_5_1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExercise_5_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExercise_5_1Dlg, CDialogEx)
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_LOAD_BTN, &CExercise_5_1Dlg::OnBnClickedLoadBtn)
    ON_BN_CLICKED(IDC_SAVE_BTN, &CExercise_5_1Dlg::OnBnClickedSaveBtn)
    ON_COMMAND_RANGE(ID_FILE_LOAD1, ID_EDIT_SELECTALL1, &CExercise_5_1Dlg::OnPopupMenuClicked)
    ON_WM_INITMENUPOPUP()
    ON_WM_SETFOCUS()
END_MESSAGE_MAP()


// CExercise_5_1Dlg ��Ϣ�������

BOOL CExercise_5_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    CMenu menu;
    menu.LoadMenu(IDR_MENU);
    SetMenu(&menu);
    
    m_hAccel = LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_ACCELERATOR));

	return FALSE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CExercise_5_1Dlg::OnPaint()
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
HCURSOR CExercise_5_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExercise_5_1Dlg::OnBnClickedLoadBtn()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    setlocale(LC_CTYPE, "chs");
    CFileDialog fileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
        _T("�ı��ļ�(*.txt)|*.txt||"), this);
    TCHAR *pBuf = NULL;
    if (IDOK == fileDlg.DoModal()) {
        try {
            CFile file(fileDlg.GetPathName(), CFile::modeRead);
            int len = (int) file.GetLength();
            pBuf = new TCHAR[(len+1)*sizeof(TCHAR)];
            memset(pBuf, 0, (len+1)*sizeof(TCHAR));
            pBuf[file.Read(pBuf, len)] = _T('\0');
        }
        catch (CFileException &e) {
            TRACE(_T("File count not be opened, cause = %d\n"), e.m_cause);
        }

        SetDlgItemText(IDC_EDIT, pBuf);
        delete[] pBuf;
    }
}


void CExercise_5_1Dlg::OnBnClickedSaveBtn()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    setlocale(LC_CTYPE, "chs");

    CFileDialog fileDlg(FALSE, NULL, _T("δ����.txt"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
        _T("�ı��ļ�(*.txt)|*.txt||"), this);

    CString strBuf;
    GetDlgItemText(IDC_EDIT, strBuf);

    if (IDOK == fileDlg.DoModal()) {
        try {
            CFile file(fileDlg.GetPathName(), CFile::modeCreate | CFile::modeWrite);
            #ifdef _UNICODE
            WORD unicode = 0xFEFF;
            file.Write(&unicode, 2);
            #endif
            file.Write((LPCTSTR) strBuf, strBuf.GetLength()*sizeof(TCHAR));
        }
        catch (CFileException &e) {
            TRACE(_T("File count not be opened, cause = %d\n"), e.m_cause);
        }
    }
}

void CExercise_5_1Dlg::OnPopupMenuClicked(UINT uId)
{
    CEdit *pEdt = (CEdit*) GetDlgItem(IDC_EDIT);
    switch (uId) {
        case ID_FILE_LOAD1: OnBnClickedLoadBtn(); break;
        case ID_FILE_SAVE1: OnBnClickedSaveBtn(); break;
        case ID_FILE_EXIT1: OnOK(); break;
        case ID_EDIT_UNDO1: pEdt->Undo(); break;
        case ID_EDIT_CUT1: pEdt->Cut(); break;
        case ID_EDIT_COPY1: pEdt->Copy(); break;
        case ID_EDIT_PASTE1: pEdt->Paste(); break;
        case ID_EDIT_SELECTALL1: pEdt->SetSel(0, -1); break;
        case ID_HELP_ABOUT1: MessageBox(_T("���׼��±����� v1.0")); break;
        default: break;
    }
}

void CExercise_5_1Dlg::OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu)
{
    CDialogEx::OnInitMenuPopup(pPopupMenu, nIndex, bSysMenu);

    // TODO: �ڴ˴������Ϣ����������
    CEdit *pEdit = (CEdit*) GetDlgItem(IDC_EDIT);
    switch (nIndex) {
    case 1:
        {
            pPopupMenu->EnableMenuItem(ID_EDIT_UNDO1,
                pEdit->CanUndo() ? MF_ENABLED : MF_GRAYED);

            int iSelBeg, iSelEnd;
            pEdit->GetSel(iSelBeg, iSelEnd);
            int iState = iSelBeg == iSelEnd ? MF_GRAYED : MF_ENABLED;

            pPopupMenu->EnableMenuItem(ID_EDIT_CUT1, iState);
            pPopupMenu->EnableMenuItem(ID_EDIT_COPY1, iState);

            pPopupMenu->EnableMenuItem(ID_EDIT_PASTE1,
                IsClipboardFormatAvailable(CF_TCHARTEXT) ? MF_ENABLED : MF_GRAYED);
        }
        break;

    default:
        break;
    }
}

BOOL CExercise_5_1Dlg::PreTranslateMessage(MSG* pMsg)
{
    // TODO: �ڴ����ר�ô����/����û���
    if (TranslateAccelerator(GetSafeHwnd(), (HACCEL) m_hAccel, pMsg))
        return TRUE;

    return CDialogEx::PreTranslateMessage(pMsg);
}


void CExercise_5_1Dlg::OnSetFocus(CWnd* pOldWnd)
{
    CDialogEx::OnSetFocus(pOldWnd);

    // TODO: �ڴ˴������Ϣ����������
    GetDlgItem(IDC_EDIT)->SetFocus();
}
