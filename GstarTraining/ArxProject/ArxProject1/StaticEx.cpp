// StaticEx.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StaticEx.h"


// CStaticEx

IMPLEMENT_DYNAMIC(CStaticEx, CStatic)

CStaticEx::CStaticEx()
    : m_pDevice(nullptr)
    , m_pModel(nullptr)
    , m_pView(nullptr)
{
}

CStaticEx::~CStaticEx()
{
    if (nullptr != m_pDevice) {
        if (nullptr != m_pView)
            m_pDevice->erase(m_pView);
        acgsGetGsManager()->destroyAutoCADDevice(m_pDevice);
    }

    if (nullptr != m_pView) {
        m_pView->eraseAll();
        acgsGetGsManager()->getGSClassFactory()->deleteView(m_pView);
    }

    if (nullptr != m_pModel)
        acgsGetGsManager()->destroyAutoCADModel(m_pModel);
}


BEGIN_MESSAGE_MAP(CStaticEx, CStatic)
    ON_WM_PAINT()
END_MESSAGE_MAP()



// CStaticEx ��Ϣ�������

void CStaticEx::OnPaint()
{
    CPaintDC dc(this); // device context for painting

    if (m_pView) {
        m_pView->invalidate();
        m_pView->update();
    }
}

BOOL CStaticEx::Init()
{
    CRect rcClient;
    GetClientRect(rcClient);
    m_pDevice = acgsGetGsManager()->createAutoCADDevice(GetSafeHwnd());
    if (nullptr == m_pDevice)
        return FALSE;
    m_pDevice->onSize(rcClient.Width(), rcClient.Height());

    m_pView = acgsGetGsManager()->getGSClassFactory()->createView();
    if (nullptr == m_pView)
        return FALSE;

    m_pModel = acgsGetGsManager()->createAutoCADModel();
    if (nullptr == m_pModel)
        return FALSE;

    if (!(m_pDevice->add(m_pView)))
        return FALSE;

    return TRUE;
}

void CStaticEx::PreviewIcon(LPCTSTR lpszBlockName /* = ACDB_MODEL_SPACE */)
{
    assert(m_pView);
    m_pView->eraseAll();

    /************************************************************************/
    /* ��ÿ���¼ָ��                                                      */
    /************************************************************************/
    AcDbBlockTableRecordPointer pBlkTblRcd(lpszBlockName,
        acdbHostApplicationServices()->workingDatabase(), AcDb::kForRead);
    if (Acad::eOk != pBlkTblRcd.openStatus())
        return;

    /************************************************************************/
    /* ��ȡ����¼������ʵ�����󼸺η�Χ                                   */
    /************************************************************************/
    AcDbExtents extents;
    AcDbBlockTableRecordIterator *pBlkTblRcdIter = nullptr;
    if (Acad::eOk != pBlkTblRcd->newIterator(pBlkTblRcdIter))
        return;

    for (; !pBlkTblRcdIter->done(); pBlkTblRcdIter->step()) {
        AcDbEntity *pEnt = nullptr;
        AcDbExtents entExt;
        if (Acad::eOk != pBlkTblRcdIter->getEntity(pEnt, AcDb::kForRead))
            continue;
        pEnt->getGeomExtents(entExt);
        extents.addExt(entExt);
        pEnt->close();
    }
    delete pBlkTblRcdIter;


    /************************************************************************/
    /* ������¼��ӵ���ͼ�����д�С���ŵ�����                               */
    /************************************************************************/
    m_pView->add(pBlkTblRcd, m_pModel);

    m_pView->zoomExtents(extents.minPoint(), extents.maxPoint());

    Invalidate();
}
