#ifndef HTMLPARAGRAPH_H
#define HTMLPARAGRAPH_H

#include <QWidget>
#include "domelement.h"

/**
 * @brief Represents the <p> HTML tag.
 */
class HtmlParagraph : public DomElement
{
public:
    HtmlParagraph(QWidget *parent = 0);
    int getType();
    QString toHtml();
};

#endif // HTMLPARAGRAPH_H
