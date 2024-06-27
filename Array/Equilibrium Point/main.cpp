#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

int equilibriumPoint(int a[], int n) {
    
    int rightSum = 0, leftSum = 0, position = 0;
    for (size_t i = 0; i < n; i++)
    {
        rightSum += a[i];
    }
    for (size_t i = 0; i < n; i++) {
        rightSum -= a[i];
        if (rightSum == leftSum)
        {
            position = i + 1;
            break;
        }
        leftSum += a[i];
    }
    return position;
}

int main() {
    int a[] = {1};
    cout << equilibriumPoint(a, 5) << endl;
}