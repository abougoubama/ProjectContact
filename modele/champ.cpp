#include "champ.h"

Champ::Champ(QString nomChamp,QObject *parent) :
    QObject(parent), mNomChamp(nomChamp)
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

 QVariant Champ::toQVariant()
{
    return toString();
}

 bool Champ::fromQVariant(const QVariant v)
{
    return fromString(v.toString());
}

 QVariant Champ::image() const
 {
     return QVariant();
 }
