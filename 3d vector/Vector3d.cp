
#include <iostream>
#include <cmath>
#include <vector>
#include "Vector3d.h.hh"

Vector3d::Vector3d(){ //default
    this->m_vector.at(0) = 0.0;
    this->m_vector.at(1) = 0.0;
    this->m_vector.at(2) = 0.0;
}

Vector3d::Vector3d(double Dx, double Dy, double Dz){//overloaded
    this->m_vector.at(0) = Dx;
    this->m_vector.at(1) = Dy;
    this->m_vector.at(2) = Dz;
    return;
}

Vector3d::~Vector3d(){
}

void Vector3d::display(){
    std::cout << this->m_vector.at(0) << " x, " << this->m_vector.at(1) << " y, " << this->m_vector.at(2) << " z" << std::endl;
    return;
}

double Vector3d::dot(Vector3d vec3d){
    double dDotProduct = 0.0;
    for (unsigned int i =0;i < this->m_vector.size(); i++){
        dDotProduct += this->m_vector.at(i) * vec3d.m_vector.at(i);
    }
    return dDotProduct;
}

int main(){
    
    double const PI = 3.14159265;
    
    double Fx = 10.0 * std::cos(45 * PI/180.0); //newtons
    double Fy = 10.0 * std::sin(45 * PI/180.0);
    double Fz = 0.0;
    
    double Dx = 10.0; //meters
    double Dy = 0.0;
    double Dz = 0.0;
    
    Vector3d vec3dForce(Fx,Fy,Fz);
    Vector3d vec3dDisplacement(Dx,Dy,Dz);
    
    vec3dForce.display();
    vec3dDisplacement.display();
    
    double dWork = vec3dForce.dot(vec3dDisplacement); //Joules
    std::cout << "Work: " << dWork << std::endl;
    
    return 0;
}
