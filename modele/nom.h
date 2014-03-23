#ifndef NOM_H
#define NOM_H

#include <QObject>
#include <QString>
#include "champ.h"


class Nom : public Champ
{
    Q_OBJECT
public:
    explicit Nom(QString nomChamp,QObject *parent = 0);
    virtual QString toString() const;
    virtual bool fromString(const QString s);
signals:

public slots:

private:
    QString mNom;

};

#endif // NOM_H
