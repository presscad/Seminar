#include "mainwnd.h"
#include <QMouseEvent>
#include <QMessageBox>

mainWnd::mainWnd(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags)
{
    ui.setupUi(this);
    setMouseTracking(true);
    ui.centralWidget->setMouseTracking(true);

    connect(ui.actionBtn1, SIGNAL(triggered(bool)),
        this, SLOT(onPopupMsg()));
}

mainWnd::~mainWnd()
{

}

void mainWnd::mouseMoveEvent(QMouseEvent* e)
{
    QPointF pt = e->posF();
    QString str = QString("��ǰ����: x=%1, y=%2").arg(pt.x()).arg(pt.y());
    ui.statusBar->showMessage(str);
}

void mainWnd::onPopupMsg()
{
    QMessageBox::information(this, QString("��Ϣ��ʾ"), QString("��ť1������"));
}
