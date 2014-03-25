#include "nom.h"
#include "modele/champ.h"
#include "modele/listechamps.h"
#include "modele/texte.h"
Nom::Nom(QString nomChamp,QObject *parent) :
    ListeChamps(nomChamp,parent)
{
}

Nom::Nom(QString nomChamp, QString nom, QString prenom, QString surnom, QString prefixe, QObject *parent) :
    ListeChamps(nomChamp,parent)
{
  ajouterChamp(new Texte("Nom",nom));
  ajouterChamp(new Texte("Prénom",prenom));
  ajouterChamp(new Texte("Surnom",surnom));
  ajouterChamp(new Texte("Prefixe",prefixe));

}

Nom::Nom(QDomElement &element,QObject *parent) : ListeChamps(element,parent)
{

}

QString Nom::toString() const
{
    QString nom, prenom,surnom,  prefixe;
   for(Champ * champ:mListeChamps)
   {
       //si le nom du champs est prénom alors il vas chercher la valeur associé à prénom et l'a met dans le prénom
      if(champ->nomChamp()=="Nom") nom=champ->toString();
      if(champ->nomChamp()=="Prénom") prenom=champ->toString();
      if(champ->nomChamp()=="Surnom") surnom=champ->toString();
      if(champ->nomChamp()=="Prefixe") prefixe=champ->toString();
   }
   QString s = prefixe+" "+ prenom+(surnom=="" ? " " : " \"" + surnom+ "\" ") + nom ;
   return s.replace("  "," ").trimmed();
}
bool Nom::fromString(const QString )
{
   return false;
}


QDomElement Nom::toXml(QDomDocument &doc) const
{
    QDomElement tag=ListeChamps::toXml(doc);
    tag.setTagName("Nom");
    return tag;
}
