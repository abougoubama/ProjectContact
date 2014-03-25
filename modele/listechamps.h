#ifndef LISTECHAMPS_H
#define LISTECHAMPS_H

#include "champ.h"
#include <QVariant>
#include <QString>

class Nom;

class ListeChamps : public Champ
{
    Q_OBJECT
public:
    explicit ListeChamps(QString nomChamp,QObject *parent = 0);
    explicit ListeChamps(QDomElement element,QObject *parent = 0);
    /**
     * @brief toString convertit l'objet en format lisible
     * @return une QString contenant un format lisible du champ
     */
    virtual QString toString() const;
    /**
     * @brief fromString convertit un QString en champ
     * @return true si la conversion a réussi , false sinon
     */
    virtual bool fromString(const QString);
    virtual QVariant toQVariant();
    virtual bool fromQVariant(const QVariant v);
    /**
      * @brief nbChamps
      * @return
      */
     int nbChamps();
     /**
      * @brief getChamp
      * @param i
      * @return
      */
     Champ *getChamp(int i);
     /**
      * @brief ajouterChamp
      * @param champ
      */
     void ajouterChamp(Champ * champ);
     QDomElement toXml(QDomDocument &doc) const;

     Nom* trouverNom() const;



signals:
    void beginInsert(int position);
    void endInsert();
public slots:

protected:
    QList<Champ*> mListeChamps;

};
Q_DECLARE_METATYPE (ListeChamps*)

#endif // LISTECHAMPS_H
