#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

void merge(int arr[], int l, int m, int r) {
    int i = l; // starting index for left subarray
    int j = m + 1; // starting index for right subarray
    int k = l; // starting index for temporary

    int temp[5];
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= m) {
        temp[k++] = arr[i++]; // copying all elements from left subarray to temp as it is
    }

    while (j <= r) {
        temp[k++] = arr[j++]; // copying all elements from right subarray to temp as it is
    }

    for (int i = l; i <= r; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = (r + l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}


int main() {
    int arr[5] = {4, 6, 1, 2, 7};

    // merge sort function
    mergeSort(arr, 0, 4);

    // print the sorted array
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}