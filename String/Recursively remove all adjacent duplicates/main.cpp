#include <iostream>
#include <memory>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <climits>

using namespace std;

/* Recursively remove all adjacent duplicates */
string removeAdj( string s, string str) {
	cout << "s: " << s << "\n";
    for (int i = 0; i < s.size(); i++) {
        if(s[i] != s[i-1] && s[i] != s[i+1]){
            str += s[i];
        }
    }
	cout << "str: " << str << "\n";

    if (s.size() == str.size()) {
        return s;
    }

    return removeAdj(str, ""); 
}

string rremove( string s) {
    string ans = removeAdj(s, ""); 
    return ans;
}