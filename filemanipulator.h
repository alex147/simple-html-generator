#ifndef FILEMANIPULATOR_H
#define FILEMANIPULATOR_H

#include <QString>
#include <QtXmlPatterns>

class FileManipulator
{
public:
    FileManipulator();
    void save_to_file(QString string, QString fileName);
    QString read_from_file(QString fileName);
private:
    QXmlSchemaValidator* xml_validator;
};

#endif // FILEMANIPULATOR_H
