#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

bool isTriplet(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] * arr[i];
    }
    
    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    for (int i = n - 1; i >= 2; i--) {
        int pointLeft = 0;
        int pointRight = i - 1;
        while (pointLeft < pointRight)
        {
            if (arr[pointLeft] + arr[pointRight] == arr[i]) {
                return true;
            }

            (arr[pointLeft] + arr[pointRight]) > arr[i] ? --pointRight : ++pointLeft;
        }
    }
    
    return false;
}

int main()
{
    int arr[] = { 3, 1, 4, 6, 5 };
    int arr_size = 5;
    isTriplet(arr, arr_size) ? cout << "\nYes" : cout << "\nNo";
    return 0;
}