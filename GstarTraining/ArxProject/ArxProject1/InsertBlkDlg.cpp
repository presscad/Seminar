// InsertBlkDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "resource.h"
#include "ArxProjectHelper.h"
#include "InsertBlkDlg.h"
#include "afxdialogex.h"


// CInsertBlkDlg �Ի���

IMPLEMENT_DYNAMIC(CInsertBlkDlg, CDialogEx)

CInsertBlkDlg::CInsertBlkDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInsertBlkDlg::IDD, pParent)
    , m_hBmp(0)
{

}

CInsertBlkDlg::~CInsertBlkDlg()
{
    DeleteObject(m_hBmp);
}

void CInsertBlkDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_BLKNAME, m_comboBlkName);
    DDX_Control(pDX, IDC_LIST_ATTR, m_listAttr);
    DDX_Control(pDX, IDC_EDIT_VALUE, m_editValue);
    DDX_Control(pDX, IDC_PIC, m_pic);
}


BEGIN_MESSAGE_MAP(CInsertBlkDlg, CDialogEx)
    ON_CBN_SELCHANGE(IDC_COMBO_BLKNAME, &CInsertBlkDlg::OnCbnSelchangeComboBlkname)
    ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_ATTR, &CInsertBlkDlg::OnLvnItemchangedListAttr)
    ON_EN_CHANGE(IDC_EDIT_VALUE, &CInsertBlkDlg::OnEnChangeEditValue)
    ON_BN_CLICKED(IDOK, &CInsertBlkDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CInsertBlkDlg ��Ϣ�������


BOOL CInsertBlkDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // TODO:  �ڴ���Ӷ���ĳ�ʼ��
    //���ÿ������б�ؼ��ı��⼰��ʽ
    m_listAttr.InsertColumn(0, _T("���"), LVCFMT_LEFT, 100);
    m_listAttr.InsertColumn(1, _T("��ʾ"), LVCFMT_LEFT, 100);
    m_listAttr.InsertColumn(2, _T("��ֵ"), LVCFMT_LEFT, 100);
    m_listAttr.SetExtendedStyle(LVS_EX_FULLROWSELECT);

    //����Combobox��ʾ�Ŀ�����
    AcStringArray aGroupName;
    CArxProjectHelper::getSymbolRecord<AcDbBlockTable>(aGroupName);
    int len = aGroupName.length();
    for (int i = 0; i < len; ++i) {
        CString strBuf = aGroupName.at(i).kACharPtr();
        if (strBuf.Compare(ACDB_MODEL_SPACE)
            && strBuf.Compare(ACDB_PAPER_SPACE)
            && strBuf.Compare(_T("*Paper_Space0"))
            && strBuf.Compare(_T("*T"))) {
                m_comboBlkName.AddString(strBuf);
        }
        else {
            continue; //������ģ�Ϳռ䡢ͼֽ�ռ�ͱ�񣬺���
        }
    }

    //Combobox����Ŀʱ���༭���ȷ����ť�û�
    if (-1 == m_comboBlkName.SetCurSel(0)) {
        GetDlgItem(IDOK)->EnableWindow(FALSE);
        m_editValue.EnableWindow(FALSE); 
    }
    else
        OnCbnSelchangeComboBlkname();

    return TRUE;  // return TRUE unless you set the focus to a control
    // �쳣: OCX ����ҳӦ���� FALSE
}


void CInsertBlkDlg::OnCbnSelchangeComboBlkname()
{
    CString strBlkName;
    int iCurIndex = m_comboBlkName.GetCurSel();
    if (-1 == iCurIndex) return;

    m_listAttr.DeleteAllItems();

    m_comboBlkName.GetLBText(iCurIndex, strBlkName);
    bool bRet = CArxProjectHelper::getBlockAttribute(m_aBlkAttr, m_blkDefId, strBlkName);
    assert(bRet);
    if (!bRet) return; //��ȡ�鶨���Idʧ�ܣ�����

    //��ʾ�鶨�������ͼ
    CDC *pDC = m_pic.GetDC();
    BITMAP bmp; //Ϊ�˻�ȡλͼ���
    CRect rcClient; //Ϊ�˻�ȡ�ؼ����
    if (m_hBmp) DeleteObject(m_hBmp);
    m_hBmp = CArxProjectHelper::getBlockPreviewBitmap(m_blkDefId, pDC->GetSafeHdc());
    ::GetObject((HANDLE) m_hBmp, sizeof(BITMAP), (LPVOID) &bmp);
    m_pic.GetClientRect(rcClient);
    m_pic.DrawBitmap(m_hBmp, rcClient.right, rcClient.bottom, bmp.bmWidth, bmp.bmHeight);
    ReleaseDC(pDC);

    if (m_aBlkAttr.IsEmpty()) {
        //������ʱ�����༭����ղ��û�
        m_editValue.EnableWindow(FALSE);
        m_editValue.SetWindowText(_T(""));
        return;
    }
    else {
        m_editValue.EnableWindow(TRUE);
    }

    INT_PTR len = m_aBlkAttr.GetCount();
    for (int i = 0; i < len; ++i) {
        const CArxProjectHelper::BlockAttribute* pBlkAttr = (&m_aBlkAttr.GetAt(i));
        m_listAttr.InsertItem(i, pBlkAttr->getTag());
        m_listAttr.SetItemText(i, 1, pBlkAttr->getPompt());
        m_listAttr.SetItemText(i, 2, pBlkAttr->getTextString());
    }

    //Ĭ�ϵ�һ������ѡ���Ҿ��н���
    m_listAttr.SetItemState(0, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
}


void CInsertBlkDlg::OnLvnItemchangedListAttr(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
    
    if (LVIF_STATE == pNMLV->uChanged) {
        if (LVIS_SELECTED & pNMLV->uNewState) {
            //�ñ༭��ʧȥ���㣬�����������ִ��ʱ������EN_CHANGE�¼�ʱ�༭���ж�
            //�н��㣬OnEnChangeEditValue�Ὣ�߿����ݸ���ListCtrl����һ��Item
            m_listAttr.SetFocus();
            m_editValue.SetWindowText(m_listAttr.GetItemText(pNMLV->iItem, 2));
            m_editValue.SetFocus();
            m_editValue.SetSel(0, -1);
        }
    }

    *pResult = 0;
}

void CInsertBlkDlg::OnEnChangeEditValue()
{
    if ((CWnd*) &m_editValue != GetFocus()) return; //�༭���޽���ʱ�����в���

    CString strBuf;
    m_editValue.GetWindowText(strBuf);

    //���¿������б�ؼ��������������е�����ֵ��TextString��
    int index = m_listAttr.GetSelectionMark();
    m_listAttr.SetItemText(index, 2, strBuf);
    m_aBlkAttr[index].setTextString(strBuf);
}

void CInsertBlkDlg::OnBnClickedOk()
{
    //����ȡ�Ŀ鶨���Ƿ���Ч�������ã�
    assert(m_blkDefId.isValid());
    CDialogEx::OnOK();
}

