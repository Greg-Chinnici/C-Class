//
//  leibnitz_pi_converge.cpp
//  pi
//
//  Created by student on 3/10/22.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfloat>

int main2(){
    
int nFinal = 1048576; //2^20
double piOver4 = 0.0;


std::cout << std::setprecision(DBL_DIG);
for (int n = 2 ; n <= nFinal ; n *= 2){
    for (int k = 0 ; k < n ; k++){
        piOver4 += pow(-1,k) / (2.0 * k + 1);
        }
    double pi = (4 * piOver4);
    std::cout << "PI: " << pi << "; n: " << std::setw(15) << n << std::endl;
    piOver4 = 0.0;
}

return 0;
}
