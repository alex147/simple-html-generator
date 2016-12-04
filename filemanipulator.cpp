#include "filemanipulator.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QtXmlPatterns>
#include <QUrl>

FileManipulator::FileManipulator()
{
    QUrl schemaUrl("qrc:///html_schema.xsd");
    QXmlSchema schema;
    schema.load(schemaUrl);

    if (schema.isValid()) {
        xml_validator = new QXmlSchemaValidator(schema);
    } else
    {
        exit(1);
    }
}

void FileManipulator::save_to_file(QString string, QString fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(Q_NULLPTR, "Unable to open file",
            file.errorString());
        return;
    }
    QTextStream out(&file);
    out << string;
    file.close();
}

QString FileManipulator::read_from_file(QString fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(Q_NULLPTR, "Unable to open file",
            file.errorString());
        return "";
    }

    if (!xml_validator->validate(QUrl::fromLocalFile(file.fileName())))
    {
        QMessageBox::information(
                Q_NULLPTR,
                "Unsupported file format",
                "The format of the input file is not supported. "
                "Please verify that you have chosen a valid HTML file.");
        return "";
    }

    QTextStream in(&file);
    QString fileContent;
    while (!in.atEnd())
    {
        fileContent += in.readLine() + "\n";
    }
    file.close();

    return fileContent;
}
