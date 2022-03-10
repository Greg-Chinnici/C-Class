
//
//  Pi.cpp
//  Project Pi
//
//  Created by student on 3/2/22.
//

#include<iostream>
#include <iomanip>
#include <cmath>
#include <cfloat>
int main(){
    
int n = 1048576; //2^20
double piOver4 = 0.0;

std::cout << "What is the upper bound for n:" << std::endl;
std::cin >> n;
std::cout << std::endl;

std::cout << std::setprecision(DBL_DIG);
    
for (int k = 0 ; k < n ; k++){
    piOver4 += pow(-1,k) / (2.0 * k + 1);
}

double pi = (4 * piOver4);

std::cout << "PI (approx): " << pi << "; n: " << std::setw(7) << n << std::endl;
std::cout << "PI (actual): " << "3.141592653589793" << std::endl;

std::cout << "Decimal digits of precision: " << DBL_DIG << std::endl;
std::cout << "Number of base 2 mantissa digits of double precision floating point value: " <<  DBL_MANT_DIG << std::endl;
std::cout << "Next representable number from 3.141592653589793: " << std::nextafter(3.141592653589793, 3.14) << std::endl;
    
return 0;
}
