#include "mainwnd.h"

mainWnd::mainWnd(QWidget *parent, Qt::WFlags flags)
    : QWidget(parent, flags)
{
    ui.setupUi(this);
    connect(ui.cboType, SIGNAL(currentIndexChanged(int)),
        this, SLOT(cboTypeSelectionChanged(int)));
    connect(ui.listList, SIGNAL(itemSelectionChanged()),
        this, SLOT(listListSelectionChanged()));

    map = new QMap<QString, QVector<QString> >;
    QVector<QString> vecFruit;
    QVector<QString> vecStudy;
    vecFruit.push_back(tr("����"));
    vecFruit.push_back(tr("��"));
    vecFruit.push_back(tr("⨺���"));
    vecFruit.push_back(tr("ƻ��"));
    vecStudy.push_back(tr("�ֱ�"));
    vecStudy.push_back(tr("�ʼǱ�"));
    vecStudy.push_back(tr("��Ƥ"));
    map->insert(tr("ˮ��"), vecFruit);
    map->insert(tr("ѧϰ��Ʒ"), vecStudy);

    cboTypeSelectionChanged(0);
}

mainWnd::~mainWnd()
{
    delete map;
}

void mainWnd::cboTypeSelectionChanged(int)
{
    ui.listList->clear();

    const QVector<QString>& aList = map->value(ui.cboType->currentText());
    for (int i = 0; i < aList.count(); ++i) {
        ui.listList->addItem(aList.at(i));
    }

    ui.listList->setCurrentItem(ui.listList->item(0));
}

void mainWnd::listListSelectionChanged()
{
    ui.lblSelected->setText(ui.listList->currentItem()->text());
}
