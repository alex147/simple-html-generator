#ifndef FILEMANIPULATOR_H
#define FILEMANIPULATOR_H

#include <QString>
#include <QtXmlPatterns>

/**
 * @brief Class that handles file IO operations.
 */
class FileManipulator
{
public:
    FileManipulator();
    void save_to_file(QString string, QString fileName);
    QString read_from_file(QString fileName);
private:
    /**
     * @brief The HTML validator used to validate opened files.
     */
    QXmlSchemaValidator* xml_validator;
};

#endif // FILEMANIPULATOR_H
