#include "nom.h"

Nom::Nom(QString nomChamp, QObject *parent) :
    Champ(nomChamp,parent)
{
}
QString Nom::toString() const
{
   return mNom;
}
bool Nom::fromString(const QString s)
{
   mNom=s;
   return true;
}
