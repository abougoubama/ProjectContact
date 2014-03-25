#include "texte.h"

Texte::Texte(QString nomChamp, QObject *parent) :
    Champ(nomChamp,parent)
{
}
Texte::Texte(QString nomChamp, QString s, QObject *parent) :
    Champ(nomChamp,parent), mTexte(s)
{
}


Texte::Texte(QDomElement &element, QObject *parent) : Texte(element.attribute("nomChamp"),element.text(),parent)
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

QDomElement Texte::toXml(QDomDocument &doc) const
{
    QDomElement tag=doc.createElement("Texte");
    tag.setAttribute("nomChamp",mNomChamp);
    tag.appendChild(doc.createTextNode(mTexte));
    return tag;
}
