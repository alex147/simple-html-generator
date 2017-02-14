#ifndef HTMLSTRIKETHROUGH_H
#define HTMLSTRIKETHROUGH_H

#include <QMap>
#include <QWidget>
#include "domelement.h"

class HtmlStrikethrough : public DomElement
{
public:
    HtmlStrikethrough(QWidget *parent = 0);
    int getType();
    QString toHtml();
};

#endif // HTMLSTRIKETHROUGH_H
