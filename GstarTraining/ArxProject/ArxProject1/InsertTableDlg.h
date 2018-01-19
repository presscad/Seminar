#pragma once
#include <acuiEdit.h>
#include <acuiComboBox.h>
#include "GridCtrl_src/GridCtrl.h"
#include "resource.h"
#include "afxwin.h"
#include "afxcmn.h"
#include "ArxProjectHelper.h"

// CInsertTableDlg �Ի���

class CInsertTableDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CInsertTableDlg)

public:
	CInsertTableDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInsertTableDlg();

// �Ի�������
	enum { IDD = IDD_INSERTTABLE_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

    //���ݱ���
private:
    CArxProjectHelper::TableContent m_aTableContent; //������ݣ���ά����
    AcDbObjectId m_TextStyleId; //������ʽId
    double m_dTextHeight; //���ָ߶�
    double m_dWidthFactor; //���ֿ������
    AcCmColor m_TextColor; //������ɫ
    int m_iRowNum; //�������
    int m_iColumnNum; //�������
    AcDb::CellAlignment m_CellAlignment; //��Ԫ����뷽ʽ
    AcDb::LineWeight m_LineWeight; //����߿���߿�
    AcDbObjectId m_LineTypeId; //����߿������Id
    AcCmColor m_LineColor; //����߿����ɫ
    AcDbObjectIdArray m_aTextStyleId; //��ǰͼ������������ʽ��Id����

    //�ؼ�����
private:
    CGridCtrl m_gridContent; //�趨������ݵı��ؼ�
    CComboBox m_comboTextStyle; //������ʽ����Ͽ�ؼ�
    CAcUiNumericEdit m_editTextHeight; //���ָ߶ȵı༭��ؼ�
    CAcUiNumericEdit m_editTextWidthFactor; //���ֿ�����ӵı༭��ؼ�
    CAcUiTrueColorComboBox m_comboTextColor; //������ɫ����Ͽ�ؼ�
    CComboBox m_comboAlignment; //��Ԫ����뷽ʽ����Ͽ�ؼ�
    CAcUiLineWeightComboBox m_comboLineWidth; //����߿����Ͽ�ؼ�
    CAcUiLineTypeComboBox m_comboLineType; //������͵���Ͽ�ؼ�
    CAcUiTrueColorComboBox m_comboLineColor; //����߿���ɫ����Ͽ�ؼ�

    //����
public:
    const CArxProjectHelper::TableContent&
        getTableContent() const                              {return m_aTableContent;}
    const AcDbObjectId& getTextStyle() const                 {return m_TextStyleId;  }
    double getTextHeight() const                             {return m_dTextHeight;  }
    double getTextWidthFactor() const                        {return m_dWidthFactor; }
    const AcCmColor& getTextColor() const                    {return m_TextColor;    }
    int getRowCount() const                                  {return m_iRowNum;      }
    int getColumnCount() const                               {return m_iColumnNum;   }
    AcDb::CellAlignment getCellAlignment() const             {return m_CellAlignment;}
    AcDb::LineWeight getLineWeight() const                   {return m_LineWeight;   }
    const AcDbObjectId& getLineType() const                  {return m_LineTypeId;   }
    const AcCmColor& getLineColor() const                    {return m_LineColor;    }

private:
    // �Ի��򵯳�ʱ��ʼ���ؼ�
    void InitCtrl(void);
    virtual BOOL OnInitDialog();
    afx_msg void OnBnClickedOk();
    afx_msg void OnEnUpdateTableRownum();
    afx_msg void OnEnUpdateTableColumnnum();
    afx_msg void OnEnKillfocusTextHeight();
    afx_msg void OnEnKillfocusTextWidthfactor();
};

