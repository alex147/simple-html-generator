#include "dialogservice.h"

#include <QDialog>
#include <QFormLayout>
#include <QMap>
#include <QLineEdit>
#include <QLabel>
#include <QDialogButtonBox>
#include <QObject>

DialogService::DialogService()
{

}

/**
 * @brief Displays the Edit attributes dialog for a {@link DomElement}.
 * @param inputMap Contains a key-value pair for each available attribute on a given {@link DomElement}.
 * @return The updated map with attributes and values.
 */
QMap<QString, QString> DialogService::showDialog(QMap<QString, QString> &inputMap)
{
    QDialog dialog(Q_NULLPTR);
    dialog.setWindowTitle("Edit attributes");

    // Use a layout allowing to have a label next to each field
    QFormLayout form(&dialog);
    // Add some text above the fields
    form.addRow(new QLabel("Fill in the attribute values "
                           "for your HTML element in the input boxes below"));

    // Add the lineEdits with their respective labels
    QMap<QString, QLineEdit *> fields;
    for (QString key : inputMap.keys())
    {
        QLineEdit *lineEdit = new QLineEdit(&dialog);
        lineEdit->setText(inputMap.value(key));

        QString label = QString(key + ": ");
        form.addRow(label, lineEdit);

        fields.insert(key, lineEdit);
    }

    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    // Show the dialog as modal
    QMap<QString, QString> resultMap;
    if (dialog.exec() == QDialog::Accepted)
    {
        for (QString key : fields.keys()) {
            resultMap.insert(key, fields.value(key)->text());
        }
    }

    return resultMap;
}
