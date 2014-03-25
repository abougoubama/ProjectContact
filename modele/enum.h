#ifndef ENUM_H
#define ENUM_H


#include <QObject>
#include"modele/champ.h"
#include <QStringList>

class Enum : public Champ
{
    Q_OBJECT
public:
    explicit Enum(QString nomChamp, QObject *parent = 0);
    explicit Enum(QString nomChamp, int enum_,int valeur, QObject * parent=0);
    explicit Enum(QDomElement &element,QObject *parent = 0);

    virtual QString toString() const;
    virtual bool fromString( QString s);

    int valeur() const;
    int getEnum() const;
    static void remplirEnums();

    QVariant toQVariant();
    bool fromQVariant( QVariant v);

    QStringList valeursPossibles() const;

    QDomElement toXml(QDomDocument &doc) const;
    void fromXml(QDomElement &element);
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
