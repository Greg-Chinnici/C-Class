/// @file <hello_namespace.cpp>
/// @brief <prints a word then prints an input>
/// @author chinnici@chapman.edu
#include <iostream>
using namespace std;
int main()
{
    string strMessage;
    cout << "Halo" << endl;
    cin >> strMessage;
    cout << "Message: " << strMessage << endl;
    return 0;
}
