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
    QString toHtml();
};


#endif // HTMLIMAGE_H
