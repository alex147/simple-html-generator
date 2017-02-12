#include "htmlimage.h"

HtmlImage::HtmlImage(QWidget* parent)
    : DomElement(parent)
{
    type = 7;
    attributes.insert("Source", "");
    attributes.insert("Alternative text", "");
    attributes.insert("Width", "");
    attributes.insert("Height", "");
}

int HtmlImage::getType()
{
    return this->type;
}

QMap<QString, QString> HtmlImage::getAttributes()
{
    return this->attributes;
}

void HtmlImage::setAttributes(QMap<QString, QString> attrs)
{
    this->attributes = attrs;
}

QString HtmlImage::toHtml()
{
    return "";
}
