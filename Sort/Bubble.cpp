#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

void BubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                std::swap(a[j], a[j - 1]);
            }
        }
    }
}

int main() {
    int a[] = {1, 5, 4, 3, 2, 7, 8, 9}; 
    BubbleSort(a, 8);
    for (int i = 0; i < 8; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}