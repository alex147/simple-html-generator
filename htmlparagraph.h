#ifndef HTMLPARAGRAPH_H
#define HTMLPARAGRAPH_H

#include <QMap>
#include <QWidget>
#include "domelement.h"

class HtmlParagraph : public DomElement
{
public:
    HtmlParagraph(QWidget *parent = 0);
    int getType();
    QMap<QString, QString> getAttributes();
    void setAttributes(QMap<QString, QString> attrs);
    QString toHtml();
private:
    int type;
    QMap<QString, QString> attributes;
};

#endif // HTMLPARAGRAPH_H
