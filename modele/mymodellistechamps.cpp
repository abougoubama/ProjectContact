#include <QDebug>

#include "mymodellistechamps.h"
#include "listechamps.h"

MyModelListeChamps::MyModelListeChamps(ListeChamps & listechamps,QObject *parent) :
    QAbstractTableModel(parent),mListeChamps(listechamps)
{
    connect(&mListeChamps,&ListeChamps::beginInsert,[this](int position){
        beginInsertRows(QModelIndex(),position,position);
    });
    connect(&mListeChamps,&ListeChamps::endInsert,[this](){
        endInsertRows();
    });
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
    else if (role==Qt::EditRole)
    {

        if(index.column()==0)
        {
            return mListeChamps.getChamp(index.row())->nomChamp();
        }
        else
        {
            return mListeChamps.getChamp(index.row())->toQVariant();
        }
    }
    else if (role==Qt::DecorationRole)
    {
        if(index.column()==1)
        {
            QVariant image = mListeChamps.getChamp(index.row())->image();
           if(image.isValid()) return image;
        }
    }
    return QVariant();
}

bool MyModelListeChamps::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if(!index.isValid()) return false;
    if(index.row()>=mListeChamps.nbChamps()) return false;
    if(index.column()!=1) return false;
    if (role == Qt::EditRole)
    {
       if( mListeChamps.getChamp(index.row())->fromQVariant(value))
       {
           emit dataChanged(index,index);
           return true;
       }
    }
    return false;
}

Qt::ItemFlags MyModelListeChamps::flags(const QModelIndex &index) const
{
    return index.column()!=1 ?QAbstractTableModel::flags(index) : Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

