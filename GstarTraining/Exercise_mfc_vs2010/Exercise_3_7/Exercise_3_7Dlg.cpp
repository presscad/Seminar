
// Exercise_3_7Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Exercise_3_7.h"
#include "Exercise_3_7Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise_3_7Dlg �Ի���




CExercise_3_7Dlg::CExercise_3_7Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExercise_3_7Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExercise_3_7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExercise_3_7Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_INSTALL_BTN, &CExercise_3_7Dlg::OnBnClickedInstallBtn)
    ON_BN_CLICKED(IDC_UNINSTALL_BTN, &CExercise_3_7Dlg::OnBnClickedUninstallBtn)
END_MESSAGE_MAP()


// CExercise_3_7Dlg ��Ϣ�������

BOOL CExercise_3_7Dlg::OnInitDialog()
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

void CExercise_3_7Dlg::OnPaint()
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
HCURSOR CExercise_3_7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExercise_3_7Dlg::OnBnClickedInstallBtn()
{
    HKEY hKey;
    int iRet;
    TCHAR szThisFileName[MAX_PATH];
    do {
        iRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
            _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"),
            0, KEY_WRITE, &hKey);
        if (ERROR_SUCCESS != iRet) {
            AfxMessageBox(_T("��ע���Run��ʧ�ܣ�"), MB_ICONERROR);
            break;
        }

        iRet = RegSetValueEx(hKey, _T("Exercise_3_7"), 0, REG_SZ,
            (const BYTE*) szThisFileName,
            GetModuleFileName(NULL, szThisFileName, MAX_PATH)*sizeof(TCHAR));
        if (ERROR_SUCCESS != iRet) {
            AfxMessageBox(_T("����Exercise_3_7������ʧ�ܣ�"), MB_ICONERROR);
            break;
        }

        AfxMessageBox(_T("Exercise_3_7�����װ�ɹ���"));
    } while (FALSE);

    RegCloseKey(hKey);
}


void CExercise_3_7Dlg::OnBnClickedUninstallBtn()
{
    int iRet;
    HKEY hKey;
    do {
        iRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
            _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"),
            0, KEY_QUERY_VALUE | KEY_WRITE, &hKey);
        if (ERROR_SUCCESS != iRet) {
            AfxMessageBox(_T("��ע���Run��ʧ�ܣ�"), MB_ICONERROR);
            break;
        }

        DWORD dwData, dwType;
        iRet = RegQueryValueEx(hKey, _T("Exercise_3_7"), 0, &dwType, NULL, &dwData);
        if (ERROR_SUCCESS != iRet) {
            AfxMessageBox(_T("Exercise_3_7��������ڣ�����ж�أ�"));
            break;
        }

        iRet = RegDeleteValue(hKey, _T("Exercise_3_7"));
        if (ERROR_SUCCESS == iRet)
            AfxMessageBox(_T("Exercise_3_7������ж�سɹ���"));
        else
            AfxMessageBox(_T("Exercise_3_7������ж��ʧ�ܣ�"), MB_ICONERROR);

    } while (FALSE);

    RegCloseKey(hKey);
    
    //iRet = RegDeleteKeyValue(HKEY_LOCAL_MACHINE,
    //    _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"),
    //    _T("Exercise_3_7"));
}
