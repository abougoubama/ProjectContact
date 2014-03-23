#ifndef TEXTE_H
#define TEXTE_H

#include <QObject>
#include <QString>
#include "champ.h"

class Texte : public Champ
{
    Q_OBJECT
public:
    explicit Texte(QString nomChamp,QObject *parent = 0);
    Texte(QString nomChamp,QString s,QObject *parent = 0);
    virtual QString toString() const;
    virtual bool fromString(const QString s);

signals:

public slots:

private:
    QString mTexte;
};

#endif // TEXTE_H
