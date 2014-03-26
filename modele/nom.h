#ifndef NOM_H
#define NOM_H

#include <QObject>
#include <QString>
#include "listechamps.h"


class Nom : public ListeChamps
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur par défaut
     * @param parent fourni le parent ou QObject
     * @param nomChamp donne le nom du champ
     */
    explicit Nom(QString nomChamp,QObject *parent = 0);
    explicit Nom(QString nomChamp,QString nom, QString prenom,QString surnom, QString prefixe,QObject *parent = 0);
    explicit Nom(QDomElement &element,QObject *parent = 0);
    /**
     * @brief toString convertit l'objet en format lisible
     * @return une QString contenant un format lisible du champ
     */
    virtual QString toString() const;
    /**
     * @brief fromString convertit un QString en champ
     * @return true si la conversion a réussi , false sinon
     */
    virtual bool fromString(const QString s);
    /**
     * @brief toXml convertit une adresse en Xml
     * @param doc le QDomDocument à convertir
     * @return un QDomElement
     */
    QDomElement toXml(QDomDocument &doc) const;
signals:

public slots:

private:

};

#endif // NOM_H
