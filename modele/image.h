#ifndef IMAGE_H
#define IMAGE_H

#include <QPixmap>
#include <QUrl>
#include <QString>
#include <QVariant>
#include "champ.h"

class Image : public Champ
{
    Q_OBJECT
public:
    explicit Image(QString nomChamp,QObject *parent = 0);
    virtual QString toString() const;
    virtual bool fromString(const QString s);
    virtual QVariant toQVariant();
    virtual bool fromQVariant(const QVariant v);
    QVariant image() const;
    void setUrl(QUrl url);
    QUrl url();
    
signals:

public slots:

private:
    QPixmap mImage;
    QUrl mUrl;



};
Q_DECLARE_METATYPE (Image*)
#endif // IMAGE_H


//toString, fromSring, Qvariant, fromVariant
