
// Exercise_3_3Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Exercise_3_3.h"
#include "Exercise_3_3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise_3_3Dlg �Ի���




CExercise_3_3Dlg::CExercise_3_3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExercise_3_3Dlg::IDD, pParent)
    , m_hBitmap(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CExercise_3_3Dlg::~CExercise_3_3Dlg()
{
    BOOL bRet = DeleteObject(m_hBitmap);
}

void CExercise_3_3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExercise_3_3Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_LOAD_BTN, &CExercise_3_3Dlg::OnBnClickedLoadBtn)
    ON_BN_CLICKED(IDC_SAVE_BTN, &CExercise_3_3Dlg::OnBnClickedSaveBtn)
END_MESSAGE_MAP()


// CExercise_3_3Dlg ��Ϣ�������

BOOL CExercise_3_3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    CRect rcClient;
    GetClientRect(rcClient);
    m_cx = rcClient.right - 120, m_cy = rcClient.bottom - 30;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CExercise_3_3Dlg::OnPaint()
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

    CDC *pDC = GetDC();
    CDC menDC;
    menDC.CreateCompatibleDC(pDC);
    menDC.SelectObject((HGDIOBJ) m_hBitmap);
    pDC->StretchBlt(0, 0, m_cx, m_cy, &menDC, 0, 0, m_cxBmp, m_cyBmp, SRCCOPY);
    ReleaseDC(pDC);
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CExercise_3_3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExercise_3_3Dlg::OnBnClickedLoadBtn()
{
    CFileDialog fileDialog(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
        _T("λͼ�ļ�(*.bmp)|*.bmp||"), this);
    if (IDOK == fileDialog.DoModal()) {

        if (m_hBitmap)
            DeleteObject(m_hBitmap); //�ظ�����ʱ���ͷ�֮ǰ����Դ

        do {
            m_hBitmap = (HBITMAP) LoadImage(AfxGetInstanceHandle(), fileDialog.GetPathName(),
                IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE|LR_CREATEDIBSECTION);

            if (!m_hBitmap) {
                MessageBox(_T("��λͼ���𻵣��޷�������ʾ��"));
                break;
            }

            BITMAP bmp;
            ::GetObject((HANDLE) m_hBitmap, sizeof(BITMAP), (LPVOID) &bmp);
            m_cxBmp = bmp.bmWidth, m_cyBmp = bmp.bmHeight;

        } while (FALSE);

        Invalidate();
    }
}


void CExercise_3_3Dlg::OnBnClickedSaveBtn()
{
    if (!m_hBitmap) {
        MessageBox(_T("��ǰ��λͼ�ļ��ɱ��棡"));
        return;
    }

    CFileDialog fileDialog(FALSE, NULL, _T("λͼ.bmp"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
        _T("λͼ�ļ�(*.bmp)|*.bmp||"), this);

    if (IDOK == fileDialog.DoModal()) {
        SaveBitmapToFile(m_hBitmap, fileDialog.GetPathName());
    }
}


BOOL CExercise_3_3Dlg::SaveBitmapToFile(HBITMAP hBitmap, LPCTSTR lpszFileName)  
{  
    HDC     hDC;           
    //��ǰ�ֱ�����ÿ������ռ�ֽ���            
    int     iBits;           
    //λͼ��ÿ������ռ�ֽ���            
    WORD     wBitCount;           
    //�����ɫ���С��     λͼ�������ֽڴ�С     ��λͼ�ļ���С     ��     д���ļ��ֽ���                
    DWORD     dwPaletteSize=0,   dwBmBitsSize=0,   dwDIBSize=0,   dwWritten=0;               
    //λͼ���Խṹ                
    BITMAP     Bitmap;                   
    //λͼ�ļ�ͷ�ṹ            
    BITMAPFILEHEADER     bmfHdr;                   
    //λͼ��Ϣͷ�ṹ                
    BITMAPINFOHEADER     bi;                   
    //ָ��λͼ��Ϣͷ�ṹ                    
    LPBITMAPINFOHEADER     lpbi;                   
    //�����ļ��������ڴ�������ɫ����                
    HANDLE     fh,   hDib,   hPal,hOldPal=NULL;               

    //����λͼ�ļ�ÿ��������ռ�ֽ���                
    hDC  = CreateDC(_T("DISPLAY"),   NULL,   NULL,   NULL);           
    iBits  = GetDeviceCaps(hDC,   BITSPIXEL)     *     GetDeviceCaps(hDC,   PLANES);               
    DeleteDC(hDC);               
    if(iBits <=  1)                                                     
        wBitCount = 1;               
    else  if(iBits <=  4)                                 
        wBitCount  = 4;               
    else if(iBits <=  8)                                 
        wBitCount  = 8;               
    else                                                                                                                                 
        wBitCount  = 24;  

    GetObject(hBitmap,   sizeof(Bitmap),   (LPSTR)&Bitmap);           
    bi.biSize= sizeof(BITMAPINFOHEADER);           
    bi.biWidth = Bitmap.bmWidth;           
    bi.biHeight =  Bitmap.bmHeight;           
    bi.biPlanes =  1;           
    bi.biBitCount = wBitCount;           
    bi.biCompression= BI_RGB;           
    bi.biSizeImage=0;           
    bi.biXPelsPerMeter = 0;           
    bi.biYPelsPerMeter = 0;           
    bi.biClrImportant = 0;           
    bi.biClrUsed =  0;           

    dwBmBitsSize  = ((Bitmap.bmWidth *wBitCount+31) / 32)*4* Bitmap.bmHeight;           

    //Ϊλͼ���ݷ����ڴ�                
    hDib  = GlobalAlloc(GHND,dwBmBitsSize+dwPaletteSize+sizeof(BITMAPINFOHEADER));               
    lpbi  = (LPBITMAPINFOHEADER)GlobalLock(hDib);               
    *lpbi  = bi;               

    //     �����ɫ��                    
    hPal  = GetStockObject(DEFAULT_PALETTE);               
    if (hPal)               
    {               
        hDC  = ::GetDC(NULL);               
        hOldPal = ::SelectPalette(hDC,(HPALETTE)hPal, FALSE);               
        RealizePalette(hDC);               
    }           

    //     ��ȡ�õ�ɫ�����µ�����ֵ                
    GetDIBits(hDC,hBitmap, 0,(UINT)Bitmap.bmHeight,    
        (LPSTR)lpbi+ sizeof(BITMAPINFOHEADER)+dwPaletteSize,     
        (BITMAPINFO *)lpbi, DIB_RGB_COLORS);               

    //�ָ���ɫ��                    
    if (hOldPal)               
    {               
        ::SelectPalette(hDC,   (HPALETTE)hOldPal,   TRUE);               
        RealizePalette(hDC);               
        ::ReleaseDC(NULL,   hDC);               
    }               

    //����λͼ�ļ�                    
    fh  = CreateFile(lpszFileName,   GENERIC_WRITE,0,   NULL,   CREATE_ALWAYS,             
        FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN,   NULL);               

    if (fh     ==  INVALID_HANDLE_VALUE)         return     FALSE;               

    //     ����λͼ�ļ�ͷ                
    bmfHdr.bfType  = 0x4D42;     //     "BM"                
    dwDIBSize  = sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+dwPaletteSize+dwBmBitsSize;                   
    bmfHdr.bfSize  = dwDIBSize;               
    bmfHdr.bfReserved1  = 0;               
    bmfHdr.bfReserved2  = 0;               
    bmfHdr.bfOffBits  = (DWORD)sizeof(BITMAPFILEHEADER)+(DWORD)sizeof(BITMAPINFOHEADER)+dwPaletteSize;               
    //     д��λͼ�ļ�ͷ                
    WriteFile(fh,   (LPSTR)&bmfHdr,   sizeof(BITMAPFILEHEADER),   &dwWritten,   NULL);               
    //     д��λͼ�ļ���������                
    WriteFile(fh,   (LPSTR)lpbi,   dwDIBSize,   &dwWritten,   NULL);               
    //���                    
    GlobalUnlock(hDib);               
    GlobalFree(hDib);               
    CloseHandle(fh);               

    return     TRUE;           

}  