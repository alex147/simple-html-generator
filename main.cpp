#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QString>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet(readStyleSheet());

    MainWindow w;
    w.showMaximized();

    return a.exec();
}

QString readStyleSheet()
{
    QFile f(":/qdarkstyle/style.qss");
    if(!f.exists())
    {
        return QString("");
    } else
    {
        f.open(QIODevice::ReadOnly);
        QTextStream ts(&f);
        QString styleString = ts.readAll();
        f.close();

        return styleString;
    }
}
