#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QStringListModel>

#include <QMainWindow>
#include "modele/contacts.h"


namespace Ui {
class MainWindow;
}
/**
 * @brief La fenetre principale
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    /**
     * @brief Le constructeur par défaut
     */
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    /**
     * @brief ajouterChamp , méthode qui permet au user d'ajouter un champ
     */
    void ajouterChamp();
    /**
     * @brief creerNouveauContact , méthode qui permet au user de créer un NouveauContact
     */
    void creerNouveauContact();
    

private:
    bool charger(QString nomFichier);
    void connecter();
private slots:

private:
    /**
     * @brief ui est la user interface
     */
    Ui::MainWindow *ui;
    /**
     * @brief modele est le modèle représentant la liste de Contacts
     */
    QStringListModel *modele;
    /**
     * @brief mContacts est la liste de Contacts
     */
    Contacts *mContacts;

};

#endif // MAINWINDOW_H
