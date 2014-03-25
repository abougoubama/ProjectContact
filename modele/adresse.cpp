#include "adresse.h"
#include "modele/champ.h"
#include "modele/listechamps.h"
#include "modele/texte.h"

Adresse::Adresse(QString nomChamp, QObject *parent) :
    ListeChamps(nomChamp, parent)
{
}

Adresse::Adresse(QString nomChamp,QString rue, QString zipcode,QString localite, QString region ,QString pays,QObject *parent):
    ListeChamps(nomChamp,parent)
{
  ajouterChamp(new Texte("Rue",rue));
  ajouterChamp(new Texte("ZipCode",zipcode));
  ajouterChamp(new Texte("Localité",localite));
  ajouterChamp(new Texte("Région",region));
  ajouterChamp(new Texte("Pays",pays));

}

Adresse::Adresse(QDomElement &element,QObject *parent) : ListeChamps(element,parent)
{

}

QString Adresse::toString() const
{
    QString rue, zipcode, localite, region, pays;
   for(Champ * champ:mListeChamps)
   {
       //si le nom du champs est rue alors il vas chercher la valeur associé à rue et l'a met dans le QString rue
      if(champ->nomChamp()=="Rue") rue=champ->toString();
      if(champ->nomChamp()=="ZipCode") zipcode=champ->toString();
      if(champ->nomChamp()=="Localité") localite=champ->toString();
      if(champ->nomChamp()=="Région") region=champ->toString();
      if(champ->nomChamp()=="Pays") pays=champ->toString();
   }
   QString s = rue + " " + zipcode + " " +localite+" " +region+" " +pays;
   return s.replace("  "," ").trimmed();
}
bool Adresse::fromString(const QString)
{
   return false;
}


QDomElement Adresse::toXml(QDomDocument &doc) const
{
    QDomElement tag=ListeChamps::toXml(doc);
    tag.setTagName("Adresse");
    return tag;
}

