#include "mymodelcontacts.h"
#include "contact.h"
#include <QDebug>

MyModelContacts::MyModelContacts(Contacts & contacts,QObject *parent) :
    QAbstractListModel(parent),mContacts(contacts)
{
    connect(&mContacts,&Contacts::beginInsert,[this](int position){
        beginInsertRows(QModelIndex(),position,position);
    });
    connect(&mContacts,&Contacts::endInsert,[this](){
        endInsertRows();
    });
    connect(&mContacts,&Contacts::beginRemove,[this](int position){
        beginRemoveRows(QModelIndex(),position,position);
    });
    connect(&mContacts,&Contacts::endRemove,[this](){
        endRemoveRows();
    });
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

