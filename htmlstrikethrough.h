#ifndef HTMLSTRIKETHROUGH_H
#define HTMLSTRIKETHROUGH_H

#include <QWidget>
#include "domelement.h"

/**
 * @brief Represents the <s> HTML tag.
 */
class HtmlStrikethrough : public DomElement
{
public:
    HtmlStrikethrough(QWidget *parent = 0);
    int getType();
    QString toHtml();
};

#endif // HTMLSTRIKETHROUGH_H
