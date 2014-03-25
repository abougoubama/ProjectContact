#ifndef IMAGEEDIT_H
#define IMAGEEDIT_H

#include <QWidget>
#include <QSize>
#include "modele/image.h"

namespace Ui {
class ImageEdit;
}

class ImageEdit : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(Image * image READ image WRITE setImage USER true)

public:
    explicit ImageEdit(QWidget *parent = 0);
    ~ImageEdit();
    /**
     * @brief image
     * @return
     */
    Image * image() const;
    /**
     * @brief setImage
     * @param image
     */
    void setImage(Image *image) ;
    /**
     * @brief sizeHint
     * @return
     */
    QSize sizeHint() const;


private:
    Ui::ImageEdit *ui;
    Image * mImage;

};

#endif // IMAGEEDIT_H
