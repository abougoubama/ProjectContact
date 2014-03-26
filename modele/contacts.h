#ifndef CONTACTS_H
#define CONTACTS_H

#include <QObject>
#include "modele/contact.h"
#include "vue/nouveaucontact.h"


/**
 * @brief La classe Contacts représente une liste de contacts
 */
class Contacts : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur par défaut
     */
    explicit Contacts(QObject *parent = 0);
    explicit Contacts(QDomElement &element,QObject *parent = 0);
    /**
     * @brief ajouterContact ajoute un contact dans la liste
     * @param contact Un poiteur vers le contact à ajouter
     */
    void ajouterContact(Contact * contact);
    /**
     * @brief creerNouveauContact  à partir de son type (personne ou Organisme)
     * @param typeContact est la personne
     * @return  un contact crée
     */
static   Contact * creerNouveauContact(QString typeContact );
/**
         * @brief supprimerContact supprime un contact
         * @param row la ligne où se situe le contact dans la liste de Contacts
         */
        void supprimerContact(int row);
    /**
     * @brief getContact retourne un contact de la liste mContacts
     * @param nbr un numéro pour se situer dans la liste de contacts
     * @return un contact
     */
    Contact* getContact(int nbr);
    /**
     * @brief nbContact le nombre de contacts total dans la liste
     * @return le nombre de contacts
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
    /**
     * @brief mContacts la liste de Contact dans l'anuaire
     */
    QList<Contact*> mContacts;
    
};

#endif // CONTACTS_H
