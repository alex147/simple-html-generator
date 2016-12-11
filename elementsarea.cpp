#include "elementsarea.h"
#include "flowlayout.h"
#include "mainwindow.h"

#include <QtWidgets>
#include <QLayout>

ElementsArea::ElementsArea()
    : DragWidget()
{
    setAcceptDrops(false);

    QLabel *anchor = new QLabel();
    anchor->setPixmap(MainWindow::awesome->icon( fa::anchor ).pixmap(32,32));
    anchor->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *image = new QLabel();
    image->setPixmap(MainWindow::awesome->icon( fa::pictureo ).pixmap(32,32));
    image->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *bold = new QLabel();
    bold->setPixmap(MainWindow::awesome->icon( fa::bold ).pixmap(32,32));
    bold->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *italic = new QLabel();
    italic->setPixmap(MainWindow::awesome->icon( fa::italic ).pixmap(32,32));
    italic->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *header = new QLabel();
    header->setPixmap(MainWindow::awesome->icon( fa::header ).pixmap(32,32));
    header->setAttribute(Qt::WA_DeleteOnClose);

    FlowLayout* layout = new FlowLayout(this);
    layout->addWidget(anchor);
    layout->addWidget(image);
    layout->addWidget(bold);
    layout->addWidget(italic);
    layout->addWidget(header);
}
