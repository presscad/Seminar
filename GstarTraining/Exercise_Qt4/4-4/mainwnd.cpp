#include "mainwnd.h"
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QMessageBox>
#include "popupwnd.h"
#include "StudentModel.h"
#include "AccessDBA.h"

mainWnd::mainWnd(QWidget *parent, Qt::WFlags flags)
    : QWidget(parent, flags)
{
    ui.setupUi(this);
    connect(ui.btnAdd, SIGNAL(clicked()),
        this, SLOT(onBtnAdd()));
    connect(ui.btnRemove, SIGNAL(clicked()),
        this, SLOT(onBtnRemove()));
    connect(ui.tableView, SIGNAL(doubleClicked(const QModelIndex&)),
        this, SLOT(onTableViewDoubleClicked(const QModelIndex&)));

    m_database = new AccessDBA;
    m_model = new StudentModel;

    if (m_database->open()) {
        m_model->create(parent, m_database->database());
        m_model->setView(ui.tableView);
        m_model->select();
        ui.tableView->resizeColumnsToContents();
    } else {
        QMessageBox::critical(this, QString("��Ϣ����"),
            QString("�޷��������ݿ����ӣ�ϵͳ�޷��ҵ����ݿ��ļ�TestDataBase.mdb"));
        exit(0);
    }
}

mainWnd::~mainWnd()
{
    delete m_database;
    delete m_model;
}

void mainWnd::onBtnAdd()
{
    popupWnd wnd(this);
    if (wnd.exec() == QDialog::Accepted) {
        if (!m_model->insert(wnd.ui.editName->text(),
            wnd.ui.cboSex->currentText(),
            wnd.ui.spinAge->value(),
            wnd.ui.editAddress->text())) {
            QMessageBox::warning(this, QString("����"), QString("�������ݼ�¼ʧ�ܡ�"));
            m_model->rollback();
        } else {
            m_model->submitAll();
        }
    }
}

void mainWnd::onBtnRemove()
{
    if (!m_model->remove(&(ui.tableView->selectionModel()->selectedIndexes()))) {
        QMessageBox::warning(this, QString("����"), QString("ɾ�����ݼ�¼ʧ�ܡ�"));
    } else {
        m_model->submitAll();
    }
}

void mainWnd::onTableViewDoubleClicked(const QModelIndex& index)
{
    popupWnd wnd(this);
    QSqlTableModel* table = m_model->table();
    QSqlRecord rcd = table->record(index.row());
    wnd.ui.editID->setText(rcd.value(0).toString());
    wnd.ui.editName->setText(rcd.value(1).toString());
    wnd.ui.cboSex->setCurrentIndex(rcd.value(2).toString() == "��" ? 0 : 1);
    wnd.ui.spinAge->setValue(rcd.value(3).toInt());
    wnd.ui.editAddress->setText(rcd.value(4).toString());

    if (wnd.exec() == QDialog::Accepted) {
        if (!m_model->update(index.row(),
            wnd.ui.editName->text(),
            wnd.ui.cboSex->currentText(),
            wnd.ui.spinAge->value(),
            wnd.ui.editAddress->text())) {
                QMessageBox::warning(this, QString("����"), QString("���ݿ����ʧ�ܡ�"));
        } else {
            m_model->submitAll();
        }
    }
}