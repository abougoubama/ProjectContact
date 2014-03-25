#include "listechamps.h"
#include "champ.h"
#include "adresse.h"
#include "email.h"
#include "image.h"
#include "nom.h"
#include "texte.h"

ListeChamps::ListeChamps(QString nomChamp, QObject *parent) :
    Champ(nomChamp,parent)
{
}


ListeChamps::ListeChamps(QDomElement element, QObject *parent) : Champ(element.attribute("nomChamp"),parent)
{
    QDomElement elem=element.firstChildElement();

    while(!elem.isNull())
    {
        if(elem.tagName()=="Adresse") ajouterChamp(new Adresse(elem,this));
        else if(elem.tagName()=="Email") ajouterChamp(new Email(elem,this));
        else if(elem.tagName()=="Image") ajouterChamp(new Image(elem,this));
        else if(elem.tagName()=="ListeChamps") ajouterChamp(new ListeChamps(elem,this));
        else if(elem.tagName()=="Nom") ajouterChamp(new Nom(elem,this));
        else if(elem.tagName()=="Texte") ajouterChamp(new Texte(elem,this));
        elem=elem.nextSiblingElement();
    }
}


Nom* ListeChamps::trouverNom() const
{
    for(Champ* champ : mListeChamps)
    {
        if(champ->nomChamp()=="Nom") return dynamic_cast<Nom*>(champ);
    }
    return nullptr;
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

QDomElement ListeChamps::toXml(QDomDocument &doc) const
{
    QDomElement tag=doc.createElement("ListeChamps");
    tag.setAttribute("nomChamp",mNomChamp);
    for(Champ* champ : mListeChamps) tag.appendChild(champ->toXml(doc));
    return tag;
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

