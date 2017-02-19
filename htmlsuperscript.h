#ifndef HTMLSUPERSCRIPT_H
#define HTMLSUPERSCRIPT_H

#include <QWidget>
#include "domelement.h"

/**
 * @brief Represents the <sup> HTML tag.
 */
class HtmlSuperscript : public DomElement
{
public:
    HtmlSuperscript(QWidget *parent = 0);
    int getType();
    QString toHtml();
};

#endif // HTMLSUPERSCRIPT_H
