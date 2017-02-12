#ifndef HTMLITALIC_H
#define HTMLITALIC_H

#include <QMap>
#include <QWidget>
#include "domelement.h"

class HtmlItalic : public DomElement
{
public:
    HtmlItalic(QWidget *parent = 0);
    int getType();
    QMap<QString, QString> getAttributes();
    void setAttributes(QMap<QString, QString> attrs);
    QString toHtml();
private:
    int type;
    QMap<QString, QString> attributes;
};

#endif // HTMLITALIC_H
