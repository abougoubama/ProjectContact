#include "contact.h"


Contact::Contact(QObject *parent) :QObject(parent)
{

}

Contact::~Contact()
{

}


QString Contact::nom() const
{
    return mNom;
}

 void Contact::setNom(QString nom)
 {
     mNom=nom;
 }
