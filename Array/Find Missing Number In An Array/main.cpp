#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

int getMissingNumbersMethod1(int a[], int n) {
    int N = n + 1;
    int sum = N * (N + 1) / 2;
    
    for (int i = 0; i < n; i++) {
        sum -= a[i];
    }

    return sum;
}

int getMissingNumbersMethod2(int a[], int n) {
    int N = n + 1;
    int sum = N * (N + 1) / 2;
    int sumArrayA = 0;
    for (int i = 0; i < n; i++) {
        sumArrayA += a[i];
    }

    return sum - sumArrayA;
}

int getMissingNumbers (int a[], int n)
{
    int i, total = 1;
 
    for (i = 2; i < (n + 1); i++) {
        total += i;
        cout << "total " << total << "\n";
        total -= a[i - 2];
        cout << "total_after " << total << "\n";
    }
    return total;
}

int main() {
    int a[] = {4, 2, 3, 5};
    int n = sizeof(a) / sizeof(a[0]);

    cout << getMissingNumbersMethod2(a, n) << endl;

    return 0;
}