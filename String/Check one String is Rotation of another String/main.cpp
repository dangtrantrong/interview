#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;

bool checkRotation(string mainString, string rotationString) {
    if (mainString.length() != rotationString.length()) 
        return false;
    
    string concatedString = mainString + mainString;

    if (concatedString.find(rotationString) != string::npos)
        return true;

    return false;
}

int main(int argc, char *argv[]) {
    cout << boolalpha << checkRotation("abcd", "adab") << endl;
}