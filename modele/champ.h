#ifndef CHAMP_H
#define CHAMP_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QDomElement>

/**
 * @brief La classe Champ représente un champ d'un formulaire
 */
class Champ : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur par défaut
     * @param parent fourni le parent ou QObject
     * @param nomChamp donne le nom du champ
     */
    explicit Champ(QString nomChamp, QObject *parent = 0);
    /**
     * @brief setNomChamp affecte la valeur nom à l'attribut membre mNomChamp
     * @param nom le nom du champ que l'on veut donner
     */
    void setNomChamp(QString nom);
    /**
     * @brief nomChamp
     * @return mNomChamp
     */
    QString nomChamp();
    /**
     * @brief toString convertit l'objet en format lisible
     * @return une QString contenant un format lisible du champ
     */
    virtual QString toString() const =0;
    /**
     * @brief fromString convertit un QString en champ
     * @return true si la conversion a réussi , false sinon
     */
    virtual bool fromString(const QString)=0;
    /**
     * @brief toVariant convertit l'objet en QVariant
     * @return un QVariant décrivant exactement l'objet
     */
    virtual QVariant toQVariant() ;
    /**
     * @brief fromVariant un QVariant en Champ
     * @param v le QVariant a convertir
     * @return true si la conversion a réussi, false sinon
     */
    virtual bool fromQVariant(const QVariant v);
    /**
     * @brief image fourni une image à afficher
     * @return sous la forme d'un QVariant (QPixmap ou QIcon ou QImage)
     */
    virtual QVariant image() const;
    /**
     * @brief toXml convertit une adresse en Xml
     * @param doc le QDomDocument à convertir
     * @return un QDomElement
     */
    virtual QDomElement toXml(QDomDocument &doc) const=0;



signals:

public slots:

protected:
    /**
     * @brief mNomChamp le nom d'un champ
     */
    QString mNomChamp;



};

#endif // CHAMP_H
