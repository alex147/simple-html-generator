#ifndef HTMLHEADING_H
#define HTMLHEADING_H

#include <QWidget>
#include "domelement.h"

/**
 * @brief Represents all HTML heading tags <h1> to <h6>.
 *
 * The significance of the heading is determined by the user input.
 */
class HtmlHeading : public DomElement
{
public:
    HtmlHeading(QWidget *parent = 0);
    int getType();
    QString toHtml();
};

#endif // HTMLHEADING_H
