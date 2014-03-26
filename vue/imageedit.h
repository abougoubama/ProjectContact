#ifndef IMAGEEDIT_H
#define IMAGEEDIT_H

#include <QWidget>
#include <QSize>
#include "modele/image.h"

namespace Ui {
class ImageEdit;
}
/**
 * @brief La classe ImageEdit permet d'éditer un champ Image
 */
class ImageEdit : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(Image * image READ image WRITE setImage USER true)

public:
    /**
     * @brief Le constructeur par défaut
     */
    explicit ImageEdit(QWidget *parent = 0);
    ~ImageEdit();

    /**
     * @brief image renvoie l'objet Image associé
     * @return L'objet Image associé
     */
    Image * image() const;
    /**
     * @brief setImage modifie l'objet Image
     * @param l'objet Image
     */
    void setImage(Image *image) ;

    QSize sizeHint() const;


private:
    /**
     * @brief ui Un pointeur vers la user interface
     */
    Ui::ImageEdit *ui;
    Image * mImage;

};

#endif // IMAGEEDIT_H
