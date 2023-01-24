#ifndef CREATEELEMENTS
#define CREATEELEMENTS

class Element {

    unsigned id;
    float S;
    float H;

public:

//   virtual ~Element();
    virtual void computeH() = 0;
    virtual void computeS() = 0;
    virtual void setParameters() = 0;
};

class Pipe : public Element{

    float k;
    float diameter;
    float length;

public:

    void computeH();
    void computeS();
    void setParameters();
};

class Regulator : public Element{

    float maxS;
    float minS;
    float position;

public:

    void setParameters();
};

class RegulatorPressure : public Regulator{

public:

    void computeH();
    void computeS();
};

class RegulatorFlow : public Regulator{

public:

    void computeH();
    void computeS();
};

class GateValve : public Regulator{

public:

    void computeH();
    void computeS();
};

class SourceForce : public Element{

    int* H;
    int* Q;

public:
    void setParameters();
};

class Pump : public SourceForce{

public:
    void computeH();
    void computeS();
};

class tank : public SourceForce{

public:
    void computeH();
    void computeS();
};

class ElementFactory {

public:

   // virtual ~ElementFactory();
    virtual Element* createElement() = 0;
};

class PipeFactory : public ElementFactory {

public:

    Element* createElement();
};


class SourceForceFactory : public ElementFactory {

public:

    Element* createElement();
};

class PlantFactory : public ElementFactory {

public:

    Element* createElement();
};

class RegulatorFactory : public ElementFactory {

public:

    Element* createElement();
};

#endif // CREATEELEMENTS

