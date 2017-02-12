#include "htmlparagraph.h"

HtmlParagraph::HtmlParagraph(QWidget* parent)
    : DomElement(parent)
{
    type = 2;
    attributes.insert("Text", "");
}

int HtmlParagraph::getType()
{
    return this->type;
}

QMap<QString, QString> HtmlParagraph::getAttributes()
{
    return this->attributes;
}

void HtmlParagraph::setAttributes(QMap<QString, QString> attrs)
{
    this->attributes = attrs;
}

QString HtmlParagraph::toHtml()
{
    return "";
}
