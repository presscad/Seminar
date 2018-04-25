
// Exercise_2_2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Exercise_2_2.h"
#include "Exercise_2_2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise_2_2Dlg �Ի���




CExercise_2_2Dlg::CExercise_2_2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExercise_2_2Dlg::IDD, pParent)
    , m_iSpeed(30), m_hbrCtl(RGB(0,0,0))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

    //��ʼ��RGBֵ
    for (int i = 0; i < 3; ++i)
        m_iColor[i] = 0;
}

void CExercise_2_2Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExercise_2_2Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_WM_HSCROLL()
    ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CExercise_2_2Dlg ��Ϣ�������

BOOL CExercise_2_2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    ((CScrollBar*) GetDlgItem(IDC_R_SCRBAR))->SetScrollRange(0, 255);
    ((CScrollBar*) GetDlgItem(IDC_G_SCRBAR))->SetScrollRange(0, 255);
    ((CScrollBar*) GetDlgItem(IDC_B_SCRBAR))->SetScrollRange(0, 255);

    CSliderCtrl *pSlider = (CSliderCtrl*) GetDlgItem(IDC_SPEED_SLIDER);
    pSlider->SetRange(1,100);
    pSlider->SetPos(m_iSpeed);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CExercise_2_2Dlg::OnPaint()
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
HCURSOR CExercise_2_2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CExercise_2_2Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    if (pScrollBar->GetDlgCtrlID() == IDC_SPEED_SLIDER) {
        m_iSpeed = ((CSliderCtrl*) pScrollBar)->GetPos();
        this->SetDlgItemInt(IDC_SPEEDVAL_STATIC, m_iSpeed, FALSE);
    }
    else {
        int i = pScrollBar->GetDlgCtrlID() - IDC_R_SCRBAR;
        switch (nSBCode) {
        case SB_LINELEFT: m_iColor[i] -= 1; break;
        case SB_LINERIGHT: m_iColor[i] += 1; break;
        case SB_PAGELEFT: m_iColor[i] -= m_iSpeed; break;
        case SB_PAGERIGHT: m_iColor[i] += m_iSpeed; break;
        case SB_LEFT: m_iColor[i] = 0; break;
        case SB_RIGHT: m_iColor[i] = 255; break;

        case SB_THUMBPOSITION:
        case SB_THUMBTRACK:
            m_iColor[i] = nPos;
            break;

        default:
            break;
        }

        m_iColor[i] = max(0, min(m_iColor[i], 255));
        pScrollBar->SetScrollPos(m_iColor[i]);
        this->SetDlgItemInt(i + IDC_RVAL_STATIC, m_iColor[i], FALSE);
        GetDlgItem(IDC_CTL_STATIC)->InvalidateRect(NULL);
    }

    CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

HBRUSH CExercise_2_2Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

    // TODO:  �ڴ˸��� DC ���κ�����

    // TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
    if (pWnd->GetDlgCtrlID() == IDC_CTL_STATIC) {
        m_hbrCtl.DeleteObject();
        m_hbrCtl.CreateSolidBrush(RGB(m_iColor[0], m_iColor[1], m_iColor[2]));
        return (HBRUSH) m_hbrCtl.GetSafeHandle();
    }

    return hbr;
}
