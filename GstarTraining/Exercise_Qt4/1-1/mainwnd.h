#ifndef MAINWND_H
#define MAINWND_H

#include <QtGui/QWidget>
#include "ui_mainwnd.h"

class mainWnd : public QWidget
{
    Q_OBJECT

public:
    mainWnd(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~mainWnd();

private:
    Ui::mainWndClass ui;

private slots:
    void edit1Changed(const QString&);
    void edit2Changed(const QString&);
};

#endif // MAINWND_H
