#include "domelement.h"

DomElement::DomElement(QWidget *parent)
    : QLabel(parent)
{
    this->isDoubleClickEnabled = false;
}

void DomElement::setDoubleClickEnabled(bool isDoubleClickEnabled)
{
    this->isDoubleClickEnabled = isDoubleClickEnabled;
}

bool DomElement::getDoubleClickEnabled()
{
    return this->isDoubleClickEnabled;
}

QMap<QString, QString> DomElement::getAttributes()
{
    return this->attributes;
}

void DomElement::setAttributes(QMap<QString, QString> attrs)
{
    this->attributes = attrs;
}
