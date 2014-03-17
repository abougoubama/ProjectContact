#ifndef CONTACTVIEW_H
#define CONTACTVIEW_H

#include <QWidget>
#include "modele/contact.h"

namespace Ui {
class ContactView;
}

class ContactView : public QWidget
{
    Q_OBJECT

public:
    explicit ContactView(QWidget *parent = 0);
    void setContact(Contact *contact);

    ~ContactView();

private:
    Ui::ContactView *ui;
};

#endif // CONTACTVIEW_H
