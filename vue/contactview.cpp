#include "contactview.h"
#include "ui_contactview.h"
#include "modele/mymodellistechamps.h"

ContactView::ContactView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContactView)
{
    ui->setupUi(this);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

ContactView::~ContactView()
{
    delete ui;
}

//affiche le contact, change le texte du label pour afficher le nom du contact
void ContactView::setContact(Contact *contact)
{
    ui->tableView->setModel(new MyModelListeChamps(contact->listeChamps()));

}
