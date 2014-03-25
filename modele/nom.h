#ifndef NOM_H
#define NOM_H

#include <QObject>
#include <QString>
#include "listechamps.h"


class Nom : public ListeChamps
{
    Q_OBJECT
public:
    explicit Nom(QString nomChamp,QObject *parent = 0);
    explicit Nom(QString nomChamp,QString nom, QString prenom,QString surnom, QString prefixe,QObject *parent = 0);
    explicit Nom(QDomElement &element,QObject *parent = 0);
    virtual QString toString() const;
    virtual bool fromString(const QString s);
    QDomElement toXml(QDomDocument &doc) const;
signals:

public slots:

private:

};

#endif // NOM_H
