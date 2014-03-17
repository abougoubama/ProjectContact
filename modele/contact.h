#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>
#include <QString>
#include <QPair>


class Contact : public QObject
{
    Q_OBJECT
public:
    explicit Contact(QObject *parent = 0);
    ~Contact();
    QString nom() const;
    void setNom(QString nom);

signals:

public slots:

private:
    QString mNom;
};

#endif // CONTACT_H
