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
    virtual QString toString() const;
    virtual bool fromString(const QString s);
signals:

public slots:

private:
    QString mNom;

};

#endif // NOM_H
