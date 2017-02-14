#include "htmlimage.h"

HtmlImage::HtmlImage(QWidget* parent)
    : DomElement(parent)
{
    attributes.insert("Source", "");
    attributes.insert("Alternative text", "");
    attributes.insert("Width", "");
    attributes.insert("Height", "");
}

int HtmlImage::getType()
{
    return DomElement::IMAGE_TYPE;
}

QString HtmlImage::toHtml()
{
    return "";
}
