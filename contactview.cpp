#include "contactview.h"
#include "ui_contactview.h"

ContactView::ContactView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContactView)
{
    ui->setupUi(this);
}

ContactView::~ContactView()
{
    delete ui;
}

//affiche le contact, change le texte du label pour afficher le nom du contact
void ContactView::setContact(Contact *contact)
{
    ui->labelNom->setText(contact->nom());
}
