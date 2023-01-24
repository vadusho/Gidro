#ifndef WORKXML
#define WORKXML

#include <Qstring>
#include <QFile>
#include <QtXml/QDomDocument>

//void writeData ();
//void reatData ();

class WorksXml { // add exception if file not opens
    QString nameFile;
    QString functionElement;
    QString typeElement;

    QFile file;
    QDomDocument doc;
    QDomElement docElem;
    QDomNode node;
    QDomElement element;

public:
    WorksXml( const QString nameFile, const QString functionElement, const QString typeElement );
    QString getParameter (const QString findAttribute, const QString valueFindAttribute, const QString ValueAttribute );
    QString getElement (const QString findAttribute);
    bool  nextElement();
};

#endif // WORKXML

