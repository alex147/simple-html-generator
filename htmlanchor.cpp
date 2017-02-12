#include "htmlanchor.h"

HtmlAnchor::HtmlAnchor(QWidget* parent)
    : DomElement(parent)
{
    type = 8;
    attributes.insert("Text", "");
    attributes.insert("Link", "");
}

int HtmlAnchor::getType()
{
    return this->type;
}

QMap<QString, QString> HtmlAnchor::getAttributes()
{
    return this->attributes;
}

void HtmlAnchor::setAttributes(QMap<QString, QString> attrs)
{
    this->attributes = attrs;
}

QString HtmlAnchor::toHtml()
{
    return "";
}
