#include "image.h"
#include <QDebug>

Image::Image(QString nomChamp, QObject *parent) :
    Champ(nomChamp,parent)
{
}

QString Image::toString() const
{
   return "";
}

bool Image::fromString(const QString)
{
   return false;
}

QVariant Image::toQVariant()
{
   return QVariant::fromValue(this);
}

bool Image::fromQVariant(const QVariant v)
{
   Image * image=v.value<Image*>();
   setUrl(image->url());
   return true;
}

QVariant Image::image() const
{
    if(mImage.isNull()) return QVariant();
    return mImage;
}

void Image::setUrl(QUrl url)
{
  mUrl=url;
  if(url.isLocalFile())
  {
      if(mImage.load(url.toLocalFile())) mImage=mImage.scaledToHeight(400);
  }
}

 QUrl Image::url()
 {
     return mUrl;
 }
