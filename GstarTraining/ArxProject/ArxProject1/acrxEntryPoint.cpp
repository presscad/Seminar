// (C) Copyright 2002-2012 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//----- acrxEntryPoint.cpp
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "resource.h"
#include "ArxProjectHelper.h"
#include "InsertBlkDlg.h"
#include "InsertTableDlg.h"
#include "Jig.h"
//-----------------------------------------------------------------------------
#define szRDS _RXST("MFG")
//-----------------------------------------------------------------------------
//----- ObjectARX EntryPoint
class CArxProject1App : public AcRxArxApp {

public:
	CArxProject1App () : AcRxArxApp () {}

	virtual AcRx::AppRetCode On_kInitAppMsg (void *pkt) {
		// TODO: Load dependencies here

		// You *must* call On_kInitAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kInitAppMsg (pkt) ;
		
		// TODO: Add your initialization code here
        acedAlert(
            _T("MFGArxProject1.arx�����嵥��\n")
            _T("ARX1��������Ϣ����ʾHello World��\n")
            _T("ARX2��ָ��Բ�ġ��뾶��ͼ��������ɫ����ֵ������Բ������ӡ����ֵ��\n")
            _T("ARX3��ѡ��ʵ�壬����TEST������ɫֵΪ4����ɫΪByLayer��Բ�뾶����һ����\n")
            _T("ARX4����ӡ��ǰͼ������ͼ�㡢�顢�ߴ��ע��ʽ��������ƣ�\n")
            _T("ARX5��ѡ����ʵ�壬�ڽ��㴦��Բ��\n")
            _T("ARX6��������������������������Կ���գ�\n")
            _T("ARX7������CGridCtrl�ؼ��е�������AutoCAD�л��Ʊ��")
            );

		return (retCode) ;
	}

	virtual AcRx::AppRetCode On_kUnloadAppMsg (void *pkt) {
		// TODO: Add your code here

		// You *must* call On_kUnloadAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kUnloadAppMsg (pkt) ;

		// TODO: Unload dependencies here

		return (retCode) ;
	}

	virtual void RegisterServerComponents () {
	}
	
    //----------------------------------------------------------
    // Summary:
    //    �����Ի�������
    // Parameter:
    // Returns:
    //    void
    //----------------------------------------------------------
    static void MFGGroupARX1 () {
        acedAlert(_T("Hello World"));
	}

    //----------------------------------------------------------
    // Summary:
    //    ����Բ����
    // Parameter:
    // Returns:
    //    void
    //----------------------------------------------------------
    static void MFGGroupARX2 () {
        AcGePoint3d ptCenter;
        ads_real radius = 0;
        ACHAR szLayerName[135] = {0}; //acedGetString����ȡ133�ַ�
        int colorIndex = 4;
        int rt;

        rt= acedGetString(Adesk::kFalse, _T("ָ��Բ���ڵ�ͼ������ <TEST>: \n"), szLayerName);
        switch (rt) {
        case RTNORM:
            //����û�ֱ�Ӱ��س�ȷ�ϣ�����Ĭ��ֵ
            if (_T('\0') ==szLayerName[0]) _tcscpy(szLayerName, _T("TEST"));
            break;
        default:
            return;
        }

        acedInitGet(RSG_NONEG, NULL);
        rt= acedGetInt(_T("ָ��Բ����ɫ����ֵ(0~256) <4>: \n"), &colorIndex);
        switch (rt) {
        case RTNONE:
            //����û�ֱ�Ӱ��س�ȷ�ϣ�����Ĭ��ֵ
            colorIndex = 4; break;
        case RTNORM:
            if (colorIndex >256)
                acutPrintf(_T("����: �������ֵ����������Χ����ɫ��Ĭ����ʾ\n"));
            break;
        default:
            return;
        }
        
        acedInitGet(RSG_NONULL, NULL);
        if (RTNORM != acedGetPoint(NULL, _T("ָ��Բ��Բ��: \n"), asDblArray(ptCenter)))
            return;

        CCircleJig circleJig(ptCenter, colorIndex);
        circleJig.setDispPrompt(_T("ָ��Բ�İ뾶: \n"));
        if (AcEdJig::kNormal != circleJig.drag())
            return;

        AcDbObjectId circleId = CArxProjectHelper::createCircle(ptCenter, circleJig.getRadius(), szLayerName, colorIndex);

        acutPrintf(_T("�������Բ�ľ��Ϊ: "));
        circleId.handle().print();
    }

    //----------------------------------------------------------
    // Summary:
    //    ѡ��ʵ�壬��Բ�뾶����һ��
    // Parameter:
    // Returns:
    //    void
    //----------------------------------------------------------
    static void MFGGroupARX3 ()
    {
        resbuf *rbFilter = NULL;
        ads_name ssname = {0};
        rbFilter = acutBuildList(RTDXF0, _T("CIRCLE")  //ѡ��Բ
            , 8, _T("TEST")                            //ѡ��ͼ��ΪTEST
            , -4, _T("<OR")                            //�߼���ʼ
            , 62, 4                                    //��ɫ����Ϊ4
            , 62, 256                                  //����ɫΪByLayer
            , -4, _T("OR>")                            //�߼������
            , RTNONE);

        if (RTNORM == acedSSGet(NULL, NULL, NULL, rbFilter, ssname)) {
            long len = 0L;
            acedSSLength(ssname, &len);

            for (AdInt32 i = 0L; i < len; ++i) {
                //��������ȡѡ���е�Ԫ��
                ads_name ent;
                acedSSName(ssname, i, ent);
                AcDbObjectId objId;
                acdbGetObjectId(objId, ent);
                AcDbEntity *pEntity = NULL;
                if (Acad::eOk != acdbOpenObject(pEntity, objId, AcDb::kForWrite))
                    continue;
            
                //��ȡԲ�Ĳ���ֱ������һ��
                AcDbCircle *pCircle = AcDbCircle::cast(pEntity);
                if (pCircle) {
                    AcGeMatrix3d mat;
                    mat.setToScaling(2, pCircle->center());
                    pCircle->transformBy(mat);
                }
                pEntity->close();
            }
        }
        
        acutRelRb(rbFilter);
        acedSSFree(ssname);
    }

    //----------------------------------------------------------
    // Summary:
    //    ��ӡ����ͼ�������������ߴ��ע��ʽ��������
    // Parameter:
    // Returns:
    //    void
    //----------------------------------------------------------
    static void MFGGroupARX4 ()
    {
        AcStringArray aOutputName;
        
        CArxProjectHelper::getSymbolRecord<AcDbBlockTable>(aOutputName);
        CArxProjectHelper::printSymbolRecord(_T("�������"), aOutputName);

        CArxProjectHelper::getSymbolRecord<AcDbLayerTable>(aOutputName);
        CArxProjectHelper::printSymbolRecord(_T("�������"), aOutputName);

        CArxProjectHelper::getSymbolRecord<AcDbDimStyleTable>(aOutputName);
        CArxProjectHelper::printSymbolRecord(_T("�ߴ��ע��ʽ����"), aOutputName);

        CArxProjectHelper::getGroupName(aOutputName);
        CArxProjectHelper::printSymbolRecord(_T("������"), aOutputName);
    }

    //----------------------------------------------------------
    // Summary:
    //    ����ѡ������ʵ�壬�ڽ��㴦����Բ
    // Parameter:
    // Returns:
    //    void
    //----------------------------------------------------------
    static void MFGGroupARX5 ()
    {
        int rt; //ѡ��ʵ�巵��ֵ
        ads_name ent[2] = {0};  //��һ����ʵ����
        ads_point pt;  //ѡ���һ����ʵ��ʱ������
        AcDbObjectId objId; //ѡ��ʵ���ǰͼ���id
        AcDbEntity *pEnt[2] = {0};  //����ʵ�����ָ��
        AcGePoint3dArray aPoint3d;  //��������ʵ��Ľ���
        bool bCancel;  //�˳�ѡ���������
        //ѡ����ʾ˵��
        ACHAR *strDesc[2] = {_T("ѡ���һʵ��: \n"), _T("ѡ��ڶ�ʵ��: \n")};

        for (int i = 0; i < 2; ++i) {
            bCancel = false;

            while (!bCancel) {
                rt = acedEntSel(strDesc[i], ent[i], pt);
                switch (rt) {
                case RTNORM:
                    {
                        acdbGetObjectId(objId, ent[i]);
                        acdbOpenObject(pEnt[i], objId, AcDb::kForRead);
                        if (pEnt[i]->isKindOf(AcDbLine::desc())
                            || pEnt[i]->isKindOf(AcDbCircle::desc())
                            || pEnt[i]->isKindOf(AcDbArc::desc())
                            || pEnt[i]->isKindOf(AcDbEllipse::desc())
                            || pEnt[i]->isKindOf(AcDbPolyline::desc()))
                        {
                            pEnt[i]->highlight(); //ѡ��������ʾ
                            bCancel = true;
                        }
                        else {
                            acutPrintf(_T("����: ѡ���ʵ��ֻ��Ϊֱ�ߡ�Բ��Բ������Բ�Ͷ����\n"));
                        }
                    }
                    break;

                case RTERROR: //���������ѡ��
                    break;

                case RTCAN:  //���û�����Esc���˳�
                default:
                    goto CleanHandler;
                }
            }
        }

        //�󽻵�
        pEnt[0]->intersectWith(pEnt[1], AcDb::kOnBothOperands, aPoint3d);

        //�ڵ�ǰͼ���ϻ��ư뾶Ϊ1��Բ
        {
            AcString strCLayerName;
            if (!CArxProjectHelper::getCurrentLayerName(strCLayerName))
                goto CleanHandler;

            int len = aPoint3d.length();
            for (int i = 0; i < len; ++i) {
                CArxProjectHelper::createCircle(aPoint3d.at(i), 1, strCLayerName.kTCharPtr(), 1);
            }
        }

CleanHandler:
        for (int i = 0; i < 2; ++i) {
            if (!acdbNameNil(ent[i]))
                pEnt[i]->unhighlight(); //�ָ�δ����״̬
            if (pEnt[i]) pEnt[i]->close();
        }
    }

    //----------------------------------------------------------
    // Summary:
    //    �ڶԻ�������������ֵ����������ԵĿ����
    // Parameter:
    // Returns:
    //    void
    //----------------------------------------------------------
    static void MFGGroupARX6 ()
    {
        CInsertBlkDlg dlg;
        if (IDOK == dlg.DoModal()) {
            CArxProjectHelper::createBlockReference(dlg.m_blkDefId, 0,
                AcGeScale3d(1), dlg.m_aBlkAttr); //��ת�ͷŴ�ϵ����ΪĬ��
        }
    }

    //----------------------------------------------------------
    // Summary:
    //    ����CGridCtrl�ؼ��е����ݻ��Ʊ��
    // Parameter:
    // Returns:
    //    void
    //----------------------------------------------------------
    static void MFGGroupARX7 ()
    {
        CInsertTableDlg dlg;
        if (IDOK == dlg.DoModal()) {
            //�������
            AcDbObjectId tableId = CArxProjectHelper::createTable(dlg.getRowCount(),
                dlg.getColumnCount(), dlg.getCellAlignment());

            if (tableId.isValid()) { //���ñ������
                CArxProjectHelper::fillTableContent(dlg.getTableContent(), tableId);
                CArxProjectHelper::setTableTextAttribute(dlg.getTextStyle(), dlg.getTextHeight(),
                    dlg.getTextWidthFactor(), dlg.getTextColor(), tableId);
                CArxProjectHelper::setTableLineAttribute(dlg.getLineWeight(), dlg.getLineType(),
                    dlg.getLineColor(), tableId);
            }
        }
    }
} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT(CArxProject1App)

ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject1App, MFGGroup, ARX1, ARX1, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject1App, MFGGroup, ARX2, ARX2, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject1App, MFGGroup, ARX3, ARX3, ACRX_CMD_MODAL | ACRX_CMD_USEPICKSET, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject1App, MFGGroup, ARX4, ARX4, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject1App, MFGGroup, ARX5, ARX5, ACRX_CMD_MODAL | ACRX_CMD_USEPICKSET, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject1App, MFGGroup, ARX6, ARX6, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject1App, MFGGroup, ARX7, ARX7, ACRX_CMD_MODAL, NULL)

