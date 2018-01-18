//////////////////////////////////////////////////////////////////////////
// ObjectARX��ϰ��Ŀ�����࣬�����MFG�ڲ���ѵ�ƻ���������1~8�������
// ����Ҫ�ķ������з�װ������ʹ�á�
//
//////////////////////////////////////////////////////////////////////////

#pragma once

class CArxProjectHelper
{
public:
    CArxProjectHelper(void){};
    ~CArxProjectHelper(void){};

public:
    //�ýṹ�����ڴ������Կ���մ������ݣ�����TextString�����û�ָ����ֵ��
    //�������ֶβ����޸ģ�tag��prompt��testString������ListCtrl����չʾ��
    struct BlockAttribute {
    public:
        // ���캯��
        BlockAttribute() {}
        BlockAttribute(const CString& tag, const CString& prompt,
            const CString& textSting, const AcDbObjectId& attrId)
            : m_tag(tag), m_prompt(prompt)
            , m_textString(textSting), m_attrId(attrId) {}
        //����
        const CString& getTag() const {return m_tag;}
        const CString& getPompt() const {return m_prompt;}
        const CString& getTextString() const {return m_textString;}
        const AcDbObjectId& getAttrId() const {return m_attrId;}
        void setTextString(const CString& newTextSting)
            {m_textString = newTextSting;}
    private:
        CString m_tag;
        CString m_prompt;
        CString m_textString;
        AcDbObjectId m_attrId;
    };

    //��8�������ʱʹ�õĶ�ά����
    typedef std::vector<std::vector<CString> > TableContent;

public:
    //��ָ��ͼ���ϻ���ָ����ɫ��Բ
    static AcDbObjectId createCircle(const AcGePoint3d &center,
        double radius, const ACHAR *layer, Adesk::UInt16 color);
    
    //����ָ�����ű��¼������
    template<typename SymbolTableType>
    static bool getSymbolRecord(AcStringArray &outputName);

    template<typename SymbolTableType>
    static bool getSymbolRecord(AcStringArray &outputName,
        AcDbObjectIdArray &outputObjId);
    
    //����������
    static bool getGroupName(AcStringArray &outputName);

    //��ȡ��ǰͼ������
    static bool getCurrentLayerName(AcString &outputName);

    //���ؿ�����
    static bool getBlockAttribute(CArray<BlockAttribute> &outputBlkAttr,
        AcDbObjectId &outputBlkId, const TCHAR *szBlkName);

    //���������ԵĿ����
    static AcDbObjectId createBlockReference(AcDbObjectId blkDefId, double dRotation,
        const AcGeScale3d &scale, const CArray<BlockAttribute> &aNewAttr);

    //��ȡ���¼����ͼ
    static HBITMAP getBlockPreviewBitmap(AcDbObjectId blkId, HDC hdc);

    //��ӡָ���ķ��ű�
    static void printSymbolRecord(const ACHAR *szSymbolType,
        const AcStringArray &recordName);

    //���������������뷽ʽ���߿����͡��߿���ɫ�����񣬷��ر�����Id
    static AcDbObjectId createTable(int iRowCount, int iColCount,
        AcDb::CellAlignment cellAlignment);

    //���������
    static bool fillTableContent(const TableContent &aTableContent,
        const AcDbObjectId &tableId);

    //���ñ���߿�����
    static bool setTableLineAttribute(AcDb::LineWeight lineWidth,
        const AcDbObjectId &lineType, const AcCmColor &lineColor,
        const AcDbObjectId &tableId);

    //���ñ����������
    static bool setTableTextAttribute(const AcDbObjectId &textStyle,
        double dTextHeight, double dTextWidthFactor,
        const AcCmColor &textColor, const AcDbObjectId &tableId);
private:
    static bool postToModelSpace(AcDbObjectId &outputId, AcDbEntity *pEntity);
    static bool createLayer(AcDbObjectId &layerId, const ACHAR *layerName);
};

template<typename SymbolTableType>
bool CArxProjectHelper::getSymbolRecord(AcStringArray &outputName,
    AcDbObjectIdArray &outputObjId)
{
    Acad::ErrorStatus es;
    AcDbSymbolTable *pSymbolTbl = NULL;
    AcDbSymbolTableRecord *pSymbolTblRecord = NULL;
    AcDbSymbolTableIterator *pSymbolTblIter = NULL;
    AcString strBuf;

    outputName.removeAll();
    outputObjId.removeAll();

    do {
        //��ָ���������ʹ򿪷��ű�
        es = acdbHostApplicationServices()->workingDatabase()
            ->getSymbolTable((SymbolTableType*&) pSymbolTbl, AcDb::kForRead);
        if (Acad::eOk != es) break;

        //�½����ű������
        es = pSymbolTbl->newIterator(pSymbolTblIter);
        if (Acad::eOk != es) break;

        //��ȡ���ű��¼
        for (; !pSymbolTblIter->done(); pSymbolTblIter->step()) {
            pSymbolTblIter->getRecord(pSymbolTblRecord, AcDb::kForRead);
            pSymbolTblRecord->getName(strBuf);
            outputName.append(strBuf);
            outputObjId.append(pSymbolTblRecord->id());
            pSymbolTblRecord->close();
        }
    } while (false);

    if (pSymbolTbl) pSymbolTbl->close();
    if (pSymbolTblIter) delete pSymbolTblIter;

    return Acad::eOk == es;
}


template<typename SymbolTableType> inline
bool CArxProjectHelper::getSymbolRecord(AcStringArray &outputName)
{
    AcDbObjectIdArray aObjId;
    return getSymbolRecord<SymbolTableType>(outputName, aObjId);
}