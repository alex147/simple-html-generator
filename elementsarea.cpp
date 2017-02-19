#include "elementsarea.h"
#include "flowlayout.h"
#include "mainwindow.h"
#include "htmlheading.h"
#include "htmlparagraph.h"
#include "htmlunderline.h"
#include "htmlstrikethrough.h"
#include "htmlitalic.h"
#include "htmlbold.h"
#include "htmlimage.h"
#include "htmlanchor.h"
#include "htmlsubscript.h"
#include "htmlsuperscript.h"

#include <QtWidgets>
#include <QLayout>

ElementsArea::ElementsArea()
    : DragWidget()
{
    setAcceptDrops(false);
    setStyleSheet("background-color:#C3C3C3");

    // All available HTML elements should be included here.
    HtmlAnchor *anchor = new HtmlAnchor();
    anchor->setPixmap(MainWindow::awesome->icon( fa::anchor ).pixmap(48,48));
    anchor->setAttribute(Qt::WA_DeleteOnClose);

    HtmlImage *image = new HtmlImage();
    image->setPixmap(MainWindow::awesome->icon( fa::pictureo ).pixmap(48,48));
    image->setAttribute(Qt::WA_DeleteOnClose);

    HtmlHeading *heading = new HtmlHeading();
    heading->setPixmap(MainWindow::awesome->icon( fa::header ).pixmap(48,48));
    heading->setAttribute(Qt::WA_DeleteOnClose);

    HtmlParagraph *paragraph = new HtmlParagraph();
    paragraph->setPixmap(MainWindow::awesome->icon( fa::paragraph ).pixmap(48,48));
    paragraph->setAttribute(Qt::WA_DeleteOnClose);

    HtmlBold *bold = new HtmlBold();
    bold->setPixmap(MainWindow::awesome->icon( fa::bold ).pixmap(48,48));
    bold->setAttribute(Qt::WA_DeleteOnClose);

    HtmlItalic *italic = new HtmlItalic();
    italic->setPixmap(MainWindow::awesome->icon( fa::italic ).pixmap(48,48));
    italic->setAttribute(Qt::WA_DeleteOnClose);

    HtmlUnderline *underline = new HtmlUnderline();
    underline->setPixmap(MainWindow::awesome->icon( fa::underline ).pixmap(48,48));
    underline->setAttribute(Qt::WA_DeleteOnClose);

    HtmlStrikethrough *strikethrough = new HtmlStrikethrough();
    strikethrough->setPixmap(MainWindow::awesome->icon( fa::strikethrough ).pixmap(48,48));
    strikethrough->setAttribute(Qt::WA_DeleteOnClose);

    HtmlSubscript *subscript = new HtmlSubscript();
    subscript->setPixmap(MainWindow::awesome->icon( fa::subscript ).pixmap(48,48));
    subscript->setAttribute(Qt::WA_DeleteOnClose);

    HtmlSuperscript *superscript = new HtmlSuperscript();
    superscript->setPixmap(MainWindow::awesome->icon( fa::superscript ).pixmap(48,48));
    superscript->setAttribute(Qt::WA_DeleteOnClose);

    FlowLayout* layout = new FlowLayout(this);
    layout->addWidget(anchor);
    layout->addWidget(image);
    layout->addWidget(heading);
    layout->addWidget(paragraph);
    layout->addWidget(bold);
    layout->addWidget(italic);
    layout->addWidget(underline);
    layout->addWidget(strikethrough);
    layout->addWidget(subscript);
    layout->addWidget(superscript);
}
