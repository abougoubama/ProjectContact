#ifndef ENUMEDIT_H
#define ENUMEDIT_H

#include <QWidget>
#include <QComboBox>
#include "modele/enum.h"

namespace Ui {
class EnumEdit;
}
/**
 * @brief La class EnumEdit est le widget affichant les choix multiple d'un champ à énumération
 */
class EnumEdit : public QComboBox
{
    Q_OBJECT
    Q_PROPERTY(Enum* enum READ getEnum WRITE setEnum USER true)

public:
    /**
     * @brief Le constructeur par défaut
     */
    explicit EnumEdit(QWidget *parent = 0);
    ~EnumEdit();
    /**
     * @brief getEnum renvoie la valeur de la sélection de l'énumération
     * @return La valeur de la sélection
     */
     Enum * getEnum() const;
     /**
      * @brief setEnum initialise l'énumération
      * @param c L'énumération à afficher
      */
     void setEnum(Enum *c);

private:
     /**
     * @brief mEnum une énumération de type Enum
     */
    Enum* mEnum;
};

#endif // ENUMEDIT_H
