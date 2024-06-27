#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

int atoiImplement(string str) {
    int i = 0;
    int sign = 1;
    if (str[0] == '-') {
        sign = -1;
        i++;
    }

    int res = 0;
    for (; i  < str.size(); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return -1;
        }
        res = res * 10 + str[i] - '0';
    }

    return res * sign;
    
}

int main() {
    cout << atoiImplement("21") << "\n";
}