#ifndef LISTECHAMPS_H
#define LISTECHAMPS_H

#include "champ.h"
#include <QVariant>
#include <QString>


class ListeChamps : public Champ
{
    Q_OBJECT
public:
    explicit ListeChamps(QString nomChamp,QObject *parent = 0);
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
     int nbChamps();
     Champ *getChamp(int i);

     void ajouterChamp(Champ * champ);



signals:
    void beginInsert(int position);
    void endInsert();
public slots:

protected:
    QList<Champ*> mListeChamps;

};
Q_DECLARE_METATYPE (ListeChamps*)

#endif // LISTECHAMPS_H
