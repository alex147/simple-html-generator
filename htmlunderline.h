#ifndef HTMLUNDERLINE_H
#define HTMLUNDERLINE_H

#include <QMap>
#include <QWidget>
#include "domelement.h"

class HtmlUnderline : public DomElement
{
public:
    HtmlUnderline(QWidget *parent = 0);
    int getType();
    QMap<QString, QString> getAttributes();
    void setAttributes(QMap<QString, QString> attrs);
    QString toHtml();
private:
    int type;
    QMap<QString, QString> attributes;
};

#endif // HTMLUNDERLINE_H
