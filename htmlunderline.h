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
    QString toHtml();
};

#endif // HTMLUNDERLINE_H
