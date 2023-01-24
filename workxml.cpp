#include "workxml.h"

#include <QFile>
#include <QtXml/QDomDocument>


#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QXmlStreamAttributes>
/*
void writeData (){
    QFile file("file.xml");
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);     // Устанавливаем автоформатирование текста
    xmlWriter.writeStartDocument();      // Запускаем запись в документ
    xmlWriter.writeStartElement("resources");
    xmlWriter.writeStartElement("checkBox\_1");
    xmlWriter.writeAttribute("boolean1",  "true1" );
    xmlWriter.writeAttribute("boolean2",  "true2" );
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("checkBox\_2");
    xmlWriter.writeAttribute("boolean1",  "true" );
    xmlWriter.writeAttribute("boolean2",  "false" );
    xmlWriter.writeEndElement();

    xmlWriter.writeCharacters("Somebody information");
    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
    file.close();
}

void reatData (){
    QFile file("file.xml");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QXmlStreamReader xmlReader(&file);
    while (!xmlReader.atEnd() && !xmlReader.hasError()){
            QXmlStreamReader::TokenType token = xmlReader.readNext();
            if (token == QXmlStreamReader::StartDocument)
                continue;
            if (token == QXmlStreamReader::StartElement){
                if (xmlReader.name() == "resources"){
                    foreach(const QXmlStreamAttribute &attr, xmlReader.attributes()) {
                     if (attr.name().toString() == "boolean1") {
                         QString value = attr.value().toString();
                                                                    }
                                        }
            }
        }
    }
    file.close();
} */


    WorksXml::WorksXml( const QString nameFile, const QString functionElement, const QString typeElement ){
        this->nameFile = nameFile;
        this->functionElement = functionElement;
        this->typeElement = typeElement;

        file.setFileName(this->nameFile);
        if (!file.exists() || !file.open(QFile::ReadOnly | QFile::Text))
            ; //need exception
        doc.setContent(&file);
        docElem  = doc.documentElement();
        node  = docElem.firstChild();
    }

     QString WorksXml :: getParameter (const QString findAttribute, const QString valueFindAttribute, const QString ValueAttribute ) {

        while( !node.isNull() ) {
            if( node.nodeName() == functionElement ) {
//                if ( element.isNull() ) {
//                    node = node.firstChild();
//                    element = node.toElement();
//                }
                element = node.firstChild().toElement();
                while ( !element.isNull() ) {
                    if ( element.tagName() == typeElement && element.attribute(findAttribute) == valueFindAttribute ) {
                         return element.attribute(ValueAttribute);
                    }
                    element = element.nextSiblingElement();
                }
            }
            node = node.nextSibling();
        }
        file.close();
        return "Error"; //need exception
    }

     bool WorksXml :: nextElement () {
         element = element.nextSiblingElement();
         if ( element.previousSiblingElement() == node.lastChild() )
             return false;
         else
             return true;

     }
     QString WorksXml :: getElement (const QString findAttribute) {

         while( !node.isNull() ) {
             if( node.nodeName() == functionElement ) {
                 if ( element.isNull() )
                     element = node.firstChild().toElement();
                 while ( !element.isNull() ) {
                     if ( element.tagName() == typeElement ){
                         QString atr = element.attribute(findAttribute) ;
                         if ( atr.isEmpty())
                             ; // //need exception
                         else
                             return atr;
                     }
                     element = element.nextSiblingElement();
                 }
             }
             node = node.nextSibling();
         }
         file.close();
         return "Error"; //need exception
     }








     /*
     QString WorksXml :: getElement (const QString findAttribute) {

         QFile file(nameFile);
         if (!file.exists() || !file.open(QFile::ReadOnly | QFile::Text))
             ; //need exception

         QDomDocument doc;
         doc.setContent(&file);

         QDomElement docElem  = doc.documentElement();
         QDomNode node  = docElem.firstChild();
         while( !node.isNull() ) {
             if( node.nodeName() == functionElement ) {
                 node = node.firstChild();
                 QDomElement element = node.toElement();
                 while ( !element.isNull() ) {
                     if ( element.tagName() == typeElement ){
                         QString atr = element.attribute(findAttribute) ;
                         if ( atr.isEmpty())
                             ; // //need exception
                         else
                             return atr;
                     }
                     element = element.nextSiblingElement();
                 }
             }
             node = node.nextSibling();
         }
         file.close();
         return "Error"; //need exception
     }
*/

