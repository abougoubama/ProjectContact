#ifndef AJOUTERCHAMP_H
#define AJOUTERCHAMP_H

#include <QDialog>
#include "modele/champ.h"
#include "ajouterchamp.h"

namespace Ui {
class AjouterChamp;
}

class AjouterChamp : public QDialog
{
    Q_OBJECT

public:
    explicit AjouterChamp(QWidget *parent = 0);
    ~AjouterChamp();
    static Champ* get();

private:
    Ui::AjouterChamp *ui;
};

#endif // AJOUTERCHAMP_H
