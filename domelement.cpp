#include "domelement.h"

DomElement::DomElement(QWidget *parent)
    : QLabel(parent)
{
    this->isDoubleClickEnabled = false;
}

/**
 * @brief Default setter for the isDoubleClickEnabled property
 * @param isDoubleClickEnabled The new value to set
 */
void DomElement::setDoubleClickEnabled(bool isDoubleClickEnabled)
{
    this->isDoubleClickEnabled = isDoubleClickEnabled;
}

/**
 * @brief Default getter for the isDoubleClickEnabled property
 * @return The value of isDoubleClickEnabled
 */
bool DomElement::getDoubleClickEnabled()
{
    return this->isDoubleClickEnabled;
}

/**
 * @brief Default getter for the attributes property
 * @return The value of attributes
 */
QMap<QString, QString> DomElement::getAttributes()
{
    return this->attributes;
}

/**
 * @brief Default setter for the attributes property
 * @param attrs The new value to set
 */
void DomElement::setAttributes(QMap<QString, QString> attrs)
{
    this->attributes = attrs;
}
