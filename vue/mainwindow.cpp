#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QStringList>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QTableView>
#include <QDebug>
#include "modele/image.h"

#include "modele/contacts.h"
#include "modele/mymodelcontacts.h"
#include "modele/listechamps.h"
#include "modele/champ.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
       ui->setupUi(this);
       Contact * contact1 =new Contact;
       Nom * nom1=new Nom;
       nom1->fromString("doudou");
       nom1->setNomChamp("Nom");
       contact1->setNom(nom1);
       Image * image1=new Image;
       image1->setUrl(QUrl("file:///home/bama/Documents/c++/doudouchat.jpg"));
       image1->setNomChamp("Image");
       contact1->listeChamps().ajouterChamp(image1);


       Contact * contact2=new Contact;
       Nom * nom2=new Nom;
       nom2->fromString("tichat");
       nom2->setNomChamp("Nom");
       contact2->setNom(nom2);
       Image * image2=new Image;
       image2->setUrl(QUrl("file:///home/bama/Documents/c++/bama.jpg"));
       image2->setNomChamp("Image");
       contact2->listeChamps().ajouterChamp(image2);

       mContacts.ajouterContact(contact1);
       mContacts.ajouterContact(contact2);
       MyModelContacts * model= new MyModelContacts(mContacts);

       ui->horizontalLayout->setStretch(0,0);
       ui->horizontalLayout->setStretch(1,1);
       ui->listView->setModel(model);

       connect(ui->listView->selectionModel(),&QItemSelectionModel::currentChanged,
               [this](const QModelIndex & current, const QModelIndex & )
       {
           ui->contactWidget->setContact(mContacts.getContact(current.row()));

       });

       showMaximized();
       // en ajoutant au moins un champs dans les ListeChamps
}

MainWindow::~MainWindow()
{

    delete ui;
}
