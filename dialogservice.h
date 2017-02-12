#ifndef DIALOGSERVICE_H
#define DIALOGSERVICE_H

#include <QMap>

class DialogService
{
public:
    DialogService();
    QMap<QString, QString> showDialog(QMap<QString, QString> &inputMap);
};

#endif // DIALOGSERVICE_H
