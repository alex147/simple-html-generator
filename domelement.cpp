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
