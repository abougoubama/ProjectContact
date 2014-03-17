#include "mymodellistechamps.h"
#include "listechamps.h"

MyModelListeChamps::MyModelListeChamps(ListeChamps & listechamps,QObject *parent) :
    QAbstractTableModel(parent),mListeChamps(listechamps)
{
}

int MyModelListeChamps::rowCount(const QModelIndex & /*parent*/) const
{
   return mListeChamps.nbChamps();
}

int MyModelListeChamps::columnCount(const QModelIndex & ) const
{
    return 2;
}

QVariant MyModelListeChamps::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();
    if(index.row()>=mListeChamps.nbChamps()) return QVariant();
    if(index.column()>=2) return QVariant();
    if (role == Qt::DisplayRole)
    {
       if(index.column()==0)
       {
           return mListeChamps.getChamp(index.row())->nomChamp();
       }
       else
       {
           return mListeChamps.getChamp(index.row())->toString();
       }
    }

    return QVariant();
}

