#include "droparea.h"

#include <QtWidgets>

DropArea::DropArea()
    : DragWidget()
{
    setAcceptDrops(true);

    QPalette pal(palette());
    pal.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);
}
