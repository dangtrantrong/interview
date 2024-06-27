#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

void mergeSortedArraysWithSpace(int arr1[], int arr2[], int arr3[], int n1, int n2) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }
    while (i < n1) {
        arr3[k++] = arr1[i++];
    }
    while (j < n2) {
        arr3[k++] = arr2[j++];
    }
}

void mergeSortedArraysWithoutSpace(int arr1[], int arr2[], int n1, int n2) {
    for (int i = n2 - 1; i >= 0; i--)
    {
        int j, last = arr1[n1 - 1];
        for (j = n1 - 2; j >= 0 && arr1[j] > arr2[i]; j--)
        {
            arr1[j + 1] = arr1[j];
        }

        if (last > arr2[i]) {
            arr1[j + 1] = arr2[i];
            arr2[i] = last;
        }
    }
}

void mergeSortedArraysWithoutSpaceWayOther(int arr1[], int arr2[], int n1, int n2) {
    int i = 0, j = 0, k = n1 - 1;
    while (i < k && j < n2) {
        if (arr1[i] <= arr2[j]) {
            i++;
        } else {
            swap(arr1[k--], arr2[j++]);
        }
    }

    // Sort first array
    sort(arr1, arr1 + n1);
 
    // Sort second array
    sort(arr2, arr2 + n2);

}

int main() {
    int n1 = 5, n2 = 4;
    
    int arr1[] = {5,6, 7, 8, 9}, 
        arr2[] = {1,2,3, 4};
    
    mergeSortedArraysWithoutSpaceWayOther(arr1, arr2, n1, n2);
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}