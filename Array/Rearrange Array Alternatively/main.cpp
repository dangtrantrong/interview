#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

void rearrange(int arr[], int n) { 
    int k = 0;
    while (k < n )
    {
        int last = arr[n -1];
        cout << "last: " << last << endl;
        for (int i = n - 1; i > k; i--) {
            arr[i] = arr[i - 1];
        }
        arr[k] = last;
        k += 2;
    }
}

void rearrangeWayOther(int *arr, int n) {
    // Your code here
    int maxIdx = n - 1;
    int minIdx = 0;
    int maxElem = arr[n - 1] + 1; // Set maxElem to a value greater than the maximum element in the array

    for (int i = 0; i < n; i++) {
        // At even index, we store the maximum elements
        if (i % 2 == 0) {
            arr[i] += (arr[maxIdx] % maxElem) * maxElem;
            maxIdx--;
        }
        // At odd index, we store the minimum elements
        else {
            arr[i] += (arr[minIdx] % maxElem) * maxElem;
            minIdx++;
        }
    }

    // Dividing each element by maxElem to get the original value at that position
    for (int i = 0; i < n; i++) {
        arr[i] /= maxElem;
    }
}


int main() {
    int arr[] = {10,20,30,40,50,60,70,80,90,100,110};
    rearrangeWayOther(arr, 11);
    for (int i = 0; i < 11; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}