// StaticEx.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StaticEx.h"


// CStaticEx

IMPLEMENT_DYNAMIC(CStaticEx, CStatic)

CStaticEx::CStaticEx()
: m_hBmp(0)
, m_cx(0)
, m_cy(0)
, m_cxBmp(0)
, m_cyBmp(0)
{

}

CStaticEx::~CStaticEx()
{
}


BEGIN_MESSAGE_MAP(CStaticEx, CStatic)
    ON_WM_PAINT()
END_MESSAGE_MAP()



// CStaticEx ��Ϣ�������




void CStaticEx::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO: �ڴ˴������Ϣ����������
    // ��Ϊ��ͼ��Ϣ���� CStatic::OnPaint()

    CDC menDC;
    menDC.CreateCompatibleDC(&dc);
    menDC.SelectObject((HGDIOBJ) m_hBmp);
    SetStretchBltMode(dc.GetSafeHdc(), STRETCH_HALFTONE);
    dc.StretchBlt(0, 0, m_cx, m_cy, &menDC, 0, 0, m_cxBmp, m_cyBmp, SRCCOPY);
}
