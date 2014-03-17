#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QStringList>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QTableView>
#include <QDebug>

#include "modele/contacts.h"
#include "modele/mymodelcontacts.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
       ui->setupUi(this);
       Contact * bama=new Contact;
       bama->setNom("Bama");
       Contact * davina=new Contact;
       davina->setNom("Davina");
       mContacts.ajouterContact(bama);
       mContacts.ajouterContact(davina);
       MyModelContacts * model= new MyModelContacts(mContacts);


       ui->listView->setModel(model);

       connect(ui->listView->selectionModel(),&QItemSelectionModel::currentChanged,
               [this](const QModelIndex & current, const QModelIndex & )
       {
           ui->contactWidget->setContact(mContacts.getContact(current.row()));

       });
}

MainWindow::~MainWindow()
{

    delete ui;
}
