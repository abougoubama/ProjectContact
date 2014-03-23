#include "ajouterchamp.h"
#include "ui_ajouterchamp.h"
#include "modele/contact.h"

AjouterChamp::AjouterChamp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterChamp)
{
    //a chaque fois qu'on change le type ça vas mettre comme nom de champ la chaine de carac
    //correspondant au type
    ui->setupUi(this);
    connect(ui->typeDuChampComboBox,&QComboBox::currentTextChanged,
            [this](QString currentText){
        ui->nomDuChampLineEdit->setText(currentText);
    });
}

AjouterChamp::~AjouterChamp()
{
    delete ui;
}

 Champ* AjouterChamp::get()
{
   AjouterChamp * ajouterchamp =new AjouterChamp;
   if(ajouterchamp->exec()==QDialog::Accepted)
   {
       return Contact::creerChamp(ajouterchamp->ui->nomDuChampLineEdit->text(),
                                  ajouterchamp->ui->typeDuChampComboBox->currentText());

   }
   return nullptr;
}
