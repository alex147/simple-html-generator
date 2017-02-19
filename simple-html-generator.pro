#-------------------------------------------------
#
# Project created by QtCreator 2016-10-29T10:46:22
#
#-------------------------------------------------

QT       += core gui xmlpatterns

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = simple-html-generator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    filemanipulator.cpp \
    dragwidget.cpp \
    droparea.cpp \
    elementsarea.cpp \
    flowlayout.cpp \
    domelement.cpp \
    dialogservice.cpp \
    htmlheading.cpp \
    htmlparagraph.cpp \
    htmlunderline.cpp \
    htmlstrikethrough.cpp \
    htmlitalic.cpp \
    htmlbold.cpp \
    htmlimage.cpp \
    htmlanchor.cpp \
    htmlsubscript.cpp \
    htmlsuperscript.cpp

HEADERS  += mainwindow.h \
    filemanipulator.h \
    dragwidget.h \
    droparea.h \
    elementsarea.h \
    flowlayout.h \
    domelement.h \
    dialogservice.h \
    htmlheading.h \
    htmlparagraph.h \
    htmlunderline.h \
    htmlstrikethrough.h \
    htmlitalic.h \
    htmlbold.h \
    htmlimage.h \
    htmlanchor.h \
    htmlsubscript.h \
    htmlsuperscript.h

FORMS    += mainwindow.ui

RESOURCES += qdarkstyle/style.qrc \
    html_schema/html_schema.qrc \
    demo_resources/demo_resources.qrc

DISTFILES +=

include(QtAwesome/QtAwesome.pri)
