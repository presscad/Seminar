
// Exercise_4_3View.cpp : CExercise_4_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Exercise_4_3.h"
#endif

#include "Exercise_4_3Doc.h"
#include "Exercise_4_3View.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise_4_3View

IMPLEMENT_DYNCREATE(CExercise_4_3View, CView)

BEGIN_MESSAGE_MAP(CExercise_4_3View, CView)
    ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CExercise_4_3View ����/����

CExercise_4_3View::CExercise_4_3View()
{
	// TODO: �ڴ˴���ӹ������

}

CExercise_4_3View::~CExercise_4_3View()
{
}

BOOL CExercise_4_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExercise_4_3View ����

void CExercise_4_3View::OnDraw(CDC* /*pDC*/)
{
	CExercise_4_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CExercise_4_3View ���

#ifdef _DEBUG
void CExercise_4_3View::AssertValid() const
{
	CView::AssertValid();
}

void CExercise_4_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExercise_4_3Doc* CExercise_4_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExercise_4_3Doc)));
	return (CExercise_4_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CExercise_4_3View ��Ϣ�������


void CExercise_4_3View::OnMouseMove(UINT nFlags, CPoint point)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    CString strBuf;
    strBuf.Format(_T("x=%d, y=%d"), point.x, point.y);
    ((CMainFrame*) GetParent())->m_wndStatusBar.SetPaneText(1, strBuf);

    CView::OnMouseMove(nFlags, point);
}
