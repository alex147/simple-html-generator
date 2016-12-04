#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <filemanipulator.h>

#include <QMainWindow>
#include <QString>

namespace Ui {
class MainWindow;
}

QString readStyleSheet();

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();
    void on_actionSave_triggered();
    void on_actionOpen_triggered();
    void on_actionNew_triggered();

private:
    bool showProgressLossWarning();
    Ui::MainWindow *ui;
    FileManipulator* fileManipulator;
    QString FILTER = "All files (*.*);;HTML files (*.html);; Text files (*.txt)";
    QString SELECTED_FILTER = "HTML files (*.html)";
};

#endif // MAINWINDOW_H
