#ifndef ADRESSE_H
#define ADRESSE_H

#include <QObject>
#include <QString>
#include "listechamps.h"

class Adresse : public ListeChamps
{
    Q_OBJECT
public:
    typedef enum {
         Work,
        Home,
        Other
    } TypeAdresse;
    explicit Adresse(QString nomChamp, QObject *parent = 0);
    explicit Adresse(QString nomChamp, QString rue, QString zipcode, QString localite, QString region, QString pays, QObject *parent = 0);
    explicit Adresse(QDomElement &element,QObject *parent = 0);
    virtual QString toString() const;
    virtual bool fromString(const QString s);
    QDomElement toXml(QDomDocument &doc) const;

signals:

public slots:

};

#endif // ADRESSE_H
