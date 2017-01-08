#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QString>
#include <QFile>
#include <QTextStream>

/**
 * Application entry point.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // set the stylesheet for the whole application
    a.setStyleSheet(readStyleSheet());

    MainWindow w;
    // open the application in full screen
    w.showMaximized();

    return a.exec();
}

/**
 * @brief Reads the stylesheet file.
 * @return The contents of the stylesheet file as a QString
 * or an empty string if the file does not exist.
 */
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
