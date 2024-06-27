#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

// Function to rotate the array
void rotateArray(int arr[], int n, int k) {
    if (k == 0) {
        return;
    }

    // rotate the array to the right by one position
    int temp = arr[n - 1];
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;

    // recursively rotate the remaining elements k-1 times
    rotateArray(arr, n, k - 1);
}

void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

// Driver code
int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    vector<int> arrList = {1, 3, 5, 7, 9};

    // rotateArray(arr, n, k);
    rotate(arrList, k);

    for (int i = 0; i < n; i++) {
        std::cout << arrList[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

