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
    explicit Contact(QObject *parent = 0);
    explicit Contact(QDomElement &element,QObject *parent = 0);
    ~Contact();
    ListeChamps & listeChamps();
    Nom *nom();
    void setNom(Nom * nom);
    /**
     * @brief creerNom
     * @param nomChamp
     * @return
     */
    static Champ* creerNom(QString nomChamp);
    /**
     * @brief creerChamp
     * @param nomChamp
     * @param typeChamp
     * @return
     */
    static Champ* creerChamp(QString nomChamp, QString typeChamp );
    /**
     * @brief creerImage
     * @param nomChamp
     * @return
     */
    static Champ* creerImage(QString nomChamp);
    /**
     * @brief creerTexte
     * @param nomChamp
     * @return
     */
    static Champ* creerTexte(QString nomChamp);
    /**
     * @brief creerAdresse
     * @param nomChamp
     * @param typeChamp
     * @return
     */
    static Champ* creerAdresse(QString nomChamp);
    /**
     * @brief creerEmail
     * @param nomChamp
     * @param typeChamp
     * @return
     */
    static Champ* creerEmail(QString nomChamp);

    QDomElement toXml(QDomDocument &doc) const;


signals:

public slots:

private:
    ListeChamps mListeChamps;
    Nom * mNom;

};

#endif // CONTACT_H

