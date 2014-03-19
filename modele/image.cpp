#include "image.h"
#include <QDebug>

Image::Image(QObject *parent) :
    Champ(parent)
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

QVariant Image::toQVariant() const
{
   return mUrl;
}

bool Image::fromQVariant(const QVariant v)
{
   setUrl(v.toString());
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
