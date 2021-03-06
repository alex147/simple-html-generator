#ifndef HTMLIMAGE_H
#define HTMLIMAGE_H

#include <QWidget>
#include "domelement.h"

/**
 * @brief Represents the <img> HTML tag.
 */
class HtmlImage : public DomElement
{
public:
    HtmlImage(QWidget *parent = 0);
    int getType();
    QString toHtml();
};


#endif // HTMLIMAGE_H
