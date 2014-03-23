#include "imageedit.h"
#include "ui_imageedit.h"
#include "modele/image.h"
#include <QFileDialog>
#include <QDebug>

ImageEdit::ImageEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageEdit)
{
    setAutoFillBackground(true);
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,[this](){
        QUrl fileUrl;
        fileUrl= QFileDialog::getOpenFileUrl(this,"Quel image voulez-vous ?", QUrl(), "Image(*.jpeg *.jpg *.JPG *.JPEG *.png *.PNG *.gif *.GIF");
        if(fileUrl.isValid())
        {
            ui->lineEdit->setText(fileUrl.toString());
        }
    });
}

ImageEdit::~ImageEdit()
{
    delete ui;
}

Image * ImageEdit::image() const
{
    mImage->setUrl(QUrl(ui->lineEdit->text()));
    return mImage;
}

void ImageEdit::setImage( Image * image)
{
    mImage= image ;
    ui->lineEdit->setText(mImage->url().toString());

}
 QSize ImageEdit::sizeHint() const
 {
     return QSize(400+600,40);
 }
