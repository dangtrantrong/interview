#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

int countTheTriplets(int a[], int n) {
    int count = 0;
    int arrChecker[100] = {0};
    for (int i = 0; i < n; i++) {
        arrChecker[a[i]] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
        {
            if (arrChecker[a[i] + a[j]] == 1) {
                ++count;
            }
        }   
    }
    return count;
}

int main() {
    
    int a[] = {1, 5, 3, 2, 6};
    cout << countTheTriplets(a, 5) << endl;
    return 0;
}