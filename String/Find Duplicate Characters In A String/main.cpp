#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

void printDuplicate(string str) {
    map<char, int> counts;
    for (int i = 0; i < str.length(); i++) {
        counts[str[i]]++;
    }
    for (map<char, int>::iterator it = counts.begin(); it!= counts.end(); ++it) {
        if (it->second > 1) {
            cout << it->first << ", count = " << it->second << endl;
        }
    }
}

int main() {
    string str = "abacaba";
    printDuplicate(str);
    return 0;
}