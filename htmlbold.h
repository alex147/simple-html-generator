#ifndef HTMLBOLD_H
#define HTMLBOLD_H

#include <QMap>
#include <QWidget>
#include "domelement.h"

class HtmlBold : public DomElement
{
public:
    HtmlBold(QWidget *parent = 0);
    int getType();
    QMap<QString, QString> getAttributes();
    void setAttributes(QMap<QString, QString> attrs);
    QString toHtml();
private:
    int type;
    QMap<QString, QString> attributes;
};

#endif // HTMLBOLD_H
