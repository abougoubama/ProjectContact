#ifndef LISTECHAMPSEDIT_H
#define LISTECHAMPSEDIT_H

#include <QWidget>
#include "modele/listechamps.h"
#include <QSize>

namespace Ui {
class ListeChampsEdit;
}

class ListeChampsEdit : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(ListeChamps * listeChamps READ listeChamps WRITE setListeChamps USER true)

public:
    explicit ListeChampsEdit(QWidget *parent = 0);
    ~ListeChampsEdit();
    ListeChamps * listeChamps() const;
    void setListeChamps(ListeChamps *listeChamps) ;
    QSize sizeHint() const;

private:
    Ui::ListeChampsEdit *ui;
    ListeChamps * mListeChamps;
};

#endif // LISTECHAMPSEDIT_H
