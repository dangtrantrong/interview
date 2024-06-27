#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

void swaps(vector<long long>& arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Function to reverse every sub-array group of size k.
void reverseInGroups(vector<long long>& arr, int n, int k) {
    // code here
    for (int start = 0; start < n; start += k) {
        int end = min(start + k - 1, n - 1);
        swaps(arr, start, end);
    }
}

int main() {
    vector<long long> arr = {1,2,3,4,5, 6};
    reverseInGroups(arr, 6, 3);
    for (int arr_i = 0; arr_i < 6; arr_i++) {
        cout << arr[arr_i] << " ";
    }
    cout << endl;
    return 0;
}