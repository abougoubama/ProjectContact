#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>
#include <QString>
#include <QPair>
#include "listechamps.h"
#include "modele/nom.h"


class Contact : public QObject
{
    Q_OBJECT
public:
    explicit Contact(QObject *parent = 0);
    ~Contact();
    ListeChamps & listeChamps();
    Nom *nom();
    void setNom(Nom * nom);

signals:

public slots:

private:
    ListeChamps mListeChamps;
    Nom * mNom;

};

#endif // CONTACT_H

