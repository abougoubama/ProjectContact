#include "nouveaucontact.h"
#include "ui_nouveaucontact.h"
#include "modele/contacts.h"

NouveauContact::NouveauContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NouveauContact)
{
    ui->setupUi(this);
}

NouveauContact::~NouveauContact()
{
    delete ui;
}

Contact* NouveauContact::get()
{
  NouveauContact * nouveauContact =new NouveauContact;
  if(nouveauContact->exec()==QDialog::Accepted)
  {
      return Contacts::creerNouveauContact(nouveauContact->ui->typeDuContactComboBox->currentText());

  }
  return nullptr;
}
