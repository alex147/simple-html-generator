#include "htmlbold.h"

HtmlBold::HtmlBold(QWidget* parent)
    : DomElement(parent)
{
    type = 6;
    attributes.insert("Text", "");
}

int HtmlBold::getType()
{
    return this->type;
}

QMap<QString, QString> HtmlBold::getAttributes()
{
    return this->attributes;
}

void HtmlBold::setAttributes(QMap<QString, QString> attrs)
{
    this->attributes = attrs;
}

QString HtmlBold::toHtml()
{
    return "";
}
