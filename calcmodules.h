#ifndef CALCMODULES_H
#define CALCMODULES_H

#include "createelements.h"
#include <vector>

class Node{

    unsigned int id;
    float Q;
    float Pressure;
    float geoMark;
};

class Branche{

    unsigned int id;
    unsigned int firstNode;
    unsigned int endNode;
    float H;
    float x;
    float resistance;
    std::vector <Element*> elements;

public:

    void createElement();
};

class Scheme {

    std::vector <Node*> nodes;
    std::vector <Branche*> branche;
    std::vector <int> contours;
    std::vector <int> graph;

public:

    void findSkeleton ();
    void findCountours ();
    void optimizationScheme ();

};

class CalcModules{
    std::vector <Scheme*> schemes;

public:

    void findSchemes ();
    void initializeParameters ();
    void computeScheme ();
    void showResult ();

};

#endif // CALCMODULES_H
