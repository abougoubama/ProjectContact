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
    /**
     * @brief listeChamps
     * @return
     */
    ListeChamps * listeChamps() const;
    /**
     * @brief setListeChamps
     * @param listeChamps
     */
    void setListeChamps(ListeChamps *listeChamps) ;
    /**
     * @brief sizeHint
     * @return
     */
    QSize sizeHint() const;

private:
    Ui::ListeChampsEdit *ui;
    ListeChamps * mListeChamps;
};

#endif // LISTECHAMPSEDIT_H
