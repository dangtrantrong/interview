#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

int romanToDecimal(string &str) {
    int number = 0;
    unordered_map<char, int> mp = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    for (int i = 0; i < str.size(); i++) {
        if(mp[str[i]]>=mp[str[i+1]])
            number += mp[str[i]];
        else
            number-=mp[str[i]];
    }
    
    return number;
}

int main() {
    string str;
    cin >> str;
    cout << romanToDecimal(str) << endl;
    return 0;
}