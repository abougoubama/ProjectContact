#include "nom.h"

Nom::Nom(QObject *parent) :
    Champ(parent)
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
