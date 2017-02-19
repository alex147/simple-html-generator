#ifndef HTMLANCHOR_H
#define HTMLANCHOR_H

#include <QWidget>
#include "domelement.h"

class HtmlAnchor : public DomElement
{
public:
    HtmlAnchor(QWidget *parent = 0);
    int getType();
    QString toHtml();
};

#endif // HTMLANCHOR_H
