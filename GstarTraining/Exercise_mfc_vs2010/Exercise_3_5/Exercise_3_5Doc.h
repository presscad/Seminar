
// Exercise_3_5Doc.h : CExercise_3_5Doc ��Ľӿ�
//


#pragma once


class CExercise_3_5Doc : public CDocument
{
protected: // �������л�����
	CExercise_3_5Doc();
	DECLARE_DYNCREATE(CExercise_3_5Doc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CExercise_3_5Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

public:
    CArray<CPoint> m_aPoint;

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
