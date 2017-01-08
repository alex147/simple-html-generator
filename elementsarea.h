#ifndef ELEMENTSAREA_H
#define ELEMENTSAREA_H

#include "dragwidget.h"
#include "flowlayout.h"

/**
 * Subclass of the DragWidget that acts
 * as a container to all available HTML elements.
 * Does not accept drops.
 */
class ElementsArea : public DragWidget
{
public:
    ElementsArea();
};

#endif // ELEMENTSAREA_H
