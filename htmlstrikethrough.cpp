#include "htmlstrikethrough.h"

HtmlStrikethrough::HtmlStrikethrough(QWidget* parent)
    : DomElement(parent)
{
    type = 4;
    attributes.insert("Text", "");
}

int HtmlStrikethrough::getType()
{
    return this->type;
}

QMap<QString, QString> HtmlStrikethrough::getAttributes()
{
    return this->attributes;
}

void HtmlStrikethrough::setAttributes(QMap<QString, QString> attrs)
{
    this->attributes = attrs;
}

QString HtmlStrikethrough::toHtml()
{
    return "";
}
