#include "htmlheading.h"

HtmlHeading::HtmlHeading(QWidget* parent)
    : DomElement(parent)
{
    attributes.insert("Significance 1-6", "1");
    attributes.insert("Text", "");
}

int HtmlHeading::getType()
{
    return DomElement::HEADING_TYPE;
}

QString HtmlHeading::toHtml()
{
    return  QString("<h%1>%2</h%3>")
            .arg(attributes.value("Significance 1-6"),
                 attributes.value("Text"),
                 attributes.value("Significance 1-6"));
}
