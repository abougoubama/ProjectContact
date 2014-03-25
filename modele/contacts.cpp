#include <QFile>
#include <QTextStream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <QApplication>
#include <QDomDocument>

#include "contacts.h"
#include "vue/nouveaucontact.h"




Contacts::Contacts(QObject *parent) :
    QObject(parent)
{
}


Contacts::Contacts(QDomElement &element,QObject*parent) : Contacts(parent)
{
    if(element.tagName() != "Contacts") return;
    QDomElement elem=element.firstChildElement();
    while(!elem.isNull())
    {
        ajouterContact(new Contact(elem,this));
        elem=elem.nextSiblingElement();
    }
}

void Contacts::ajouterContact(Contact * contact)
{
    emit beginInsert(mContacts.size());
    mContacts<<contact;
    emit endInsert();
}

Contact* Contacts::getContact(int nbr)
{
    return mContacts[nbr];
}

int Contacts::nbContact()
{
    return mContacts.size();
}

Contact * Contacts::creerNouveauContact(QString typeContact)
{
    if(typeContact=="Personne")
    {
      Contact * personne= new Contact ;
      personne->listeChamps().ajouterChamp(Contact::creerChamp("Image","Image"));
      Nom * nom=new Nom("Nom","Nouveau contact","","","");
      personne->setNom(nom);
      personne->listeChamps().ajouterChamp(Contact::creerChamp("Adresse","Adresse"));
      personne->listeChamps().ajouterChamp(Contact::creerChamp("Email","Email"));
      return personne;

    }

    //if(typeContact=="Organisme") return new  ;
    return nullptr;
}

QDomElement Contacts::toXml(QDomDocument & doc) const
{
    QDomElement tag=doc.createElement("Contacts");
    for(Contact* contact : mContacts) tag.appendChild(contact->toXml(doc));
    return tag;
}

void Contacts::sauvegarder(QString nomFichier) const
{
    QDomDocument doc("contacts");
    doc.appendChild(toXml(doc));
    QString xmlContent = doc.toString();


    QFile fichier(nomFichier);
    fichier.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream out(&fichier);
    out<<xmlContent;
    fichier.close();
}


Contacts* Contacts::charger(QString nomFichier)
{
    QFile fichier(nomFichier);
    if(fichier.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QString xmlFileContent=fichier.readAll();
        fichier.close();

        QDomDocument doc;
        doc.setContent(xmlFileContent);
        QDomElement root = doc.documentElement();
        return new Contacts(root);
    }
    return nullptr;
}

void Contacts::supprimerContact(int row)
{
    emit beginRemove(row);
    mContacts.removeAt(row);
    emit endRemove();
}
