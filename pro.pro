#-------------------------------------------------
#
# Project created by QtCreator 2014-03-11T13:42:59
#
#-------------------------------------------------

QT       += core gui xml
QT += widgets

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
    modele/image.cpp \
    modele/texte.cpp \
    vue/ajouterchamp.cpp \
    vue/imageedit.cpp \
    vue/listechampsedit.cpp \
    modele/adresse.cpp \
    modele/email.cpp \
    vue/nouveaucontact.cpp \
    modele/tel.cpp \
    modele/enum.cpp \
    vue/enumedit.cpp

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
    modele/image.h \
    modele/texte.h \
    vue/ajouterchamp.h \
    vue/imageedit.h \
    vue/listechampsedit.h \
    modele/adresse.h \
    modele/email.h \
    vue/nouveaucontact.h \
    modele/tel.h \
    modele/enum.h \
    vue/enumedit.h

FORMS    += vue/mainwindow.ui \
    vue/contactview.ui \
    vue/ajouterchamp.ui \
    vue/imageedit.ui \
    vue/listechampsedit.ui \
    vue/nouveaucontact.ui

QMAKE_CXXFLAGS += -std=c++11
