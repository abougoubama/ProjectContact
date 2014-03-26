#ifndef IMAGE_H
#define IMAGE_H

#include <QPixmap>
#include <QUrl>
#include <QString>
#include <QVariant>
#include "champ.h"

class Image : public Champ
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur par défaut
     * @param parent fourni le parent ou QObject
     * @param nomChamp donne le nom du champ
     */
    explicit Image(QString nomChamp,QObject *parent = 0);
    explicit Image(QDomElement &element,QObject *parent = 0);
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
     * @brief toVariant convertit l'objet en QVariant
     * @return un QVariant décrivant exactement l'objet
     */
    virtual QVariant toQVariant();
    /**
     * @brief fromVariant un QVariant en Champ
     * @param v le QVariant a convertir
     * @return true si la conversion a réussi, false sinon
     */
    virtual bool fromQVariant(const QVariant v);
    /**
     * @brief setValeur affecte mValeur la valeur passé en paramètre
     * @param valeur une valeur entière
     */
    QDomElement toXml(QDomDocument &doc) const;
    /**
     * @brief image est la conversion du champ en QVariant
     * @return Une QVariant représentant le champ
     */
    QVariant image() const;
    /**
     * @brief setUrl affecte à mUrl la valeur de url passé en paramètre
     * @param url un paramètre de type QUrl
     */
    void setUrl(QUrl url);
    /**
     * @brief url
     * @return l'attribut membre mUrl
     */
    QUrl url();
    
signals:

public slots:

private:
    QPixmap mImage;
    QUrl mUrl;



};
Q_DECLARE_METATYPE (Image*)
#endif // IMAGE_H


//toString, fromSring, Qvariant, fromVariant
