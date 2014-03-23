#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QStringList>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QTableView>
#include <QDebug>
#include <QItemEditorFactory>
#include <QItemEditorCreatorBase>
#include <QFileDialog>
#include <QLineEdit>

#include "modele/image.h"
#include "modele/contacts.h"
#include "modele/mymodelcontacts.h"
#include "modele/listechamps.h"
#include "modele/champ.h"
#include "ajouterchamp.h"
#include "imageedit.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
      QItemEditorFactory *factory= new QItemEditorFactory;
      factory->registerEditor((QVariant::Type)qMetaTypeId<Image*>(), new         QStandardItemEditorCreator<ImageEdit>());
      factory->registerEditor((QVariant::Type)qMetaTypeId<QString>(), new         QStandardItemEditorCreator<QLineEdit>());
      QItemEditorFactory::setDefaultFactory(factory);


       ui->setupUi(this);
       Contact * contact1 =new Contact;
       Nom * nom1=new Nom("Nom");
       nom1->fromString("doudou");

       contact1->setNom(nom1);
       Image * image1=new Image("Image");
       image1->setUrl(QUrl("file:///home/bama/Documents/c++/doudouchat.jpg"));

       contact1->listeChamps().ajouterChamp(image1);
       contact1->listeChamps().ajouterChamp(Contact::creerNom("Nom"));


       Contact * contact2=new Contact;
       Nom * nom2=new Nom("Nom");
       nom2->fromString("tichat");

       contact2->setNom(nom2);
       Image * image2=new Image("Image");
       image2->setUrl(QUrl("file:///home/bama/Documents/c++/bama.jpg"));

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

       connect(ui->actionAjouter_champ,&QAction::triggered,
               this,&MainWindow::ajouterChamp);

       showMaximized();
       // en ajoutant au moins un champs dans les ListeChamps
}

MainWindow::~MainWindow()
{

    delete ui;
}

//demander à l'user que champ il veut ajout avec le nom du champ et d'ajouter le champs ds le contact courant
void MainWindow::ajouterChamp()
{
    Champ * nouveauChamp=AjouterChamp::get();
    mContacts.getContact(ui->listView->currentIndex().row())->listeChamps().ajouterChamp(nouveauChamp);
}
