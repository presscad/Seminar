
// Exercise_4_3View.h : CExercise_4_3View ��Ľӿ�
//

#pragma once


class CExercise_4_3View : public CView
{
protected: // �������л�����
	CExercise_4_3View();
	DECLARE_DYNCREATE(CExercise_4_3View)

// ����
public:
	CExercise_4_3Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CExercise_4_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Exercise_4_3View.cpp �еĵ��԰汾
inline CExercise_4_3Doc* CExercise_4_3View::GetDocument() const
   { return reinterpret_cast<CExercise_4_3Doc*>(m_pDocument); }
#endif

