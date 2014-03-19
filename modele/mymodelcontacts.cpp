#include "mymodelcontacts.h"
#include "contact.h"
#include <QDebug>

MyModelContacts::MyModelContacts(Contacts & contacts,QObject *parent) :
    QAbstractListModel(parent),mContacts(contacts)
{

}

int MyModelContacts::rowCount(const QModelIndex & /*parent*/) const
{
   return mContacts.nbContact();
}

QVariant MyModelContacts::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();
    if(index.row()>=mContacts.nbContact()) return QVariant();
    if (role == Qt::DisplayRole)
    {
       return mContacts.getContact(index.row())->nom()->toString();
    }

    return QVariant();
}

