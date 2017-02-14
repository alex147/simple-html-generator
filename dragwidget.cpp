#include "dragwidget.h"
#include "domelement.h"
#include "htmlheading.h"
#include "htmlparagraph.h"
#include "htmlunderline.h"
#include "htmlstrikethrough.h"
#include "htmlitalic.h"
#include "htmlbold.h"
#include "htmlimage.h"
#include "htmlanchor.h"

#include <QtWidgets>

/**
 * @brief Constructs a DragWidget object.
 * @param parent the parent widget of this DragWidget.
 */
DragWidget::DragWidget(QWidget *parent)
    : QFrame(parent)
{
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    dialogService = new DialogService();
}

void DragWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

/**
 * @brief Handler for the QDragEnterEvent.
 * @param event the QDragEnterEvent to handle.
 */
void DragWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}
/**
 * @brief Handler for the QDragMoveEvent.
 * @param event the QDragMoveEvent to handle.
 */
void DragWidget::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}
/**
 * @brief Handler for the QDropEvent.
 * @param event the QDropEvent to handle.
 */
void DragWidget::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        int type;
        dataStream >> pixmap >> offset >> type;

        // Create a new DomElement at the spot,
        // where the drop happened.
        DomElement *newElement = createDomElement(type);
        if (!tmp.isEmpty()) {
            newElement->setAttributes(tmp);
            tmp.clear();
        }

        newElement->setDoubleClickEnabled(true);
        newElement->setPixmap(pixmap);
        newElement->move(event->pos() - offset);
        newElement->show();
        newElement->setAttribute(Qt::WA_DeleteOnClose);

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

/**
 * @brief Creates a new {@link DomElement} object based on the given type.
 * @param type
 * @return A new {@link DomElement} object of the correct type.
 */
DomElement *DragWidget::createDomElement(int type)
{
    DomElement *newElement;
    switch(type)
    {
        case DomElement::HEADING_TYPE: newElement = new HtmlHeading(this); break;
        case DomElement::PARAGRAPH_TYPE: newElement = new HtmlParagraph(this); break;
        case DomElement::UNDERLINE_TYPE: newElement = new HtmlUnderline(this); break;
        case DomElement::STRIKETHROUGH_TYPE: newElement = new HtmlStrikethrough(this); break;
        case DomElement::ITALIC_TYPE: newElement = new HtmlItalic(this); break;
        case DomElement::BOLD_TYPE: newElement = new HtmlBold(this); break;
        case DomElement::IMAGE_TYPE: newElement = new HtmlImage(this); break;
        case DomElement::ANCHOR_TYPE:newElement = new HtmlAnchor(this); break;
    }

    return newElement;
}

/**
 * @brief Handler for the mouse press event.
 * @param event the QMouseEvent to handle.
 */
void DragWidget::mousePressEvent(QMouseEvent *event)
{
    DomElement *child = static_cast<DomElement*>(childAt(event->pos()));
    if (!child)
        return;

    tmp = child->getAttributes();

    QPixmap pixmap = *child->pixmap();

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << pixmap << QPoint(event->pos() - child->pos()) << child->getType();

    QMimeData *mimeData = new QMimeData;
    // Set a custom mime type, so that we can differentiate
    // drag & drop events from others.
    mimeData->setData("application/x-dnditemdata", itemData);

    // Start the actual drag.
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos() - child->pos());

    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
    painter.end();

    child->setPixmap(tempPixmap);

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
        child->close();
    } else {
        child->show();
        child->setPixmap(pixmap);
    }
}

/**
 * @brief Handler for the mouse double click event.
 *
 * NOTE: Keep in mind that the {@link mousePressEvent} handler
 * is always executed first on double click.
 *
 * @param event the QMouseEvent to handle.
 */
void DragWidget::mouseDoubleClickEvent(QMouseEvent * event)
{
    DomElement *child = static_cast<DomElement*>(childAt(event->pos()));
    if (!child)
        return;

    if (child->getDoubleClickEnabled())
    {
        QMap<QString, QString> result = dialogService->showDialog(child->getAttributes());
        if (!result.isEmpty()) {
            child->setAttributes(result);
        }
    }
}
