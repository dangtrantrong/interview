#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
using namespace std;

/* Using Hashing */

int getPairsCount(int arr[], int n, int sum)
{
    int count = 0;
    map<int, int> pairNumbers;
    for (int i = 0; i < n; i++) {
        if (pairNumbers.find(sum - arr[i]) != pairNumbers.end()) {
            ++count;
        }
        pairNumbers[arr[i]]++;
    }

    for (auto &i : pairNumbers) {
        cout << i.first << ", " << i.second << endl;
    }

    return count;
}



int main() {
    int arr[] = {1, 2, 3, 4, 5};

    cout << getPairsCount(arr, 5, 6) << endl;

    return 0;
}