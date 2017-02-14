#include "htmlbold.h"

HtmlBold::HtmlBold(QWidget* parent)
    : DomElement(parent)
{
    attributes.insert("Text", "");
}

int HtmlBold::getType()
{
    return DomElement::BOLD_TYPE;
}

QString HtmlBold::toHtml()
{
    return "";
}
