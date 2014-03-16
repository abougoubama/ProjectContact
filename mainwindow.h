#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QStringListModel>



#include <QMainWindow>

#include "contacts.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    QStringListModel *modele;

    Contacts mContacts;

};

#endif // MAINWINDOW_H
