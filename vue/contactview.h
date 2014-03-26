#ifndef CONTACTVIEW_H
#define CONTACTVIEW_H

#include <QWidget>
#include "modele/contact.h"

namespace Ui {
class ContactView;
}
/**
 * @brief La classe ContactView est la zone d'affichage d'un contact
 */
class ContactView : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Le constructeur par défaut
     */
    explicit ContactView(QWidget *parent = 0);
    /**
     * @brief setContact détermine le contact à afficher
     * @param contact le contact à afficher
     */
    void setContact(Contact *contact);

    void supprimerChamp();
    ~ContactView();

private:
    /**
     * @brief ui Un pointeur vers la user interface
     */
    Ui::ContactView *ui;
    Contact* mContact;
};

#endif // CONTACTVIEW_H
