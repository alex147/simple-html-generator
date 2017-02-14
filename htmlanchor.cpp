#include "htmlanchor.h"

HtmlAnchor::HtmlAnchor(QWidget* parent)
    : DomElement(parent)
{
    attributes.insert("Text", "");
    attributes.insert("Link", "");
}

int HtmlAnchor::getType()
{
    return DomElement::ANCHOR_TYPE;
}

QString HtmlAnchor::toHtml()
{
    return "";
}
