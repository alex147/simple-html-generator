#include "htmlstrikethrough.h"

HtmlStrikethrough::HtmlStrikethrough(QWidget* parent)
    : DomElement(parent)
{
    attributes.insert("Text", "");
}

int HtmlStrikethrough::getType()
{
    return DomElement::STRIKETHROUGH_TYPE;
}

QString HtmlStrikethrough::toHtml()
{
    return "";
}
