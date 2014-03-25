#ifndef NOUVEAUCONTACT_H
#define NOUVEAUCONTACT_H

#include <QDialog>

#include "modele/contact.h"

namespace Ui {
class NouveauContact;
}

class NouveauContact : public QDialog
{
    Q_OBJECT

public:
    explicit NouveauContact(QWidget *parent = 0);
    ~NouveauContact();
    static Contact* get();

private:
    Ui::NouveauContact *ui;
};

#endif // NOUVEAUCONTACT_H
