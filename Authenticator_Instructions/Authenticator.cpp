//
//  main.cpp
//  breach
//
//  Created by student on 2/23/22.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    
    const char realCodeChar1 = 'E';
    const char realCodeChar2 = 'C';
    const char realCodeChar3 = 'A';
    
    char userCodeChar1;
    char userCodeChar2;
    char userCodeChar3;
    
    //collect user code chars
    
    cout << "Enter the first letter to the code:" << endl;
    cin >> userCodeChar1;
    cout << "Enter the second letter to the code:" << endl;
    cin >> userCodeChar2;
    cout << "Enter the third letter to the code:" << endl;
    cin >> userCodeChar3;
    cout << " " << endl;
    
 //   string concat the chars, this seems like a terrbile way but its the only one that works
    std::string realCode;
    realCode += realCodeChar1;
    realCode += realCodeChar2;
    realCode += realCodeChar3;

    std::string userCode;
    userCode += userCodeChar1;
    userCode += userCodeChar2;
    userCode += userCodeChar3;
    
    cout << "Authenticator Code: " << realCode << endl;
    cout << "Message Code: " << userCodeChar1 << userCodeChar2 << userCodeChar3 << endl;
    
    cout << " " << endl;
 
    //auth check from chars
    bool doLexo = false;
    if (userCodeChar1 == realCodeChar1 && userCodeChar2 == realCodeChar2 && userCodeChar3 == realCodeChar3){
        cout << "Message is authentic." << endl;
    }else{
        cout<< "Message is invalid." << endl;
        doLexo = true;
    }
    
    cout << "Concurence: ";
    if (realCode == userCode){
        cout << "message is authentic" << endl;
    }else{
        cout<< "message is invalid." << endl;
    }
    
    cout << " " << endl;
    
    cout << "Characterization of Message Code" << endl;
    cout << "--------------------------------" << endl;

    int userCheckSum = ((int)(userCodeChar1) + (int)(userCodeChar2) + (int)(userCodeChar3)) % 7;
    const int realCheckSum = 5;
    
    //ascii calculation
    cout << "ASCII values of Message Code Characters: " << int(userCodeChar1) << ", " << int(userCodeChar2) << ", " <<  int(userCodeChar3) << endl;
    cout << "Sum of the ASCII VAlues for Message Code Characters: " << int(userCodeChar1) + int(userCodeChar2) + int(userCodeChar3) << endl;
    
    if (userCheckSum == realCheckSum){
        cout << "Message Code Checksum is valid: 5" << endl;
    }else{
        cout << "Message Code Checksum is invalid: " << userCheckSum << "; expected: 5" << endl;
    }
    
    //check each index of the code
    if (realCodeChar1 != userCodeChar1) {
        cout << "First characters do not match: Message: " << userCodeChar1 << " Authenticator: "<< realCodeChar1 << endl;
    }
    if (realCodeChar2 != userCodeChar2) {
        cout << "Second characters do not match: Message: " << userCodeChar2 << " Authenticator: "<< realCodeChar2 << endl;
    }
    if (realCodeChar3 != userCodeChar3) {
        cout << "Third characters do not match: Message: " << userCodeChar3 << " Authenticator: "<< realCodeChar3 << endl;
    }
    
    //lexicograph check
    if (doLexo){
    if (userCheckSum < realCheckSum){
        cout << "Message code (" << userCode << ") is lexicographically greater than Authenticator code (ECA)" << endl;
    }else{
        cout << "Message code (" << userCode << ") is lexicographically less than Authenticator code (ECA)" << endl;
    }
    }

    return 0;
}
