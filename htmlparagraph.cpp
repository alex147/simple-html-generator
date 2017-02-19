#include "htmlparagraph.h"

HtmlParagraph::HtmlParagraph(QWidget* parent)
    : DomElement(parent)
{
    attributes.insert("Text", "");
}

int HtmlParagraph::getType()
{
    return DomElement::PARAGRAPH_TYPE;
}

QString HtmlParagraph::toHtml()
{
    return  QString("<p>%1</p>")
            .arg(attributes.value("Text"));
}
