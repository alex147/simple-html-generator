#ifndef DROPAREA_H
#define DROPAREA_H

#include "dragwidget.h"

/**
 * Subclass of the DragWidget that accepts drops.
 * Acts as a designer pane where user drops HTML elements.
 */
class DropArea : public DragWidget
{
public:
    DropArea();
};

#endif // DROPAREA_H
