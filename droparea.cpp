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

/**
 * @brief This function overrides {#link QWidget#paintEvent}.
 * This is done to ensure that custom stylesheets can be set for this element.
 * If this function is not overridden, stylesheets would not work!
 */
void DropArea::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
