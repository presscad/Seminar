//////////////////////////////////////////////////////////////////////////
// ������ʾ�鶨��Ԥ��ͼ�Ŀؼ��࣬ʹ��AcGs��ʵ��
//
//////////////////////////////////////////////////////////////////////////

#pragma once


// CStaticEx

class CStaticEx : public CStatic
{
	DECLARE_DYNAMIC(CStaticEx)

public:
	CStaticEx();
	virtual ~CStaticEx();

public:
    //----------------------------------------------------------
    // Summary:
    //    ��ʼ��Model��View��Device
    // Parameter:
    // Returns:
    //    BOOL
    //----------------------------------------------------------
    BOOL Init();

    //----------------------------------------------------------
    // Summary:
    //    Ԥ����ͼ��
    // Parameter:
    //    lpszBlockName - ������
    // Returns:
    //    void
    //----------------------------------------------------------
    void PreviewIcon(LPCTSTR lpszBlockName = ACDB_MODEL_SPACE);

protected:
	DECLARE_MESSAGE_MAP()

private:
    afx_msg void OnPaint();
    
private:
    AcGsView *m_pView;
    AcGsDevice *m_pDevice;
    AcGsModel *m_pModel;
};


