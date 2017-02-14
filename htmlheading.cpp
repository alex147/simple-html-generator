#include "htmlheading.h"

HtmlHeading::HtmlHeading(QWidget* parent)
    : DomElement(parent)
{
    attributes.insert("Significance 1-6", "");
    attributes.insert("Text", "");
}

int HtmlHeading::getType()
{
    return DomElement::HEADING_TYPE;
}

QString HtmlHeading::toHtml()
{
    return "";
}
