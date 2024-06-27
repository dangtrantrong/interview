#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

map<int, int> mapElement;

bool arrayInArray(int arr1[], int arr2[]) {
    
    for (int i = 0; i < 10; i++) {
        mapElement[arr1[i]]++;
    }

    for (auto& x : mapElement) {
        cout << x.first << " " << x.second << endl;
    }

    for (int i = 0; i < 4; i++) {
        if (mapElement[arr2[i]] != 1) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {1, 2, 3, 11};
    cout << boolalpha << arrayInArray(arr1, arr2) << endl;
    return 0;
}