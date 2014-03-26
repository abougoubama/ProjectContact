#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>
#include <QString>
#include <QPair>
#include <QDomElement>
#include "listechamps.h"
#include "modele/nom.h"
#include "modele/adresse.h"
#include "modele/email.h"



class Contact : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur par défaut
     */
    explicit Contact(QObject *parent = 0);
    explicit Contact(QDomElement &element,QObject *parent = 0);
    ~Contact();
    /**
     * @brief listeChamps
     * @return retourne la liste mListeChamps
     */
    ListeChamps & listeChamps();
    /**
     * @brief nom
     * @return l'attribut membre mNom
     */
    Nom *nom();
    /**
     * @brief setNom affecte la valeur nom à l'attribut membre mNom
     * @param nom
     */
    void setNom(Nom * nom);
    /**
     * @brief creerNom crée un champ Nom à partir du nom de champ  passé en paramètre.
     * @param nomChamp le nom du champ à créer
     * @return le champ
     */
    static Champ* creerNom(QString nomChamp);
    /**
     * @brief creerChamp crée un champ à partir de son nom , et de son type.
     * @param nomChamp le nom du champ à créer
     * @param typeChamp le type du champ à créer
     * @return le champ
     */
    static Champ* creerChamp(QString nomChamp, QString typeChamp );
    /**
     * @brief creerImage crée un champ Image à partir du nom de champ  passé en paramètre.
     * @param nomChamp le nom du champ à créer
     * @return le champ
     */
    static Champ* creerImage(QString nomChamp);
    /**
     * @brief creerTexte crée un champ Texte à partir du nom de champ  passé en paramètre.
     * @param nomChamp le nom du champ à créer
     * @return le champ
     */
    static Champ* creerTexte(QString nomChamp);
    /**
     * @brief creerAdresse crée un champ Adresse à partir du nom de champ  passé en paramètre.
     * @param nomChamp le nom du champ à créer
     * @return le champ
     */
    static Champ* creerAdresse(QString nomChamp);
    /**
     * @brief creerEmail crée un champ Email à partir du nom de champ  passé en paramètre.
     * @param nomChamp le nom du champ à créer
     * @return le champ
     */
    static Champ* creerEmail(QString nomChamp);
    /**
     * @brief toXml convertit une adresse en Xml
     * @param doc le QDomDocument à convertir
     * @return un QDomElement
     */

    QDomElement toXml(QDomDocument &doc) const;


signals:

public slots:

private:
    /**
     * @brief mListeChamps attribut membre qui est une liste de champ
     */
    ListeChamps mListeChamps;
    /**
     * @brief mNom attribut membre qui est un Nom
     */
    Nom * mNom;

};

#endif // CONTACT_H

