#include <QDomElement>
#include "contact.h"
#include "listechamps.h"
#include "modele/nom.h"
#include "modele/texte.h"
#include "modele/adresse.h"
#include "modele/email.h"
#include "modele/listechamps.h"
#include "modele/image.h"
#include "modele/tel.h"


Contact::Contact(QObject *parent) :QObject(parent),mListeChamps("")
{

}

Contact::Contact(QDomElement &element, QObject*parent) : QObject(parent),mListeChamps(element.firstChildElement())
{
    mNom=mListeChamps.trouverNom();
}

Contact::~Contact()
{

}

ListeChamps & Contact::listeChamps()
{
 return mListeChamps;
}

QDomElement Contact::toXml(QDomDocument &doc) const
{
    QDomElement tag=doc.createElement("Contact");
    tag.appendChild(mListeChamps.toXml(doc));
    return tag;
}

Nom * Contact::nom()
{
 return mNom;
}

void Contact::setNom(Nom * nom)
{
mNom = nom;
mListeChamps.ajouterChamp(mNom);
}

Champ* Contact::creerNom(QString nomChamp)
{
    return new Nom(nomChamp);
}

Champ* Contact::creerImage(QString nomChamp)
{
  return new Image(nomChamp);

}

Champ* Contact::creerTexte(QString nomChamp)
{
   return new Texte(nomChamp);
}

//en fct du type de contact elle utilise la méthode stat por créer les contact correspondant
Champ* Contact::creerChamp(QString nomChamp, QString typeChamp )
{
    if(typeChamp=="Nom") return creerNom(nomChamp);
    if(typeChamp=="Image") return creerImage(nomChamp);
    if(typeChamp=="Texte") return creerTexte(nomChamp);
    if(typeChamp=="Email") return creerEmail(nomChamp);
    if(typeChamp=="Adresse") return creerAdresse(nomChamp);
    if(typeChamp=="Tel") return new Tel(nomChamp);
    return nullptr;
}

Champ* Contact::creerAdresse(QString nomChamp )
{
    return new Adresse(nomChamp,"","","","","");
}

Champ* Contact::creerEmail(QString nomChamp )
{
    return new Email(nomChamp,"","","");
}
