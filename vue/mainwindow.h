#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QStringListModel>

#include <QMainWindow>
#include "modele/contacts.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    /**
     * @brief ajouterChamp
     */
    void ajouterChamp();
    /**
     * @brief creerNouveauContact
     */
    void creerNouveauContact();
    
private slots:

private:
    Ui::MainWindow *ui;
    QStringListModel *modele;

    Contacts *mContacts;

};

#endif // MAINWINDOW_H
