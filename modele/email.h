#ifndef EMAIL_H
#define EMAIL_H

#include <QObject>
#include <QString>
#include "listechamps.h"

class Email : public ListeChamps
{
    Q_OBJECT
public:
    explicit Email(QString nomChamp, QObject *parent = 0);
    explicit Email(QString nomChamp,QString nom, QString domain,QString extension,QObject *parent = 0);
    explicit Email(QDomElement &element,QObject *parent = 0);
    virtual QString toString() const;
    virtual bool fromString(const QString s);
    QDomElement toXml(QDomDocument &doc) const;

signals:

public slots:

};

#endif // EMAIL_H
