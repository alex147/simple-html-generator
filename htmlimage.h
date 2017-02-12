#ifndef HTMLIMAGE_H
#define HTMLIMAGE_H

#include <QMap>
#include <QWidget>
#include "domelement.h"

class HtmlImage : public DomElement
{
public:
    HtmlImage(QWidget *parent = 0);
    int getType();
    QMap<QString, QString> getAttributes();
    void setAttributes(QMap<QString, QString> attrs);
    QString toHtml();
private:
    int type;
    QMap<QString, QString> attributes;
};


#endif // HTMLIMAGE_H
