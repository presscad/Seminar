#include "mainwnd.h"
#include <QtGui/QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());        //֧��Tr����
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale()); //֧�������ļ�����ʾ

    QApplication a(argc, argv);
    mainWnd w;
    w.show();
    return a.exec();
}
