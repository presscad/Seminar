
// Exercise_3_5Doc.cpp : CExercise_3_5Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Exercise_3_5.h"
#endif

#include "Exercise_3_5Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CExercise_3_5Doc

IMPLEMENT_DYNCREATE(CExercise_3_5Doc, CDocument)

BEGIN_MESSAGE_MAP(CExercise_3_5Doc, CDocument)
END_MESSAGE_MAP()


// CExercise_3_5Doc ����/����

CExercise_3_5Doc::CExercise_3_5Doc()
{
	// TODO: �ڴ����һ���Թ������

}

CExercise_3_5Doc::~CExercise_3_5Doc()
{
}

BOOL CExercise_3_5Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CExercise_3_5Doc ���л�

void CExercise_3_5Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
        int iCount = m_aPoint.GetSize();
        ar << iCount;
        for (int i = 0; i < iCount; ++i)
            ar << m_aPoint[i];
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
        m_aPoint.RemoveAll();
        int iCount;
        CPoint pt;
        ar >> iCount;
        for (int i = 0; i < iCount; ++i) {
            ar >> pt;
            m_aPoint.Add(pt);
        }
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CExercise_3_5Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CExercise_3_5Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CExercise_3_5Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CExercise_3_5Doc ���

#ifdef _DEBUG
void CExercise_3_5Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExercise_3_5Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CExercise_3_5Doc ����
