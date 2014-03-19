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

 QVariant Champ::toQVariant() const
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
