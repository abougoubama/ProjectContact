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
        vue/mainwindow.cpp \
    modele/contact.cpp \
    modele/contacts.cpp \
    modele/mymodelcontacts.cpp \
    vue/contactview.cpp \
    modele/champ.cpp \
    modele/listechamps.cpp \
    modele/mymodellistechamps.cpp \
    modele/nom.cpp \
    modele/image.cpp

HEADERS  += vue/mainwindow.h \
    modele/contact.h \
    modele/contacts.h \
    mymodelcontacts.h \
    vue/contactview.h \
    modele/champ.h \
    modele/mymodelcontacts.h \
    modele/listechamps.h \
    modele/mymodellistechamps.h \
    modele/nom.h \
    modele/image.h

FORMS    += vue/mainwindow.ui \
    vue/contactview.ui

QMAKE_CXXFLAGS += -std=c++11
