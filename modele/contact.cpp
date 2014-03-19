#include "contact.h"
#include "modele/nom.h"


Contact::Contact(QObject *parent) :QObject(parent)
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
