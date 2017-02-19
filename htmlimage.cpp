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
    return  QString("<img src='%1' alt='%2' height='%3' width='%4'>")
            .arg(attributes.value("Source"),
                 attributes.value("Alternative text"),
                 attributes.value("Height"),
                 attributes.value("Width"));
}
