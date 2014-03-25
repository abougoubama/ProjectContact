#include "email.h"
#include "modele/champ.h"
#include "modele/listechamps.h"
#include "modele/texte.h"
Email::Email(QString nomChamp, QObject *parent) :
    ListeChamps(nomChamp, parent)
{
}

Email::Email(QString nomChamp,QString nom, QString domain,QString extension,QObject *parent ):
    ListeChamps(nomChamp,parent)
{
  ajouterChamp(new Texte("Nom",nom));
  ajouterChamp(new Texte("Domaine",domain));
  ajouterChamp(new Texte("Extension",extension));

}

Email::Email(QDomElement &element,QObject *parent) : ListeChamps(element,parent)
{

}

QString Email::toString() const
{
    QString nom, domain, extension;
   for(Champ * champ:mListeChamps)
   {
       //si le nom du champs est prénom alors il vas chercher la valeur associé à prénom et l'a met dans le prénom
      if(champ->nomChamp()=="Nom") nom=champ->toString();
      if(champ->nomChamp()=="Domaine") domain=champ->toString();
      if(champ->nomChamp()=="Extension") extension=champ->toString();
   }
   QString s = nom + "@" + domain + "." + extension;
   return s.replace("  "," ").trimmed();
}
bool Email::fromString(const QString)
{
   return false;
}

QDomElement Email::toXml(QDomDocument &doc) const
{
    QDomElement tag=ListeChamps::toXml(doc);
    tag.setTagName("Email");
    return tag;
}
