#ifndef DIALOGSERVICE_H
#define DIALOGSERVICE_H

#include <QMap>

/**
 * @brief A service class responsible for displaying input dialogs.
 */
class DialogService
{
public:
    DialogService();
    QMap<QString, QString> showDialog(QMap<QString, QString> &inputMap);
};

#endif // DIALOGSERVICE_H
