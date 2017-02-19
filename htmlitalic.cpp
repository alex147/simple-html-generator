#include "htmlitalic.h"

HtmlItalic::HtmlItalic(QWidget* parent)
    : DomElement(parent)
{
    attributes.insert("Text", "");
}

int HtmlItalic::getType()
{
    return DomElement::ITALIC_TYPE;
}

QString HtmlItalic::toHtml()
{
    return  QString("<i>%1</i>")
            .arg(attributes.value("Text"));

}
