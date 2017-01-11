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

/**
 * @brief Constructs the MainWindow object.
 * @param parent the parent QWidget of our window.
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize FontAwesome,
    // so that we can grab icons later.
    // Does not work without this step.
    awesome->initFontAwesome();

    QLayout* layout = createDesignerLayout();
    ui->designerTab->setLayout(layout);

    fileManipulator = new FileManipulator();
}

/**
 * @brief Default destructor.
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Creates the layout for the Designer tab.
 * @return The QLayout for the Designer tab,
 * that contains a DropArea and an ElementsArea
 * with the correct sizing rules.
 */
QLayout* MainWindow::createDesignerLayout()
{
    QWidget* dropArea = new DropArea();
    // Set the widget name, so that we
    // can reference it by name later.
    dropArea->setObjectName("dropArea");
    QWidget* elementsArea = new ElementsArea();

    // Set SizePolicy for the DropArea and the ElementsArea,
    // so that they are sized correctly in different window resolutions.
    // The horizontal size ratio between the two is 9:1.
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

/**
 * @brief Handler for the File > New menu item.
 */
void MainWindow::on_actionNew_triggered()
{
    if (!showProgressLossWarning())
    {
        return;
    }

    // Erase everything in the Preview tab.
    ui->previewText->setPlainText("");

    // Clear out all elements that have been dropped inside the Designer pane.
    qDeleteAll(ui->designerTab->findChild<QObject *>("dropArea")->findChildren<QLabel *>());
}

/**
 * @brief Handler for the File > Exit menu item.
 */
void MainWindow::on_actionExit_triggered()
{
    if (!showProgressLossWarning())
    {
        return;
    }

    // Close the application.
    QApplication::quit();
}

/**
 * @brief Handler for the File > Save menu item.
 */
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

/**
 * @brief Handler for the File > Open menu item.
 */
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

    // Set the Preview tab text to the contents of the file.
    ui->previewText->setPlainText(fileContent);
}

/**
 * @brief Displays a dialog that warns the user that they will lose any unsaved progress.
 * @return True if the user has decided to proceed regardless of the warning,
 * False otherwise.
 */
bool MainWindow::showProgressLossWarning()
{
    if (ui->previewText->toPlainText() != "" ||
            !ui->designerTab->findChild<QObject *>("dropArea")->findChildren<QLabel *>().empty())
    {
        QString warningMessage =
                "This action will "
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
