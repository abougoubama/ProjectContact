#ifndef CHAMP_H
#define CHAMP_H

#include <QObject>
#include <QString>

class Champ : public QObject
{
    Q_OBJECT
public:
    explicit Champ(QObject *parent = 0);
    void setNomChamp(QString nom);
    QString nomChamp();
    /**
     * @brief toString convertit l'objet en format lisible
     * @return une QString contenant un format lisible du champ
     */
    virtual QString toString() const =0;
    /**
     * @brief fromString convertit un QString en champ
     * @return true si la conversion a réussi , false sinon
     */
    virtual bool fromString(const QString)=0;

signals:

public slots:

private:
    QString mNomChamp;

};

#endif // CHAMP_H
