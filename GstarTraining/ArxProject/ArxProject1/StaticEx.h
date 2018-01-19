//////////////////////////////////////////////////////////////////////////
// ������ʾ�鶨������ͼ�Ŀؼ��࣬������CStatic�������DrawBitmap����
//
//////////////////////////////////////////////////////////////////////////

#pragma once


// CStaticEx

class CStaticEx : public CStatic
{
	DECLARE_DYNAMIC(CStaticEx)

public:
	CStaticEx();
	virtual ~CStaticEx();

protected:
	DECLARE_MESSAGE_MAP()
    HBITMAP m_hBmp;
    int m_cx, m_cy, m_cxBmp, m_cyBmp;
public:
    afx_msg void OnPaint();
    void DrawBitmap(HBITMAP hBmp, int cx, int cy, int cxBmp, int cyBmp);
};

inline
void CStaticEx::DrawBitmap(HBITMAP hBmp, int cx, int cy, int cxBmp, int cyBmp)
{
    m_hBmp = hBmp, m_cx = cx, m_cy = cy, m_cxBmp = cxBmp, m_cyBmp = cyBmp;
    Invalidate();
}


