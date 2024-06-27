#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

void InsertionSort(int a[], int n) {
    int pos, x;
    for (int i = 1; i < n; i++) {
        x = a[i];
        pos = i;
        while (pos > 0 && a[pos - 1] > x) {
            a[pos] = a[pos - 1];
            --pos;
        }
        a[pos] = x;
    }
}

int main() {
    int a[] = {1, 5, 4, 3, 2, 7, 8, 9}; 
    InsertionSort(a, 8);
    for (int i = 0; i < 8; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}