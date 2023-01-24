#include "workxml.h"
#include "createelements.h"
#include "calcmodules.h"
#include <QCoreApplication>
#include <iostream>
#include <vector>


int main(int argc, char *argv[])
{
    QCoreApplication ac(argc, argv);
    setlocale(LC_ALL, "RUS");
   /*
    const int MIN_VALUE = 0;
    const int MAX_VALUE = 5;
    graf_my a;
    a.set_matrix();
    srand(10);
*/
   // writeData();
    WorksXml worksXml("library.xml", "pipes","pipe");
    double a = worksXml.getParameter("id","3","diameter" ).toDouble();
    a = worksXml.getParameter("id","7","diameter" ).toDouble();

    ElementFactory* elementFactory;
    elementFactory = new RegulatorFactory;
    Element* regualror;
    regualror = elementFactory->createElement();
    regualror->computeH();
    regualror->computeS();
    CalcModules calcModules;
    calcModules.findSchemes();
    return ac.exec();
}

