/// @file <MusicalNotes.cpp>
/// @brief <prints the values of notes>
/// @author chinnici@chapman.edu
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
    double totalFrequency; //the final awnswer
    double totalWavelength; //final wavelenght in meters
    double refrenceFrequency = 16.35;
    const double dTwelfthRootOfTwo = 1.059463094359;
    int octaveNumber = 0;
    int halfStep = 0; //can be between 0 and 11 inclusive
    int speedOfSound = 345;

    cout << "The reference Frequncy is " << refrenceFrequency << endl;
    cout << "The speed of sound in a room is " << speedOfSound << " m/s" << endl;

    // this is the freqency equation
    
    totalFrequency = refrenceFrequency * pow(2 , octaveNumber) * pow(dTwelfthRootOfTwo , halfStep);

    //this is the wavlength equation
    totalWavelength = speedOfSound / totalFrequency;
    
    cout << "Note: C0" << "; nu: " << octaveNumber << "; k: " << halfStep << "; frequency: " << totalFrequency << "Hz" << "; wavelength: " << (totalWavelength * 100) << "cm" << endl;
    
    //C#0
    
    octaveNumber = 0;
    halfStep = 1;
    totalFrequency = refrenceFrequency * pow(2 , octaveNumber) * pow(dTwelfthRootOfTwo , halfStep);
    totalWavelength = speedOfSound / totalFrequency;
    cout << "Note: C#0" << "; nu: " << octaveNumber << "; k: " << halfStep << "; frequency: " << totalFrequency << "Hz" << "; wavelength: " << (totalWavelength * 100) << "cm" << endl;
    
    //D0
   
    octaveNumber = 0;
    halfStep = 2;
    totalFrequency = refrenceFrequency * pow(2 , octaveNumber) * pow(dTwelfthRootOfTwo , halfStep);
    totalWavelength = speedOfSound / totalFrequency;
    cout << "Note: D0" << "; nu: " << octaveNumber << "; k: " << halfStep << "; frequency: " << totalFrequency << "Hz" << "; wavelength: " << (totalWavelength * 100) << "cm" << endl;
    
    //C4
    octaveNumber = 4;
    halfStep = 0;
    totalFrequency = refrenceFrequency * pow(2 , octaveNumber) * pow(dTwelfthRootOfTwo , halfStep);
    totalWavelength = speedOfSound / totalFrequency;
    cout << "Note: C4" << "; nu: " << octaveNumber << "; k: " << halfStep << "; frequency: " << totalFrequency << "Hz" << "; wavelength: " << (totalWavelength * 100) << "cm" << endl;
    
    //D#7
    octaveNumber = 7;
    halfStep = 3;
    totalFrequency = refrenceFrequency * pow(2 , octaveNumber) * pow(dTwelfthRootOfTwo , halfStep);
    totalWavelength = speedOfSound / totalFrequency;
    cout << "Note: D#7" << "; nu: " << octaveNumber << "; k: " << halfStep << "; frequency: " << totalFrequency << "Hz" << "; wavelength: " << (totalWavelength * 100) << "cm" << endl;
    
    //C8
    octaveNumber = 8;
    halfStep = 0;
    totalFrequency = refrenceFrequency * pow(2 , octaveNumber) * pow(dTwelfthRootOfTwo , halfStep);
    totalWavelength = speedOfSound / totalFrequency;
    cout << "Note: C8" << "; nu: " << octaveNumber << "; k: " << halfStep << "; frequency: " << totalFrequency << "Hz" << "; wavelength: " << (totalWavelength * 100) << "cm" << endl;

}
