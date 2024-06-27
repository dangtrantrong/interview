#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>

using namespace std;

string printLargest(int n, vector<string> &arr) {
    string output;
    sort(arr.begin(), arr.end(),[](string a, string b){
        return (a + b) > (b + a);
    });

    for (int i = 0; i < n; i++)
    {
        output += arr[i];
    }
    return output;
}

int main() {
    vector<string> arr = {"3", "30", "34", "5", "9"};
    cout << printLargest(5, arr);
    return 0;
}