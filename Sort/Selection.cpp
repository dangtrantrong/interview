#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

void SelectionSort(int a[], int n) {
    int min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        swap(a[i], a[min]);
    }
}

int main() {
    int a[] = {1, 5, 4, 3, 2, 7, 8, 9}; 
    SelectionSort(a, 8);
    for (int i = 0; i < 8; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}