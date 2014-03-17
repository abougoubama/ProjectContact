#include "contacts.h"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <QApplication>






Contacts::Contacts(QObject *parent) :
    QObject(parent)
{
}

void Contacts::ajouterContact(Contact * contact)
{
    mContacts<<contact;
}

Contact* Contacts::getContact(int nbr)
{
    return mContacts[nbr];
}

int Contacts::nbContact()
{
    return mContacts.size();
}
