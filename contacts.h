#ifndef CONTACTS_H
#define CONTACTS_H

#include <QObject>
#include "contact.h"


class Contacts : public QObject
{
    Q_OBJECT
public:
    explicit Contacts(QObject *parent = 0);
    void ajouterContact(Contact * contact);
    Contact* getContact(int nbr);
    int nbContact();
    
signals:
    
public slots:

private:
    QList<Contact*> mContacts; //liste de contact dans l'annuaire
    
};

#endif // CONTACTS_H
