#ifndef NOUVEAUCONTACT_H
#define NOUVEAUCONTACT_H

#include <QDialog>

#include "modele/contact.h"

namespace Ui {
class NouveauContact;
}
/**
 * @brief La classe NouveauContact permet d'accéder à  un nouveau contact
 */
class NouveauContact : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Le constructeur par défaut
     */
    explicit NouveauContact(QWidget *parent = 0);
    ~NouveauContact();
    /**
     * @brief get renvoit le nouveau contact
     * @return le contact
     */
    static Contact* get();

private:
    /**
     * @brief ui est la user interface
     */
    Ui::NouveauContact *ui;
};

#endif // NOUVEAUCONTACT_H
