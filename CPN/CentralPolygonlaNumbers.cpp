//
//  polygon.cpp
//  polygonalNumbers
//
//  Created by student on 4/22/22.
//
#include <iostream>
#include <fstream>


class CentralPolygonalNumbers{
public:
    CentralPolygonalNumbers();
    CentralPolygonalNumbers(int nMax);
    ~CentralPolygonalNumbers();
    void display();
    bool save(std::string strFileName);
private:
    int m_nMax;
    int* mp_iNumbers;//pointer to int
};

CentralPolygonalNumbers::CentralPolygonalNumbers(){
    int nMax = 0;
    mp_iNumbers = new int[nMax+1];
    for (int i = 0 ; i < nMax ; i++){
        mp_iNumbers[i] = ((i * i) + i + 2)/2;
    }
}

CentralPolygonalNumbers::CentralPolygonalNumbers(int nMax){
    m_nMax = nMax;
    mp_iNumbers = new int[nMax+1];
    for (int i = 0 ; i <= nMax ; i++){
        mp_iNumbers[i] = ((i * i) + i + 2)/2;
        std::cout << "n:" << i << ",max number of pieces: "<< mp_iNumbers[i] << std::endl;
    }
}

CentralPolygonalNumbers::~CentralPolygonalNumbers(){
    delete[] mp_iNumbers;
    std::cout << "~CentralPolygonalNumbers destructor called" << std::endl;
}

bool CentralPolygonalNumbers::save(std::string strFileName){
std::ofstream ofsNumbers;
    for (int i = 0;i <= m_nMax + 1;i++ ){
        ofsNumbers << mp_iNumbers[i];
    }
    ofsNumbers.close();
    return true;
}

int main(){
    CentralPolygonalNumbers cpn(10);
    cpn.save("CPN");
}
