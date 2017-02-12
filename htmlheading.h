#ifndef HTMLHEADING_H
#define HTMLHEADING_H

#include <QMap>
#include <QWidget>
#include "domelement.h"

class HtmlHeading : public DomElement
{
public:
    HtmlHeading(QWidget *parent = 0);
    int getType();
    QMap<QString, QString> getAttributes();
    void setAttributes(QMap<QString, QString> attrs);
    QString toHtml();
private:
    int type;
    QMap<QString, QString> attributes;
};

#endif // HTMLHEADING_H
