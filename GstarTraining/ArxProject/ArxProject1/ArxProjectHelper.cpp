#include "stdafx.h"
#include "ArxProjectHelper.h"
#include "Jig.h"


AcDbObjectId CArxProjectHelper::createCircle(const AcGePoint3d &center, double radius,
    const ACHAR *layer, Adesk::UInt16 color)
{
    AcDbObjectId circleId, layerId;
    AcGeVector3d normal(0, 0, 1);
    AcDbCircle *pCircle = NULL;
    Acad::ErrorStatus es;

    do {
        if (!createLayer(layerId, layer)) {
            acutPrintf(_T("����: �򿪻򴴽�ͼ�� %s ʧ��\n"), layer);
            break;
        }

        pCircle = new AcDbCircle(center, normal, radius);
        if (!postToModelSpace(circleId, pCircle)) {
            acutPrintf(_T("����: ����Բʧ��\n"));
            break;
        }

        es = pCircle->setColorIndex(color);
        es = pCircle->setLayer(layer);
    } while (false);

    if (pCircle) pCircle->close();

    return circleId;
}

bool CArxProjectHelper::getGroupName(AcStringArray &outputName)
{
    Acad::ErrorStatus es;
    AcDbDictionary *pDict = NULL;
    AcDbDictionaryIterator *pDictIter = NULL;

    outputName.removeAll();

    do {
        //��ȡ���ֵ�
        es = acdbHostApplicationServices()->workingDatabase()
            ->getGroupDictionary(pDict, AcDb::kForRead);
        if (Acad::eOk != es) break;

        //�����ֵ������
        pDictIter = pDict->newIterator();
        if (!pDictIter) {
            es = Acad::eNullIterator;
            break;
        }

        //��ȡ������
        for (; !pDictIter->done(); pDictIter->next()) {
            AcDbGroup *pGroup = NULL;
            if (Acad::eOk != pDictIter->getObject((AcDbObject*&) pGroup, AcDb::kForRead))
                continue;

            ACHAR *pBuf = NULL;
            if (Acad::eOk == pGroup->getName(pBuf)) {
                outputName.append(pBuf);
                acutDelString(pBuf);
            }

            if (pGroup) pGroup->close();
        }
    } while (false);

    if (pDict) pDict->close();
    if (pDictIter) delete pDictIter;

    return Acad::eOk == es;
}

bool CArxProjectHelper::getCurrentLayerName(AcString &outputName)
{
    AcDbObjectId clayerId = acdbHostApplicationServices()->workingDatabase()->clayer();
    AcDbLayerTableRecord *pCLayer = NULL;
    if (Acad::eOk != acdbOpenObject(pCLayer, clayerId, AcDb::kForRead))
        return false;

    pCLayer->getName(outputName);

    pCLayer->close();
    return true;
}

bool CArxProjectHelper::getBlockAttribute(CArray<BlockAttribute> &outputBlkAttr,
    AcDbObjectId &outputBlkId, const TCHAR *szBlkName)
{
    AcDbBlockTable *pBlkTbl = NULL;
    AcDbBlockTableRecord *pBlkTblRecord = NULL;
    AcDbBlockTableRecordIterator *pBlkTblRecordIter = NULL;
    Acad::ErrorStatus es;

    outputBlkAttr.RemoveAll();
    outputBlkId.setNull();

    do {
        //�򿪿��
        es = acdbHostApplicationServices()->workingDatabase()
            ->getBlockTable(pBlkTbl, AcDb::kForRead);
        if (Acad::eOk != es) break;

        //���ݿ�����ƻ�ȡ����¼
        es = pBlkTbl->getAt(szBlkName, pBlkTblRecord, AcDb::kForRead);
        if (Acad::eOk != es) break;

        //��ȡ���Id
        outputBlkId = pBlkTblRecord->id();

        //���ÿ���¼�Ƿ�������
        if (!pBlkTblRecord->hasAttributeDefinitions()) {
            break;
        }

        //�����ÿ���¼�ĵ�����������ȡ����
        es = pBlkTblRecord->newIterator(pBlkTblRecordIter);
        if (Acad::eOk != es) break;

        for (; !pBlkTblRecordIter->done(); pBlkTblRecordIter->step()) {
            //ͨ����������ȡʵ�壬�����Զ�������ȡ����
            AcDbEntity *pEntity = NULL;
            pBlkTblRecordIter->getEntity(pEntity, AcDb::kForRead);
            AcDbAttributeDefinition *pAttrDef = AcDbAttributeDefinition::cast(pEntity);
            if (pAttrDef) {
                BlockAttribute blkAttr(
                    pAttrDef->tagConst(),
                    pAttrDef->promptConst(),
                    pAttrDef->textStringConst(),
                    pAttrDef->id()
                );
                outputBlkAttr.Add(blkAttr);
            }
            pEntity->close();
        }
    } while (false);

    //�������
    if (pBlkTbl) pBlkTbl->close();
    if (pBlkTblRecord) pBlkTblRecord->close();
    if (pBlkTblRecordIter) delete pBlkTblRecordIter;

    return (Acad::eOk == es && outputBlkId.isValid());
}

AcDbObjectId CArxProjectHelper::createBlockReference(AcDbObjectId blkDefId,
    double dRotation, const AcGeScale3d &scale, const CArray<BlockAttribute> &aNewAttr)
{
    assert(blkDefId.isValid());
    AcDbBlockReference *pBlkRef = new AcDbBlockReference;

    //���ÿ���յ�����顢��ת�ǺͷŴ�ϵ��
    pBlkRef->setBlockTableRecord(blkDefId);
    pBlkRef->setRotation(dRotation);
    pBlkRef->setScaleFactors(scale);

    AcDbObjectId blkRefId;
    //���п���յ��ϷŲ���
    CBlockReferenceInsertJig blkRefInsertJig(pBlkRef);
    blkRefInsertJig.setDispPrompt(_T("ָ������յĲ����: \n"));
    if (AcEdJig::kNormal == blkRefInsertJig.drag()) {

        INT_PTR len = aNewAttr.GetCount();
        for (int i = 0; i < len; ++i) {
            const BlockAttribute *pNewAttr = &(aNewAttr.GetAt(i));
            AcDbAttribute *pAttr = new AcDbAttribute;
        
            //1���ӿ鶨���п�������
            {
                AcDbAttributeDefinition *pAttrDef = NULL;
                acdbOpenAcDbEntity((AcDbEntity*&) pAttrDef,
                    pNewAttr->getAttrId(), AcDb::kForRead);

                pAttr->setAttributeFromBlock(pAttrDef, pBlkRef->blockTransform());
            
                pAttrDef->close();
            }

            //2���Ӵ��ݵ��������滻����ֵ��TextString�������û�ָ������ֵ
            pAttr->setTextString(pNewAttr->getTextString());

            //������ʵ�����ӵ������
            pBlkRef->appendAttribute(pAttr);
            pAttr->close();
        }

        //������շ���ģ�Ϳռ�
        blkRefId = blkRefInsertJig.append();
    }

    pBlkRef->close();

    return blkRefId;
}

//ע��HBITMAP�ɵ�����ͨ��DeleteObject�����ͷ�
HBITMAP CArxProjectHelper::getBlockPreviewBitmap(AcDbObjectId blkId, HDC hdc)
{
    AcDbBlockTableRecord *pBlkTblRcd = NULL;
    AcArray<Adesk::UInt8> icon;
    HBITMAP hBmp = NULL;
    Acad::ErrorStatus es;

    do {
        es = acdbOpenObject(pBlkTblRcd, blkId, AcDb::kForRead);
        if (Acad::eOk != es) break;

        //���Թ�������ͼ
        AcString str;
        pBlkTblRcd->getName(str);
        if (!pBlkTblRcd->hasPreviewIcon()) {
            int rt = acedCommand(RTSTR, _T("BLOCKICON"), RTSTR, str.kACharPtr(), RTNONE);
        }

        if (!pBlkTblRcd->hasPreviewIcon())
            break;

        es = pBlkTblRcd->getPreviewIcon(icon);
        if (Acad::eOk != es) break;

        BITMAPINFOHEADER infoHeader;
        memcpy(&infoHeader, icon.asArrayPtr(), sizeof(BITMAPINFOHEADER));
        size_t memSize = sizeof(BITMAPINFOHEADER) + ((__int64)1<<infoHeader.biBitCount)*sizeof(RGBQUAD);
        BITMAPINFO *pInfo = new BITMAPINFO[memSize];
        memcpy(pInfo, icon.asArrayPtr(), memSize);

        //�������豸�޹ص�λͼ�����ؾ��
        hBmp = CreateDIBitmap(hdc, &infoHeader, CBM_INIT, icon.asArrayPtr()+memSize, pInfo, DIB_RGB_COLORS);
        delete [] pInfo;

    } while (false);

    if (pBlkTblRcd) pBlkTblRcd->close();

    return hBmp;
}

void CArxProjectHelper::printSymbolRecord(const ACHAR *szSymbolType, const AcStringArray &recordName)
{
    int count = recordName.length();
    acutPrintf(_T("%s: "), szSymbolType);

    if (count <= 0) {
        acutPrintf(_T("<��>\n"));
        return;
    }

    for (int i = 0; i < count; ++i) {
        acutPrintf(recordName.at(i).kACharPtr());

        if (i < count-1)
            acutPrintf(_T(","));
    }
    acutPrintf(_T("\n"));  //�������ӡ����
}

AcDbObjectId CArxProjectHelper::createTable(int iRowCount, int iColCount,
    AcDb::CellAlignment cellAlignment)
{
    AcDbObjectId tableId;
    Acad::ErrorStatus es;
    AcDbTable *pTbl = new AcDbTable;

    //����������
    es = pTbl->setNumRows(iRowCount);
    assert(Acad::eOk == es);
    es = pTbl->setNumColumns(iColCount);
    assert(Acad::eOk == es);

    //���õ�Ԫ����뷽ʽ
    for (int i = 0; i < iRowCount; ++i)
        for (int j = 0; j < iColCount; ++j)
            es = pTbl->setAlignment(i, j, cellAlignment);
    assert(Acad::eOk == es);

    //���ñ�����
    es = pTbl->suppressHeaderRow(false);
    assert(Acad::eOk == es);

    pTbl->setColumnWidth(30); //�̶��п�Ϊ30

    es = pTbl->generateLayout();
    assert(Acad::eOk == es);

    //ͨ����̬�ϷŲ�����
    CTableInsertJig tblJig(pTbl);
    tblJig.setDispPrompt(_T("ָ���������: \n"));
    if (AcEdJig::kNormal == tblJig.drag()) {
        tableId = tblJig.append();
    }

    pTbl->close();

    return tableId;
}

bool CArxProjectHelper::fillTableContent(const TableContent &aTableContent,
    const AcDbObjectId &tableId)
{
    AcDbTable *pTbl = NULL;
    Acad::ErrorStatus es;
    if (Acad::eOk != acdbOpenObject(pTbl, tableId, AcDb::kForWrite))
        return false;

    for (int i = 0; i < (int) pTbl->numRows(); ++i) {
        for (int j = 0; j < (int) pTbl->numColumns(); ++j) {
            es = pTbl->setTextString(i, j, aTableContent[i][j]);
            assert(Acad::eOk == es);
        }
    }

    pTbl->close();
    return true;
}

bool CArxProjectHelper::setTableTextAttribute(const AcDbObjectId &textStyle,
    double dTextHeight, double dTextWidthFactor,
    const AcCmColor &textColor, const AcDbObjectId &tableId)
{
    AcDbTable *pTbl = NULL;
    Acad::ErrorStatus es;
    if (Acad::eOk != acdbOpenObject(pTbl, tableId, AcDb::kForWrite))
        return false;

    for (int i = 0; i < (int) pTbl->numRows(); ++i) {
        for (int j = 0; j < (int) pTbl->numColumns(); ++j) {
            es = pTbl->setTextStyle(i, j, textStyle);  //������ʽ
            assert(Acad::eOk == es);
            es = pTbl->setTextHeight(i, j, dTextHeight); //���ָ߶�
            assert(Acad::eOk == es);
            es = pTbl->setContentColor(i, j, textColor); //������ɫ
            assert(Acad::eOk == es);            
        }
    }

    //�޸�ָ��������ʽ�Ŀ�����ӣ��ﵽ�޸ı�������ֵĿ�߱ȣ����������ã�
    AcDbObjectPointer<AcDbTextStyleTableRecord> pTextStyleRcd(textStyle, AcDb::kForWrite);
    if (Acad::eOk == pTextStyleRcd.openStatus()) {
        pTextStyleRcd->setXScale(dTextWidthFactor);
    }

    pTbl->close();
    return true;
}

bool CArxProjectHelper::setTableLineAttribute(AcDb::LineWeight lineWidth,
    const AcDbObjectId &lineType, const AcCmColor &lineColor,
    const AcDbObjectId &tableId)
{
    AcDbTable *pTbl = NULL;
    Acad::ErrorStatus es;
    if (Acad::eOk != acdbOpenObject(pTbl, tableId, AcDb::kForWrite))
        return false;

    for (int i = 0; i < (int) pTbl->numRows(); ++i) {
        for (int j = 0; j < (int) pTbl->numColumns(); ++j) {
            //�߿��߿�
            es = pTbl->setGridLineWeight(i, j, AcDb::kAllGridLineTypes, lineWidth);
            assert(Acad::eOk == es);
            //�߿��߿�����
            es = pTbl->setGridLinetype(i, j, AcDb::kAllGridLineTypes, lineType);
            assert(Acad::eOk == es);
            //�߿���ɫ
            es = pTbl->setGridColor(i, j, AcDb::kAllGridLineTypes, lineColor);
            assert(Acad::eOk == es);
        }
    }

    pTbl->close();
    return true;
}

bool CArxProjectHelper::postToModelSpace(AcDbObjectId &outputId, AcDbEntity *pEntity)
{
    Acad::ErrorStatus es;
    AcDbBlockTable *pBlkTbl = NULL;
    AcDbBlockTableRecord *pBlkTblRecord = NULL;

    outputId.setNull();

    do {
        //�򿪿��
        es = acdbHostApplicationServices()->workingDatabase()
            ->getBlockTable(pBlkTbl, AcDb::kForRead);
        if (Acad::eOk != es) break;

        //�򿪿���¼
        es = pBlkTbl->getAt(ACDB_MODEL_SPACE, pBlkTblRecord, AcDb::kForWrite);
        if (Acad::eOk != es) break;

        //���ʵ�岢������Id
        es = pBlkTblRecord->appendAcDbEntity(outputId, pEntity);
    } while (false);
    
    if (pBlkTbl) pBlkTbl->close();
    if (pBlkTblRecord) pBlkTblRecord->close();

    return Acad::eOk == es;
}

bool CArxProjectHelper::createLayer(AcDbObjectId &layerId, const ACHAR *layerName)
{
    AcDbLayerTable *pLayerTbl = NULL;
    AcDbLayerTableRecord *pLayerTblRecord = NULL;
    Acad::ErrorStatus es;

    layerId.setNull();

    do {
        es = acdbHostApplicationServices()->workingDatabase()
            ->getLayerTable(pLayerTbl, AcDb::kForWrite);
        if (Acad::eOk != es) break;

        //�ж�ͼ���Ƿ���ڣ�����������򴴽�
        if (pLayerTbl->has(layerName)) {
            es = pLayerTbl->getAt(layerName, pLayerTblRecord, AcDb::kForWrite);
        }
        else {
            pLayerTblRecord = new AcDbLayerTableRecord();
            pLayerTblRecord->setName(layerName);
            es = pLayerTbl->add(pLayerTblRecord);
        }
        if (Acad::eOk != es) break;

        //����ͼ��Id
        layerId = pLayerTblRecord->id();

    } while (false);

    if (pLayerTbl) pLayerTbl->close();
    if (pLayerTblRecord) pLayerTblRecord->close();

    return Acad::eOk == es;
}