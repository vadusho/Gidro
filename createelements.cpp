#include "createelements.h"
#include <Qstring>
#include <iostream>

  //  Element :: ~Element(){};

    void Pipe :: computeH(){
        std::cout<<"Pipe compute H"<<std::endl;
    }
    void Pipe :: computeS(){
        std::cout<<"Pipe compute S"<<std::endl;
    }
    void Pipe :: setParameters(){
        std::cout<<"Pipe setParameters"<<std::endl;
    }


    void Regulator :: setParameters(){
        std::cout<<"Regulator setParameters"<<std::endl;
    }


    void RegulatorPressure :: computeH(){
        std::cout<<"RegulatorPressure compute H"<<std::endl;
    }
    void RegulatorPressure :: computeS(){
        std::cout<<"RegulatorPressure compute S"<<std::endl;
    }

    void RegulatorFlow ::computeH(){
        std::cout<<"RegulatorFlow compute H"<<std::endl;
    }
    void RegulatorFlow ::computeS(){
        std::cout<<"RegulatorFlow compute S"<<std::endl;
    }

    void GateValve :: computeH(){
        std::cout<<"GateValve compute H"<<std::endl;
    }
    void GateValve :: computeS(){
        std::cout<<"GateValve compute S"<<std::endl;
    }


    void SourceForce :: setParameters(){
        std::cout<<"SourceForce setParameters"<<std::endl;
    }

    void Pump :: computeH(){
        std::cout<<"Pump compute H"<<std::endl;
    }
    void Pump :: computeS(){
        std::cout<<"Pump compute S"<<std::endl;
    }

    void  tank ::computeH(){
        std::cout<<"tank compute H"<<std::endl;
    }
    void  tank ::computeS(){
        std::cout<<"tank compute S"<<std::endl;
    }

  // ElementFactory :: ~ElementFactory(){}

    Element* PipeFactory :: createElement(){
        std::cout<<"call PipeFactory"<<std::endl;
        return new Pipe;
    }



    Element* SourceForceFactory :: createElement(){
        std::cout<<"call SourceForceFactory"<<std::endl;
        return new Pump;
    }

    Element* PlantFactory :: createElement(){
        std::cout<<"call SourceForceFactory"<<std::endl;
        return new Pump;
    }

    Element* RegulatorFactory :: createElement(){
        std::cout<<"call RegulatorFactory"<<std::endl;
        return new Pump;
    }
