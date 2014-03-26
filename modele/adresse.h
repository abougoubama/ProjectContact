#ifndef ADRESSE_H
#define ADRESSE_H

#include <QObject>
#include <QString>
#include "listechamps.h"

class Adresse : public ListeChamps
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur par défaut
     */
    explicit Adresse(QString nomChamp, QObject *parent = 0);
    explicit Adresse(QString nomChamp, QString rue, QString zipcode, QString localite, QString region, QString pays, QObject *parent = 0);
    explicit Adresse(QDomElement &element,QObject *parent = 0);
    /**
     * @brief toStringtoString convertit l'objet en format lisible
     * @return une QString contenant un format lisible du champ
     */
    virtual QString toString() const;
    /**
     * @brief fromString convertit un QString en Structure
     * @param s La QString à convertir
     * @return true si la conversion a réussi, false sinon
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

};

#endif // ADRESSE_H
