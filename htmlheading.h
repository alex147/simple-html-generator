#ifndef HTMLHEADING_H
#define HTMLHEADING_H

#include <QWidget>
#include "domelement.h"

class HtmlHeading : public DomElement
{
public:
    HtmlHeading(QWidget *parent = 0);
    int getType();
    QString toHtml();
};

#endif // HTMLHEADING_H
