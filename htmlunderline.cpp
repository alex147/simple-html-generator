#include "htmlunderline.h"

HtmlUnderline::HtmlUnderline(QWidget* parent)
    : DomElement(parent)
{
    attributes.insert("Text", "");
}

int HtmlUnderline::getType()
{
    return DomElement::UNDERLINE_TYPE;
}

QString HtmlUnderline::toHtml()
{
    return  QString("<u>%1</u>")
            .arg(attributes.value("Text"));
}
