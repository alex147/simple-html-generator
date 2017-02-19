#include "htmlsubscript.h"

HtmlSubscript::HtmlSubscript(QWidget* parent)
    : DomElement(parent)
{
    attributes.insert("Text", "");
}

int HtmlSubscript::getType()
{
    return DomElement::SUBSCRIPT_TYPE;
}

QString HtmlSubscript::toHtml()
{
    return  QString("<sub>%1</sub>")
            .arg(attributes.value("Text"));
}

