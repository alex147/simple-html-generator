#ifndef HTMLUNDERLINE_H
#define HTMLUNDERLINE_H

#include <QWidget>
#include "domelement.h"

/**
 * @brief Represents the <u> HTML tag.
 */
class HtmlUnderline : public DomElement
{
public:
    HtmlUnderline(QWidget *parent = 0);
    int getType();
    QString toHtml();
};

#endif // HTMLUNDERLINE_H
