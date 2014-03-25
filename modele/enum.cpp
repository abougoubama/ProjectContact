#include "enum.h"
#include "modele/champ.h"
#include <QString>
#include <QObject>
#include <QDebug>
#include "modele/listechamps.h"




QStringList Enum::mEnumTypeListe;


QList<QStringList> Enum::mEnumListe;


Enum::Enum(QString nomChamp,int enum_, int valeur,QObject * parent) : Champ(nomChamp,parent),mEnum(enum_),mValeur(valeur)
{
}

Enum::Enum(QDomElement &element, QObject *parent) : Enum(element.attribute("nomChamp"),element.attribute("enumType").toInt(),element.text().toInt(),parent)
{
}


 QString Enum::toString() const
{
     return mEnumListe[mEnum][mValeur];
}

 bool Enum::fromString(const QString s)
{
     for (int i = 0; i < mEnumTypeListe.size(); ++i)
     {
         for (int j = 0; j < (mEnumListe[i]).size(); ++j)
         {
             if(mEnumListe[i][j]==s)
             {
                 mEnum=i;
                 mValeur=j;
                 return true;
             }
         }
     }
     return false;
}


 int Enum::valeur() const
 {
     return mValeur;
 }

 void Enum::setValeur(int valeur)
 {
     mValeur=valeur;
 }

int Enum::getEnum() const
{
    return mEnum;
}


QStringList Enum::valeursPossibles() const
{
    return mEnumListe[mEnum];
}

QVariant Enum::toQVariant()
{
     return QVariant::fromValue(this);
}

bool Enum::fromQVariant(const QVariant v)
{
      mEnum=v.value<Enum*>()->mEnum;
      mValeur=v.value<Enum*>()->mValeur;
      return true;
}

void Enum::remplirEnums()
{
    mEnumTypeListe<<tr("typeImage");
    QStringList typeImage;
    typeImage<<tr("JPEG")<<tr("GIF");
    mEnumListe<<typeImage;


    mEnumTypeListe<<tr("typeSite");
    QStringList typeSite;
    typeSite<<tr("web")<<tr("facebook")<<tr("google");
    mEnumListe<<typeSite;


    mEnumTypeListe<<tr("endroit");
    QStringList endroit;
    endroit<<tr("work")<<tr("home");
    mEnumListe<<endroit;


    mEnumTypeListe<<tr("typeTel");
    QStringList typeTel;
    typeTel<<tr("fixe")<<tr("cellulaire");
    mEnumListe<<typeTel;


    mEnumTypeListe<<tr("typeDonnees");
    QStringList typeDonnees;
    typeDonnees<<tr("voice")<<tr("data");
    mEnumListe<<typeDonnees;



    mEnumTypeListe<<tr("sexe");
    QStringList sexe;
    sexe<<tr("homme")<<tr("femme");
    mEnumListe<<sexe;

}

QDomElement Enum::toXml(QDomDocument &doc) const
{
    QDomElement tag=doc.createElement("Enum");
    tag.setAttribute("nomChamp",mNomChamp);
    tag.setAttribute("enumType",mEnum);
    tag.appendChild(doc.createTextNode(QString::number(mValeur)));
    return tag;
}
