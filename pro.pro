#-------------------------------------------------
#
# Project created by QtCreator 2014-03-11T13:42:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pro
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    contact.cpp \
    contacts.cpp \
    mymodelcontacts.cpp \
    contactview.cpp

HEADERS  += mainwindow.h \
    contact.h \
    contacts.h \
    mymodelcontacts.h \
    contactview.h

FORMS    += mainwindow.ui \
    contactview.ui

QMAKE_CXXFLAGS += -std=c++11
