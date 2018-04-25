#include "mainwnd.h"
#include <QtGui/QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());        //֧��Tr����
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale()); //֧�������ļ�����ʾ

    mainWnd w;
    w.show();
    return a.exec();
}
