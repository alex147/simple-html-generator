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
    filemanipulator.cpp

HEADERS  += mainwindow.h \
    filemanipulator.h

FORMS    += mainwindow.ui

RESOURCES += qdarkstyle/style.qrc \
    html_schema/html_schema.qrc \
    demo_resources/demo_resources.qrc

DISTFILES +=
