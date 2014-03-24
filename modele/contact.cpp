#include "contact.h"
#include "listechamps.h"
#include "modele/nom.h"
#include "modele/texte.h"
#include "modele/listechamps.h"
#include "modele/image.h"


Contact::Contact(QObject *parent) :QObject(parent),mListeChamps("")
{

}

Contact::~Contact()
{

}
 ListeChamps & Contact::listeChamps()
 {
     return mListeChamps;
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

//en fct du type du champ elle utilise la méthode stat por créer les champs correspondant
Champ* Contact::creerChamp(QString nomChamp, QString typeChamp )
{
    if(typeChamp=="Nom") return creerNom(nomChamp);
    if(typeChamp=="Image") return creerImage(nomChamp);
    if(typeChamp=="Texte") return creerTexte(nomChamp);
    return nullptr;
}

