#include "listechampsedit.h"
#include "ui_listechampsedit.h"
#include "modele/listechamps.h"
#include "modele/mymodellistechamps.h"

ListeChampsEdit::ListeChampsEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListeChampsEdit)
{
    ui->setupUi(this);
}

ListeChampsEdit::~ListeChampsEdit()
{
    delete ui;
}

ListeChamps * ListeChampsEdit::listeChamps() const
{

    return mListeChamps;
}

int max(int a, int b);
void ListeChampsEdit::setListeChamps(ListeChamps *listeChamps)
{
    mListeChamps=listeChamps;
    ui->tableView->setModel(new MyModelListeChamps(*listeChamps));
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

QSize ListeChampsEdit::sizeHint() const
{
    return QSize(ui->tableView->sizeHint().width()*2,ui->tableView->model()->rowCount()*30);
}
