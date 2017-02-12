#include "droparea.h"

#include <QtWidgets>

DropArea::DropArea()
    : DragWidget()
{
    setAcceptDrops(true);
    setStyleSheet("background-image:url(\":/qss_icons/rc/background.png\");"
                  "background-position: top left; "
                  "background-repeat: repeat-xy;");

}

void DropArea::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
