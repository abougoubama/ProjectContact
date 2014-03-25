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
#include "modele/adresse.h"
#include "modele/email.h"
#include "modele/contacts.h"
#include "modele/tel.h"
#include "modele/mymodelcontacts.h"
#include "modele/listechamps.h"
#include "modele/champ.h"
#include "ajouterchamp.h"
#include "vue/nouveaucontact.h"
#include "imageedit.h"
#include "listechampsedit.h"
#include "vue/enumedit.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
      QItemEditorFactory *factory= new QItemEditorFactory;
      factory->registerEditor((QVariant::Type)qMetaTypeId<Image*>(), new  QStandardItemEditorCreator<ImageEdit>());
      factory->registerEditor((QVariant::Type)qMetaTypeId<QString>(), new QStandardItemEditorCreator<QLineEdit>());
      factory->registerEditor((QVariant::Type)qMetaTypeId<ListeChamps*>(), new QStandardItemEditorCreator<ListeChampsEdit>());
      factory->registerEditor((QVariant::Type)qMetaTypeId<Enum*>(), new QStandardItemEditorCreator<EnumEdit>());
      QItemEditorFactory::setDefaultFactory(factory);

      Enum::remplirEnums();

       ui->setupUi(this);


       Contact * contact1 =new Contact;
       Nom * nom1=new Nom("Nom","abougou","bama","tichat","mlle");
       contact1->setNom(nom1);
       Image * image1=new Image("Image");
       image1->setUrl(QUrl("file:////home/bama/Documents/c++/image1"));
       contact1->listeChamps().ajouterChamp(image1);
       Adresse * adresse1=new Adresse("Adresse","1 place de la resistance","91025","Evry","Versaille","FRANCE");
       contact1->listeChamps().ajouterChamp(adresse1);
       Email * email1=new Email("Email","bama.abougou","gmail","com");
       contact1->listeChamps().ajouterChamp(email1);
       Tel * tel1=new Tel("Tel","061566666");
       contact1->listeChamps().ajouterChamp(tel1);
       Enum * test1 = new Enum("griaou",1,0);
       contact1->listeChamps().ajouterChamp(test1);



       Contact * contact2 =new Contact;
       Nom * nom2=new Nom("Nom","Rungen","Davina","sourie","mlle");
       contact2->setNom(nom2);
       Image * image2=new Image("Image");
       image2->setUrl(QUrl("file:////home/bama/Documents/c++/image2"));
       contact2->listeChamps().ajouterChamp(image2);
       Adresse * adresse2=new Adresse("Adresse","1 place de la resistance","91025","Evry","Versaille","FRANCE");
       contact2->listeChamps().ajouterChamp(adresse2);
       Email * email2=new Email("Email","davina.rungen","gmail","com");
       contact2->listeChamps().ajouterChamp(email2);
       Tel * tel2=new Tel("Tel","0615333333");
       contact2->listeChamps().ajouterChamp(tel2);
       Enum * test2 = new Enum("griaou",5,1);
       contact2->listeChamps().ajouterChamp(test2);


        mContacts=new Contacts();
       mContacts->ajouterContact(contact1);
       mContacts->ajouterContact(contact2);

       ui->horizontalLayout->setStretch(0,0);
       ui->horizontalLayout->setStretch(1,1);
       MyModelContacts * model= new MyModelContacts(*mContacts);
       ui->listView->setModel(model);

       connect(ui->listView->selectionModel(),&QItemSelectionModel::currentChanged,
               [this](const QModelIndex & current, const QModelIndex & )
       {
           ui->contactWidget->setContact(mContacts->getContact(current.row()));

       });

       connect(ui->actionAjouter_champ,&QAction::triggered,
               this,&MainWindow::ajouterChamp);

       connect(ui->actionCr_er_un_nouveau_contact,&QAction::triggered,
               this,&MainWindow::creerNouveauContact);

       connect(ui->actionSupprimer_un_contact,&QAction::triggered,
               [this]()
       {
          mContacts->supprimerContact(ui->listView->currentIndex().row());

       });
       connect(ui->actionSauvegarder,&QAction::triggered,[this](){
           QString nomFichier=QFileDialog::getSaveFileName(this,"Où voulez vous enregistrer le fichier de contacts ?", "", "Contacts(*.xml)");
           if(nomFichier=="") return;
           if(nomFichier.section(".",-1)!="xml") nomFichier+=".xml";
           mContacts->sauvegarder(nomFichier);
       });

       connect(ui->actionCharger,&QAction::triggered,[this](){
           QString nomFichier=QFileDialog::getOpenFileName(this,"Quel fichier de contacts voulez vous charger ?", "", "Contacts(*.xml)");
           if(nomFichier=="") return;
           if(nomFichier.section(".",-1)!="xml") nomFichier+=".xml";
           mContacts=Contacts::charger(nomFichier);
           MyModelContacts * model= new MyModelContacts(*mContacts);
           ui->listView->setModel(model);

           connect(ui->listView->selectionModel(),&QItemSelectionModel::currentChanged,
                   [this](const QModelIndex & current, const QModelIndex & )
           {
               ui->contactWidget->setContact(mContacts->getContact(current.row()));

           });
       });

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
    if(nouveauChamp!=nullptr) mContacts->getContact(ui->listView->currentIndex().row())->listeChamps().ajouterChamp(nouveauChamp);
}
//demander à l'user de creer unnouveau contact
void MainWindow::creerNouveauContact()
{
    Contact * nouveauContact=NouveauContact::get();
    if(nouveauContact!=nullptr) mContacts->ajouterContact(nouveauContact);

}



