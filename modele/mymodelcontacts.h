#ifndef MYMODELCONTACTS_H
#define MYMODELCONTACTS_H

#include <QAbstractListModel>
#include "contacts.h"

class MyModelContacts : public QAbstractListModel
        //QAbstractTreeModel conseillé
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur par défaut
     */
    explicit MyModelContacts(Contacts & Contacts,QObject *parent = 0);
    /**
     * @brief rowCount
     * @param parent
     * @return
     */
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    /**
     * @brief data
     * @param index
     * @param role
     * @return
     */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;


signals:

public slots:

private:

    Contacts & mContacts;

};

#endif // MYMODELCONTACTS_H
