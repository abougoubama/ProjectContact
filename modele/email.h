#ifndef EMAIL_H
#define EMAIL_H

#include <QObject>
#include <QString>
#include "listechamps.h"

class Email : public ListeChamps
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur par défaut
     * @param parent fourni le parent ou QObject
     * @param nomChamp donne le nom du champ
     */
    explicit Email(QString nomChamp, QObject *parent = 0);
    explicit Email(QString nomChamp,QString nom, QString domain,QString extension,QObject *parent = 0);
    explicit Email(QDomElement &element,QObject *parent = 0);
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

};

#endif // EMAIL_H
