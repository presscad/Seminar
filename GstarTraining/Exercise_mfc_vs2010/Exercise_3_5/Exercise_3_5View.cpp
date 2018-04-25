
// Exercise_3_5View.cpp : CExercise_3_5View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Exercise_3_5.h"
#endif

#include "Exercise_3_5Doc.h"
#include "Exercise_3_5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise_3_5View

IMPLEMENT_DYNCREATE(CExercise_3_5View, CView)

BEGIN_MESSAGE_MAP(CExercise_3_5View, CView)
    ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExercise_3_5View ����/����

CExercise_3_5View::CExercise_3_5View()
{
	// TODO: �ڴ˴���ӹ������

}

CExercise_3_5View::~CExercise_3_5View()
{
}

BOOL CExercise_3_5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExercise_3_5View ����

void CExercise_3_5View::OnDraw(CDC* pDC)
{
	CExercise_3_5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
    CRect rc;
    GetClientRect(rc);
    pDC->DrawText(_T("��굥���԰뾶10��Բ�����ļ�-���桿������е����ĵ㱣��Ϊ*.dots�ļ���")
        _T("���ļ�-�򿪡��������е����Ϣ��ȡ�������ػ���"), rc, DT_WORDBREAK);

    //pDC->SetBkMode(TRANSPARENT);
    HBRUSH hbrOld = (HBRUSH) pDC->SelectObject(GetStockObject(NULL_BRUSH));
    int iCount = pDoc->m_aPoint.GetSize();
    int xpt, ypt;
    for (int i = 0; i < iCount; ++i) {
        xpt = pDoc->m_aPoint[i].x, ypt = pDoc->m_aPoint[i].y;
        pDC->Ellipse(xpt-10, ypt-10, xpt+10, ypt+10);
    }
    pDC->SelectObject(hbrOld);
}


// CExercise_3_5View ���

#ifdef _DEBUG
void CExercise_3_5View::AssertValid() const
{
	CView::AssertValid();
}

void CExercise_3_5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExercise_3_5Doc* CExercise_3_5View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExercise_3_5Doc)));
	return (CExercise_3_5Doc*)m_pDocument;
}
#endif //_DEBUG


// CExercise_3_5View ��Ϣ�������


void CExercise_3_5View::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    CExercise_3_5Doc *pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    if (!pDoc)
        return;

    pDoc->m_aPoint.Add(point);

    Invalidate();

    CView::OnLButtonDown(nFlags, point);
}
