#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>

using namespace std;
   
void findMinMax(int arr[], int n) {
    int i, max, min;
    if (n % 2 == 0) {
        if (arr[0] > arr[1]) {
            max = arr[0];
            min = arr[1];
        } else {
            max = arr[1];
            min = arr[0];
        }
        i = 2;
    } else {
        max = min = arr[0];
        i = 1;
    }

    while (i < n - 1) {
        if (arr[i] > arr[i + 1]) {
            if (arr[i] > max)
                max = arr[i];
            if (arr[i + 1] < min)
                min = arr[i + 1];
        } else {
            if (arr[i + 1] > max)
                max = arr[i + 1];
            if (arr[i] < min)
                min = arr[i];
        }
        i += 2;
    }
    cout << "min: " << min << "max: " << max << endl;
}

int main() {
    int n;
    cout << "Enter the size array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    findMinMax(arr, n);
}