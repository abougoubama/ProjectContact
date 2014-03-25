#ifndef ENUMEDIT_H
#define ENUMEDIT_H

#include <QWidget>
#include <QComboBox>
#include "modele/enum.h"

namespace Ui {
class EnumEdit;
}

class EnumEdit : public QComboBox
{
    Q_OBJECT
    Q_PROPERTY(Enum* enum READ getEnum WRITE setEnum USER true)

public:
    explicit EnumEdit(QWidget *parent = 0);
    ~EnumEdit();
     Enum * getEnum() const;
     void setEnum(Enum *c);

private:
    Enum* mEnum;
};

#endif // ENUMEDIT_H
