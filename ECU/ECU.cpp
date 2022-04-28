//
//  ECU.cpp
//  ECU
//
//  Created by student on 4/22/22.
//


#include <iostream>

class ECU{
public:
    ECU();
    ~ECU();
    void handleCommand(char cCommand);
    void displayWheel();
    bool isCarOn = true;
private:
    bool m_ifHydraulicJacks = false; // button A
    bool m_ifBeltTires = false; //button B
    bool m_ifIrIllumation = false; // button E
   
    void useHydraulicJacks();
    void useBeltTires();
    void useIrIllumation();
    void useCarOn();
    
    
};

ECU::ECU(){
  
}

ECU::~ECU(){
    //
}

void ECU::displayWheel(){
    std::cout << "      (A)" << std::endl;
    std::cout << "   (F)(G)(B)" << std::endl;
    std::cout << "   (E)   (C)" << std::endl;
    std::cout << "      (D)" << std::endl;
   
}

void ECU::handleCommand(char cCommand){

    switch (cCommand){
        case 'A':
        case 'a':
            useHydraulicJacks();
            break;
        case 'B':
        case 'b':
            useBeltTires();
            break;
        case 'E':
        case 'e':
            useIrIllumation();
            break;
        case 'x':
        case 'X':
            useCarOn();
    }
}

void ECU::useHydraulicJacks(){
    m_ifHydraulicJacks = !m_ifHydraulicJacks;
    if (m_ifHydraulicJacks){
        if (m_ifBeltTires){
            useBeltTires();
        }
        std::cout << "Hydraulic Jacks activated" << std::endl;
    }
    if (!m_ifHydraulicJacks){
        std::cout << "Hydraulic Jacks deactivated" << std::endl;
    }

}

void ECU::useBeltTires(){
    m_ifBeltTires = !m_ifBeltTires;
    if (m_ifBeltTires){
        std::cout << "Belt Tires activated" << std::endl;
    }
    if (!m_ifBeltTires){
        std::cout << "Belt Tires deactivated" << std::endl;
    }
    
}

void ECU::useIrIllumation(){
    m_ifIrIllumation = !m_ifIrIllumation;
    if (m_ifIrIllumation){
        std::cout << "IR Illumination activated" << std::endl;
    }
    if (!m_ifIrIllumation){
        std::cout << "IR Illumation deactivated" << std::endl;
    }
   
}

void ECU::useCarOn(){
    if (isCarOn){
        std::cout << "Car turned Off" << std::endl;
        isCarOn = false;
    }
}

int main(){
    ECU ecu;
    char c;
    while (ecu.isCarOn){
        ecu.displayWheel();
        std::cin >> c;
        ecu.handleCommand(c);
        
    }
    
    return 0;
}
