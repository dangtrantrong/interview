#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

void sort012(int arr[], int n) {
    int low = 0, mid = 0, high = n -1;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 2) {
            swap(arr[mid], arr[high]);
            high--;
        } else {
            mid++;
        }
    }
}

int main() {
    int arr[] = {0, 1, 2, 0, 2, 1};
    sort012(arr, 6);
    for (size_t i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}