#ifndef HTMLBOLD_H
#define HTMLBOLD_H

#include <QWidget>
#include "domelement.h"

class HtmlBold : public DomElement
{
public:
    HtmlBold(QWidget *parent = 0);
    int getType();
    QString toHtml();
};

#endif // HTMLBOLD_H
