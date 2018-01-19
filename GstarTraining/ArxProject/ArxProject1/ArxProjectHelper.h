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
    //----------------------------------------------------------
    // Summary:
    //    ��ָ��ͼ���ϻ���ָ����ɫ��Բ
    // Parameter:
    //    center - Բ��
    //    radius - �뾶
    //    layer - ͼ����
    //    color - ��ɫ����ֵ
    // Returns:
    //    AcDbObjectId
    //----------------------------------------------------------
    static AcDbObjectId createCircle(const AcGePoint3d &center,
        double radius, const ACHAR *layer, Adesk::UInt16 color);
    
    //----------------------------------------------------------
    // Summary:
    //    ����ָ�����ű��¼������
    // Parameter:
    //    outputName - ���ط��ż�¼��
    //    [outputObjId] - ���ط��ż�¼�Ķ���Id
    // Returns:
    //    bool
    //----------------------------------------------------------
    template<typename SymbolTableType>
    static bool getSymbolRecord(AcStringArray &outputName);

    template<typename SymbolTableType>
    static bool getSymbolRecord(AcStringArray &outputName,
        AcDbObjectIdArray &outputObjId);
    
    //----------------------------------------------------------
    // Summary:
    //    ����������
    // Parameter:
    //    outputName - ��������
    // Returns:
    //    bool
    //----------------------------------------------------------
    static bool getGroupName(AcStringArray &outputName);

    //----------------------------------------------------------
    // Summary:
    //    ��ȡ��ǰͼ������
    // Parameter:
    //    outputName - 
    // Returns:
    //    bool
    //----------------------------------------------------------
    static bool getCurrentLayerName(AcString &outputName);

    //----------------------------------------------------------
    // Summary:
    //    ���ص��������������
    // Parameter:
    //    outputBlkAttr - ��������
    //    outputBlkId - �鶨���Id
    //    szBlkName - �鶨�������
    // Returns:
    //    bool
    //----------------------------------------------------------
    static bool getBlockAttribute(CArray<BlockAttribute> &outputBlkAttr,
        AcDbObjectId &outputBlkId, const TCHAR *szBlkName);

    //----------------------------------------------------------
    // Summary:
    //    ���ݿ鶨�崴�������ԵĿ����
    // Parameter:
    //    blkDefId - �鶨���Id
    //    dRotation - ����յ���ת�Ƕȣ���λ��
    //    scale - ����յķŴ�ϵ����Ĭ��Ϊ1
    //    aNewAttr - �������Ҫ�趨������ֵ
    // Returns:
    //    AcDbObjectId
    //----------------------------------------------------------
    static AcDbObjectId createBlockReference(AcDbObjectId blkDefId, double dRotation,
        const AcGeScale3d &scale, const CArray<BlockAttribute> &aNewAttr);

    //----------------------------------------------------------
    // Summary:
    //    �ӿ鶨���л�ȡ���¼����ͼ�����ص�λͼ�����Ҫ��
    //    �������ͷ�
    // Parameter:
    //    blkId - �鶨���Id
    //    hdc - ��Ҫ��ʾ����ͼ�Ĵ��ڵ�DC���
    // Returns:
    //    HBITMAP
    //----------------------------------------------------------
    static HBITMAP getBlockPreviewBitmap(AcDbObjectId blkId, HDC hdc);

    //----------------------------------------------------------
    // Summary:
    //    ��ӡָ���ķ��ű�����
    // Parameter:
    //    szSymbolType - ���ű���������
    //    recordName - ���ű�����
    // Returns:
    //    void
    //----------------------------------------------------------
    static void printSymbolRecord(const ACHAR *szSymbolType,
        const AcStringArray &recordName);

    //----------------------------------------------------------
    // Summary:
    //    ���������������뷽ʽ�����񣬷��ر�����Id
    // Parameter:
    //    iRowCount - ��������
    //    iColCount - ��������
    //    cellAlignment - ��Ԫ����뷽ʽ
    // Returns:
    //    AcDbObjectId
    //----------------------------------------------------------
    static AcDbObjectId createTable(int iRowCount, int iColCount,
        AcDb::CellAlignment cellAlignment);

    //----------------------------------------------------------
    // Summary:
    //    ���ݱ��Id���������
    // Parameter:
    //    aTableContent - �����������
    //    tableId - ���Id
    // Returns:
    //    bool
    //----------------------------------------------------------
    static bool fillTableContent(const TableContent &aTableContent,
        const AcDbObjectId &tableId);

    //----------------------------------------------------------
    // Summary:
    //    ���ݱ��Id���ñ���߿�����
    // Parameter:
    //    lineWidth - �߿�
    //    lineType - ����
    //    lineColor - ��ɫ
    //    tableId - ���Id
    // Returns:
    //    bool
    //----------------------------------------------------------
    static bool setTableLineAttribute(AcDb::LineWeight lineWidth,
        const AcDbObjectId &lineType, const AcCmColor &lineColor,
        const AcDbObjectId &tableId);

    //----------------------------------------------------------
    // Summary:
    //    ���ݱ��Id���ñ����������
    //    ע���ı������ӻ�ı�������ʽ
    // Parameter:
    //    textStyle - ������ʽ
    //    dTextHeight - ���ָ߶�
    //    dTextWidthFactor - ���ֿ������
    //    textColor - ������ɫ
    //    tableId - ���Id
    // Returns:
    //    bool
    //----------------------------------------------------------
    static bool setTableTextAttribute(const AcDbObjectId &textStyle,
        double dTextHeight, double dTextWidthFactor,
        const AcCmColor &textColor, const AcDbObjectId &tableId);
private:
    //----------------------------------------------------------
    // Summary:
    //    ��ʵ�����ģ�Ϳռ䣬������ʵ���Id
    // Parameter:
    //    outputId - ʵ��Id
    //    pEntity - ʵ�����ָ��
    // Returns:
    //    bool
    //----------------------------------------------------------
    static bool postToModelSpace(AcDbObjectId &outputId, AcDbEntity *pEntity);

    //----------------------------------------------------------
    // Summary:
    //    ����ͼ�����ƴ���ͼ�㣬������ͼ��Id
    // Parameter:
    //    layerId - ͼ��Id
    //    layerName - ͼ������
    // Returns:
    //    bool
    //----------------------------------------------------------
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