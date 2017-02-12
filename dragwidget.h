#ifndef DRAGWIDGET_H
#define DRAGWIDGET_H

#include <QFrame>
#include <QMap>

#include "dialogservice.h"
#include "domelement.h"

class QDragEnterEvent;
class QDropEvent;

/**
 * @brief Base class that handles drap & drop actions.
 */
class DragWidget : public QFrame
{
public:
    DragWidget(QWidget *parent = 0);
protected:
    void dragEnterEvent(QDragEnterEvent *event) Q_DECL_OVERRIDE;
    void dragMoveEvent(QDragMoveEvent *event) Q_DECL_OVERRIDE;
    void dropEvent(QDropEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QMouseEvent * event) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event);
private:
    DomElement *createDomElement(int type);
    DialogService* dialogService;
    QMap<QString, QString> tmp;
};

#endif // DRAGWIDGET_H
