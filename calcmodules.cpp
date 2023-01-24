#include "calcmodules.h"
#include "workxml.h"
//#include "createelements.h"
#include <Qstring>
#include <iostream>

void CalcModules :: findSchemes (){
    std::cout<<"Find some schemes"<<std::endl;
    WorksXml worksXml("link.xml", "HydroLinks","Link");
    int a, b,c,d;
    while(true){
        a = worksXml.getElement("SourceID").toInt();
        b = worksXml.getElement("SourcePort").toInt();
        c = worksXml.getElement("ReceiveID").toInt();
        d = worksXml.getElement("ReceivePort").toInt();
        std::cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<std::endl;

        if ( !worksXml.nextElement() )
            break;
    }

}
void CalcModules :: initializeParameters (){
     std::cout<<"Initialize parameters"<<std::endl;
}
void CalcModules :: computeScheme (){
     std::cout<<"Compute scheme"<<std::endl;
}
void CalcModules :: showResult (){
    std::cout<<"Shows result of computed scheme"<<std::endl;
}


void Branche :: createElement(){
    std::cout<<"Create some Element"<<std::endl;
}

void Scheme :: findSkeleton (){
    std::cout<<"Find some Skeleton"<<std::endl;
}
void Scheme :: findCountours (){
    std::cout<<"Find some Countours"<<std::endl;
}
void Scheme :: optimizationScheme (){
    std::cout<<"Optimization Scheme"<<std::endl;
}
