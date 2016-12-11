#ifndef DRAGWIDGET_H
#define DRAGWIDGET_H

#include <QFrame>

class QDragEnterEvent;
class QDropEvent;

class DragWidget : public QFrame
{
public:
    DragWidget(QWidget *parent = 0);

protected:
    void dragEnterEvent(QDragEnterEvent *event) Q_DECL_OVERRIDE;
    void dragMoveEvent(QDragMoveEvent *event) Q_DECL_OVERRIDE;
    void dropEvent(QDropEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
};

#endif // DRAGWIDGET_H
