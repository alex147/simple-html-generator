#include "htmlunderline.h"

HtmlUnderline::HtmlUnderline(QWidget* parent)
    : DomElement(parent)
{
    type = 3;
    attributes.insert("Text", "");
}

int HtmlUnderline::getType()
{
    return this->type;
}

QMap<QString, QString> HtmlUnderline::getAttributes()
{
    return this->attributes;
}

void HtmlUnderline::setAttributes(QMap<QString, QString> attrs)
{
    this->attributes = attrs;
}

QString HtmlUnderline::toHtml()
{
    return "";
}
