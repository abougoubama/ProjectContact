#include "texte.h"

Texte::Texte(QString nomChamp, QObject *parent) :
    Champ(nomChamp,parent)
{
}
Texte::Texte(QString nomChamp, QString s, QObject *parent) :
    Champ(nomChamp,parent), mTexte(s)
{
}

QString Texte::toString() const
{
   return mTexte;
}
bool Texte::fromString(const QString s)
{
   mTexte=s;
   return true;
}
