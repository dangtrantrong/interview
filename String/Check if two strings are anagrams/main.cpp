#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

bool isAnagram(string a, string b) {
    if (a.size()!= b.size()) {
        return false;
    }
    map<char, int> m;
    for (int i = 0; i < a.size(); i++) {
        m[a[i]]++;
    }
    for (int i = 0; i < b.size(); i++) {
        if (m.find(b[i]) != m.end())
            m[b[i]]--;
        else 
            return false;
    }
    for (auto i : m) {
        if (i.second != 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    cout << boolalpha << isAnagram("argc", "arcg") << endl;
}