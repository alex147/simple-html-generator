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
    QString toHtml();
};

#endif // HTMLPARAGRAPH_H
