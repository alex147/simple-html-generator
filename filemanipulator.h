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
    void saveToFile(QString string, QString fileName);
    QString readFromFile(QString fileName);
    bool isValidHtml(QString html);
private:
    /**
     * @brief The HTML validator used to validate opened files.
     */
    QXmlSchemaValidator* xml_validator;
};

#endif // FILEMANIPULATOR_H
