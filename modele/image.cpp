#include "image.h"
#include <QDir>
#include <QFileInfo>
#include <QDebug>

Image::Image(QString nomChamp, QObject *parent) :
    Champ(nomChamp,parent)
{
}


Image::Image(QDomElement &element, QObject *parent) : Champ(element.attribute("nomChamp"),parent)
{
    setUrl(QUrl(element.text()));
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

QDomElement Image::toXml(QDomDocument &doc) const
{
    QDomElement tag=doc.createElement("Image");
    tag.setAttribute("nomChamp",mNomChamp);
    tag.appendChild(doc.createTextNode(mUrl.toString()));
    return tag;
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
      if(!QFileInfo::exists(url.toLocalFile())) url=QUrl("file://"+QDir::currentPath()+url.toLocalFile());
      if(mImage.load(url.toLocalFile())) mImage=mImage.scaledToHeight(400);
  }
}

 QUrl Image::url()
 {
     return mUrl;
 }
