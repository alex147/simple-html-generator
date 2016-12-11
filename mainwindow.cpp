#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "droparea.h"
#include "elementsarea.h"

#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QHBoxLayout>

QtAwesome* MainWindow::awesome = new QtAwesome( qApp );

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    awesome->initFontAwesome();

    QLayout* layout = createDesignerLayout();
    ui->designerTab->setLayout(layout);

    fileManipulator = new FileManipulator();
}

MainWindow::~MainWindow()
{
    delete ui;
}

QLayout* MainWindow::createDesignerLayout()
{
    QWidget* dropArea = new DropArea();
    dropArea->setObjectName("dropArea");
    QWidget* elementsArea = new ElementsArea();

    QSizePolicy dropAreaSizePolicy = dropArea->sizePolicy();
    dropAreaSizePolicy.setHorizontalStretch(9);
    dropArea->setSizePolicy(dropAreaSizePolicy);

    QSizePolicy elementsAreaSizePolicy = elementsArea->sizePolicy();
    elementsAreaSizePolicy.setHorizontalStretch(1);
    elementsArea->setSizePolicy(elementsAreaSizePolicy);
    elementsArea->setMinimumWidth(100);

    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(dropArea);
    layout->addWidget(elementsArea);

    return layout;
}

void MainWindow::on_actionNew_triggered()
{
    if (!showProgressLossWarning())
    {
        return;
    }

    ui->previewText->setPlainText("");
    qDeleteAll(ui->designerTab->findChild<QObject *>("dropArea")->findChildren<QLabel *>());
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(
            this,
            "Save to file",
            QDir::homePath(),
            FILTER,
            &SELECTED_FILTER);

    if (fileName.isEmpty())
        return;

    fileManipulator->save_to_file(ui->previewText->toPlainText(),
                                  fileName);
}

void MainWindow::on_actionOpen_triggered()
{
    if (!showProgressLossWarning())
    {
        return;
    }

    QString fileName = QFileDialog::getOpenFileName(
            this,
            "Open file",
            QDir::homePath(),
            FILTER,
            &SELECTED_FILTER);

    if (fileName.isEmpty())
        return;

    QString fileContent = fileManipulator->read_from_file(fileName);
    ui->previewText->setPlainText(fileContent);
}

bool MainWindow::showProgressLossWarning()
{
    if (ui->previewText->toPlainText() != "")
    {
        QString warningMessage =
                "Opening another file will "
                "erase all your unsaved progress. "
                "Proceed anyway?";

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(
                this,
                "Unsaved progress",
                warningMessage,
                QMessageBox::Yes|QMessageBox::No);

        if (reply == QMessageBox::No)
           return false;
    }

    return true;
}
