#include "enumedit.h"
#include "ui_enumedit.h"
#include "modele/enum.h"
#include <QComboBox>

EnumEdit::EnumEdit(QWidget *parent) :
    QComboBox(parent)
{
    setAutoFillBackground(true);
}

EnumEdit::~EnumEdit()
{

}

Enum *EnumEdit::getEnum() const
{
    mEnum->setValeur(currentIndex());
    return mEnum;
}

void EnumEdit::setEnum(Enum * c)
{
    addItems(c->valeursPossibles());
    mEnum=c;
    setCurrentIndex(c->valeur());
}
