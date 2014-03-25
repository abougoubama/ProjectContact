#ifndef TEL_H
#define TEL_H

#include <QObject>
#include <QString>
#include "listechamps.h"
#include "modele/enum.h"

class Tel : public ListeChamps
{
    Q_OBJECT
public:
    explicit Tel(QString nomChamp, QObject *parent = 0);

    explicit Tel(QString nomChamp, QString numero , QObject *parent = 0);
    explicit Tel(QDomElement &element,QObject *parent = 0);
    virtual QString toString() const;
    virtual bool fromString(const QString s);
    QDomElement toXml(QDomDocument &doc) const;

signals:

public slots:

};

#endif // TEL_H
