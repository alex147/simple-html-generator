#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <filemanipulator.h>
#include "dragwidget.h"
#include "droparea.h"
#include "elementsarea.h"
#include "QtAwesome.h"

#include <QMainWindow>
#include <QString>
#include <QLayout>

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

    /**
     * A public static reference to the QtAwesome,
     * so that it is available to all classes.
     */
    static QtAwesome* awesome;

private slots:
    void on_actionExit_triggered();
    void on_actionSave_triggered();
    void on_actionOpen_triggered();
    void on_actionNew_triggered();
    void on_actionAbout_triggered();

    void on_copyToClipButton_clicked();

    void on_translateButton_clicked();

private:
    bool showProgressLossWarning();

    QLayout* createDesignerLayout();

    Ui::MainWindow *ui;

    FileManipulator* fileManipulator;

    /**
     * @brief Filter for file open/save dialogs.
     */
    QString FILTER = "All files (*.*);;HTML files (*.html);; Text files (*.txt)";

    /**
     * @brief Default filter selection in file open/save dialogs.
     */
    QString SELECTED_FILTER = "HTML files (*.html)";
};

#endif // MAINWINDOW_H
