#ifndef HTMLSTRIKETHROUGH_H
#define HTMLSTRIKETHROUGH_H

#include <QMap>
#include <QWidget>
#include "domelement.h"

class HtmlStrikethrough : public DomElement
{
public:
    HtmlStrikethrough(QWidget *parent = 0);
    int getType();
    QMap<QString, QString> getAttributes();
    void setAttributes(QMap<QString, QString> attrs);
    QString toHtml();
private:
    int type;
    QMap<QString, QString> attributes;
};

#endif // HTMLSTRIKETHROUGH_H
