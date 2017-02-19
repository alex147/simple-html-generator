#include "htmlsuperscript.h"

HtmlSuperscript::HtmlSuperscript(QWidget* parent)
    : DomElement(parent)
{
    attributes.insert("Text", "");
}

int HtmlSuperscript::getType()
{
    return DomElement::SUPERSCRIPT_TYPE;
}

QString HtmlSuperscript::toHtml()
{
    return  QString("<sup>%1</sup>")
            .arg(attributes.value("Text"));
}
