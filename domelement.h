#ifndef DOMELEMENT_H
#define DOMELEMENT_H

#include <QLabel>
#include <QMap>

class DomElement : public QLabel
{
public:
    DomElement(QWidget *parent = 0);
    void setDoubleClickEnabled(bool isDoubleClickEnabled);
    bool getDoubleClickEnabled();
    virtual int getType() = 0;
    virtual QMap<QString, QString> getAttributes() = 0;
    virtual void setAttributes(QMap<QString, QString> attrs) = 0;
    virtual QString toHtml() = 0;
private:
    bool isDoubleClickEnabled;
};

#endif // DOMELEMENT_H
