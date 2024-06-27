#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

int maxIndexDiff(int a[], int n) { 
    int rightmax[n];
    rightmax[n - 1] = a[n-1];

    for (int i = n - 2; i >= 0; i--) {
        rightmax[i] = max(rightmax[i + 1], a[i]);
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << rightmax[i] << " ";
    // }
    // cout << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    
    

    int ans = INT_MIN, i = 0, j = 0;
    while (i < n and j < n) {
        if (rightmax[j] >= a[i]) {
            ans = max(ans, j - i);
            ++j;
        } else {
            ++i;
        } 
    }

    return ans;
}

int main() {
    int a[] = {34, 8, 10, 3, 2, 80, 30, 33, 1};
    cout << maxIndexDiff(a, 9) << endl;
    return 0;
}