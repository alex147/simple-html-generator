#ifndef HTMLITALIC_H
#define HTMLITALIC_H

#include <QWidget>
#include "domelement.h"

/**
 * @brief Represents the <i> HTML tag.
 */
class HtmlItalic : public DomElement
{
public:
    HtmlItalic(QWidget *parent = 0);
    int getType();
    QString toHtml();
};

#endif // HTMLITALIC_H
