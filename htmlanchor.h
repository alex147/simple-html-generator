#ifndef HTMLANCHOR_H
#define HTMLANCHOR_H

#include <QMap>
#include <QWidget>
#include "domelement.h"

class HtmlAnchor : public DomElement
{
public:
    HtmlAnchor(QWidget *parent = 0);
    int getType();
    QMap<QString, QString> getAttributes();
    void setAttributes(QMap<QString, QString> attrs);
    QString toHtml();
private:
    int type;
    QMap<QString, QString> attributes;
};

#endif // HTMLANCHOR_H
