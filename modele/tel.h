#ifndef TEL_H
#define TEL_H

#include <QObject>
#include <QString>
#include "listechamps.h"
#include "modele/enum.h"

class Tel : public ListeChamps
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur par défaut
     * @param parent fourni le parent ou QObject
     * @param nomChamp donne le nom du champ
     */
    explicit Tel(QString nomChamp, QObject *parent = 0);
    explicit Tel(QString nomChamp, QString numero , QObject *parent = 0);
    explicit Tel(QDomElement &element,QObject *parent = 0);
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

#endif // TEL_H
