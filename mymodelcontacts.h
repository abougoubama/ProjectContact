#ifndef MYMODELCONTACTS_H
#define MYMODELCONTACTS_H

#include <QAbstractListModel>
#include "contacts.h"

class MyModelContacts : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit MyModelContacts(Contacts & Contacts,QObject *parent = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;


signals:

public slots:

private:

    Contacts & mContacts;

};

#endif // MYMODELCONTACTS_H
