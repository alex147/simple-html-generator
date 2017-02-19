#ifndef HTMLSUBSCRIPT_H
#define HTMLSUBSCRIPT_H

#include <QWidget>
#include "domelement.h"

class HtmlSubscript : public DomElement
{
public:
    HtmlSubscript(QWidget *parent = 0);
    int getType();
    QString toHtml();
};

#endif // HTMLSUBSCRIPT_H
