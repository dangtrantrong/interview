#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

int intersection(int arr1[], int m, int arr2[], int n) {
    int i = 0, j = 0;
    sort(arr1, arr1 + m);
    sort(arr2, arr2 + n);
    int count = 0;

    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            i++;
            j++;
            ++count;
        }
    }

    return count;
}

int main() {
    int arr1[] = {89, 24, 75, 11, 23};
    int arr2[] = {89, 2, 4};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    cout << intersection(arr1, m, arr2, n) << endl;
    return 0;
}