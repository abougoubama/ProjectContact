#ifndef MYMODELLISTECHAMPS_H
#define MYMODELLISTECHAMPS_H

#include <QAbstractTableModel>
#include "listechamps.h"
class MyModelListeChamps : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit MyModelListeChamps(ListeChamps &listechamps, QObject *parent = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex & parent= QModelIndex()) const ;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;


signals:

public slots:

private:
      ListeChamps & mListeChamps ;

};

#endif // MYMODELLISTECHAMPS_H
