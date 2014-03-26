#ifndef TEXTE_H
#define TEXTE_H

#include <QObject>
#include <QString>
#include "champ.h"

class Texte : public Champ
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur par défaut
     * @param parent fourni le parent ou QObject
     * @param nomChamp donne le nom du champ
     */
    explicit Texte(QString nomChamp,QObject *parent = 0);
    explicit Texte(QString nomChamp,QString s,QObject *parent = 0);
    explicit Texte(QDomElement &element,QObject *parent = 0);
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
    QString mTexte;
};

#endif // TEXTE_H
