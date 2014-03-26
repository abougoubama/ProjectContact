#ifndef LISTECHAMPSEDIT_H
#define LISTECHAMPSEDIT_H

#include <QWidget>
#include "modele/listechamps.h"
#include <QSize>

namespace Ui {
class ListeChampsEdit;
}
/**
 * @brief La classe ListeChampsEdit permet d'éditer une liste de champs
 */
class ListeChampsEdit : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(ListeChamps * listeChamps READ listeChamps WRITE setListeChamps USER true)

public:
    explicit ListeChampsEdit(QWidget *parent = 0);
    ~ListeChampsEdit();
    /**
     * @brief listeChamps renvoit la Liste associé au Widget
     * @return la liste associé au Widget
     */
    ListeChamps * listeChamps() const;
    /**
     * @brief setListeChamps est un setter pour la ListeChamps associé au Widget
     * @param listeChamps la nouvelle ListeChamps
     */   
    void setListeChamps(ListeChamps *listeChamps) ;
    /**
     * @brief sizeHint
     * @return
     */
    QSize sizeHint() const;

private:
    /**
     * @brief ui Un pointeur vers la user interface
     */
    Ui::ListeChampsEdit *ui;
    /**
     * @brief mListeChamps est la Structure représentée par ce widget
     */
    ListeChamps * mListeChamps;
};

#endif // LISTECHAMPSEDIT_H
