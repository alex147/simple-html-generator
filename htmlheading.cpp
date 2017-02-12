#include "htmlheading.h"

HtmlHeading::HtmlHeading(QWidget* parent)
    : DomElement(parent)
{
    type = 1;
    attributes.insert("Text", "");
}

int HtmlHeading::getType()
{
    return this->type;
}

QMap<QString, QString> HtmlHeading::getAttributes()
{
    return this->attributes;
}

void HtmlHeading::setAttributes(QMap<QString, QString> attrs)
{
    this->attributes = attrs;
}

QString HtmlHeading::toHtml()
{
    return "";
}
