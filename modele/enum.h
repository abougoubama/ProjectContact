#ifndef ENUM_H
#define ENUM_H


#include <QObject>
#include"modele/champ.h"
#include <QStringList>

class Enum : public Champ
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur par défaut
     * @param parent fourni le parent ou QObject
     * @param nomChamp donne le nom du champ
     */
    explicit Enum(QString nomChamp, QObject *parent = 0);
    explicit Enum(QString nomChamp, int enum_,int valeur, QObject * parent=0);
    explicit Enum(QDomElement &element,QObject *parent = 0);
    /**
     * @brief toString convertit l'objet en format lisible
     * @return une QString contenant un format lisible du champ
     */
    virtual QString toString() const;
    /**
     * @brief fromString convertit un QString en champ
     * @return true si la conversion a réussi , false sinon
     */
    virtual bool fromString( QString s);
    /**
     * @brief valeur permet de récupérer la valeur dans l'énumération
     * @return L'index de la valeur actuelle
     */
    int valeur() const;
    /**
     * @brief getEnum permet de récupérer le numéro de l'énumération utilisée
     * @return L'index de l'énumération
     */
    int getEnum() const;
    /**
     * @brief remplirEnums initialise les énumérations
     * Elle est appelée une seul et unique fois, au début du programme, pour remplir mEnumTypeListe et mEnumListe des valeurs qu'on souhaite       qu'elles prennent.
      */
    static void remplirEnums();
    /**
     * @brief toVariant convertit l'objet en QVariant
     * @return un QVariant décrivant exactement l'objet
     */
    QVariant toQVariant();
    /**
     * @brief fromVariant un QVariant en Champ
     * @param v le QVariant a convertir
     * @return true si la conversion a réussi, false sinon
     */
    bool fromQVariant( QVariant v);
    /**
     * @brief valeursPossibles permet de récupérer la liste des valeurs possible pour l'énumération actuelle
     * @return Une QStringList contenant les valeurs que peut prendre l'énumération du type enregistr
     */
    QStringList valeursPossibles() const;
    /**
     * @brief toXml convertit une adresse en Xml
     * @param doc le QDomDocument à convertir
     * @return un QDomElement
     */
    QDomElement toXml(QDomDocument &doc) const;
    /**
     * @brief setValeur affecte mValeur la valeur passé en paramètre
     * @param valeur une valeur entière
     */
    void setValeur(int valeur);


signals:

public slots:

private:
    static QStringList mEnumTypeListe;
    static QList<QStringList> mEnumListe;
    int mEnum;
    int mValeur;

};
Q_DECLARE_METATYPE (Enum*)

#endif // ENUM_H
