#ifndef CONTACTS_H
#define CONTACTS_H

#include <QObject>
#include "contact.h"
#include "vue/nouveaucontact.h"



class Contacts : public QObject
{
    Q_OBJECT
public:
    explicit Contacts(QObject *parent = 0);
    explicit Contacts(QDomElement &element,QObject *parent = 0);
    /**
     * @brief ajouterContact
     * @param contact
     */
    void ajouterContact(Contact * contact);
    /**
     * @brief creerNouveauContact
     * @param nouveauContact
     */
static   Contact * creerNouveauContact(QString typeContact );
/**
         * @brief supprimerContact
         * @param contact
         */
        void supprimerContact(int row);
    /**
     * @brief getContact
     * @param nbr
     * @return
     */
    Contact* getContact(int nbr);
    /**
     * @brief nbContact
     * @return
     */
    int nbContact();

    QDomElement toXml(QDomDocument &doc) const;

    void sauvegarder(QString nomFichier) const;
    static Contacts * charger(QString nomFichier);
    
signals:
    void beginInsert(int position);
    void endInsert();
    void beginRemove(int position);
    void endRemove();
    
public slots:

private:
    QList<Contact*> mContacts; //liste de contact dans l'annuaire
    
};

#endif // CONTACTS_H
