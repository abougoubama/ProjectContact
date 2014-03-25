#include "tel.h"

#include <QObject>
#include <QString>
#include "modele/listechamps.h"
#include "modele/texte.h"
#include "modele/enum.h"

Tel::Tel(QString nomChamp,QObject *parent) :
    ListeChamps(nomChamp,parent)
{
}


 Tel::Tel(QString nomChamp,  QString numero , QObject *parent):
      ListeChamps(nomChamp,parent)
{
     ajouterChamp(new Texte("Numéro",numero));
}

 Tel::Tel(QDomElement &element,QObject *parent): ListeChamps(element,parent)
{

}

QString Tel::toString() const
{
    QString numero;
   for(Champ * champ:mListeChamps)
   {
       //si le nom du champs est  num alors il vas chercher la valeur associé au num et l'a met dans le QString du num

      if(champ->nomChamp()=="Numéro") numero=champ->toString();


   }
   QString s =numero ;
   return s.replace("  "," ").trimmed();
}
bool Tel::fromString(const QString)
{
   return false;
}


QDomElement Tel::toXml(QDomDocument &doc) const
{
    QDomElement tag=ListeChamps::toXml(doc);
    tag.setTagName("Tel");
    return tag;
}

