#include "listechamps.h"
#include "champ.h"

ListeChamps::ListeChamps(QString nomChamp, QObject *parent) :
    Champ(nomChamp,parent)
{
}

/**
 * @brief toString convertit l'objet en format lisible
 * @return une QString contenant un format lisible du champ
 */
 QString ListeChamps::toString() const
{
    QString chaine="";
    for(Champ* champ : mListeChamps) chaine+=champ->toString()+" ";
    return chaine;
}
/**
 * @brief fromString convertit un QString en champ
 * @return true si la conversion a réussi , false sinon
 */
 bool ListeChamps::fromString(const QString)
{
    return false;
}

 QVariant ListeChamps::toQVariant()
 {
    return QVariant::fromValue(this);
 }

 bool ListeChamps::fromQVariant(const QVariant v)
 {
    ListeChamps * listeChamps=v.value<ListeChamps*>();
    mListeChamps=listeChamps->mListeChamps;

    return true;
 }


int ListeChamps::nbChamps()
{
    return mListeChamps.size();
}

Champ* ListeChamps::getChamp(int i)
{
    return mListeChamps[i];
}

void ListeChamps::ajouterChamp(Champ * champ)
{
    emit beginInsert(mListeChamps.size());
    mListeChamps<<champ;
    emit endInsert();
}

