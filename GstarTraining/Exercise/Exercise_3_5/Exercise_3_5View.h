
// Exercise_3_5View.h : CExercise_3_5View ��Ľӿ�
//

#pragma once


class CExercise_3_5View : public CView
{
protected: // �������л�����
	CExercise_3_5View();
	DECLARE_DYNCREATE(CExercise_3_5View)

// ����
public:
	CExercise_3_5Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CExercise_3_5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Exercise_3_5View.cpp �еĵ��԰汾
inline CExercise_3_5Doc* CExercise_3_5View::GetDocument() const
   { return reinterpret_cast<CExercise_3_5Doc*>(m_pDocument); }
#endif

