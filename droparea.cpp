#include "droparea.h"

#include <QtWidgets>

DropArea::DropArea()
    : DragWidget()
{
    setAcceptDrops(true);
}
