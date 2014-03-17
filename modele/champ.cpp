#include "champ.h"

Champ::Champ(QObject *parent) :
    QObject(parent)
{
}

void Champ::setNomChamp(QString nom)
{
    mNomChamp=nom;
}

QString Champ::nomChamp()
{
    return mNomChamp;
}


