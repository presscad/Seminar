//////////////////////////////////////////////////////////////////////////
// ��̬�Ϸ���ʾ����ա�����Բ��Jig��
//
//////////////////////////////////////////////////////////////////////////

#pragma once

class AcEdJig;

class CInsertJig : public AcEdJig
{
public:
    //��дʵ��Jig����������
    virtual DragStatus sampler();
    virtual Adesk::Boolean update() {return Adesk::kFalse;}
    virtual AcDbEntity *entity() const {return m_pEnt;}

protected:
    CInsertJig(AcDbEntity *pEnt) : m_pEnt(pEnt) {m_pEnt->setDatabaseDefaults();}
    ~CInsertJig(void) {};

protected:
    AcDbEntity *m_pEnt;
    AcGePoint3d m_ptInsert;
};

//�������յ�Jig
class CBlockReferenceInsertJig : public CInsertJig
{
public:
    CBlockReferenceInsertJig(AcDbBlockReference *pBlkRef) : CInsertJig(pBlkRef) {}
    ~CBlockReferenceInsertJig() {};

    virtual Adesk::Boolean update();
};

//�������Jig
class CTableInsertJig : public CInsertJig
{
public:
    CTableInsertJig(AcDbTable *pTable) : CInsertJig(pTable) {}
    ~CTableInsertJig() {};

    virtual Adesk::Boolean update();
};

//����Բ��Jig
class CCircleJig : public AcEdJig
{
public:
    CCircleJig(const AcGePoint3d &, Adesk::UInt16);
    ~CCircleJig();

    virtual DragStatus sampler();
    virtual Adesk::Boolean update();
    virtual AcDbEntity *entity() const {return m_pCircle;}

public:
    double getRadius() const {return m_dRadius;}

private:
    double m_dRadius;
    AcGePoint3d m_ptCenter;
    AcDbCircle *m_pCircle;
};
