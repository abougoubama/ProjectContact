#include <QDebug>

#include "contactview.h"
#include "ui_contactview.h"
#include "modele/mymodellistechamps.h"

ContactView::ContactView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContactView)
{
    ui->setupUi(this);

    //ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    //ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

ContactView::~ContactView()
{
    delete ui;
}

int max(int a, int b)
{
    return a>b ?a:b;
}

//affiche le contact, change le texte du label pour afficher le nom du contact
void ContactView::setContact(Contact *contact)
{
    ui->tableView->setModel(new MyModelListeChamps(contact->listeChamps()));
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
    connect(ui->tableView->selectionModel(),&QItemSelectionModel::currentChanged,[this](QModelIndex index,QModelIndex){
        if(index.isValid() && index.column()!=0)
        {
            ui->tableView->verticalHeader()->resizeSection(index.row(),max(ui->tableView->verticalHeader()->sectionSize(index.row()),ui->tableView->indexWidget(index)->sizeHint().height()));
            ui->tableView->horizontalHeader()->resizeSection(index.column(),max(ui->tableView->horizontalHeader()->sectionSize(index.column()),ui->tableView->indexWidget(index)->sizeHint().width()));
        }
        });

}
