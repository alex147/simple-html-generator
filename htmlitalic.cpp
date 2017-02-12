#include "htmlitalic.h"

HtmlItalic::HtmlItalic(QWidget* parent)
    : DomElement(parent)
{
    type = 5;
    attributes.insert("Text", "");
}

int HtmlItalic::getType()
{
    return this->type;
}

QMap<QString, QString> HtmlItalic::getAttributes()
{
    return this->attributes;
}

void HtmlItalic::setAttributes(QMap<QString, QString> attrs)
{
    this->attributes = attrs;
}

QString HtmlItalic::toHtml()
{
    return "";
}
