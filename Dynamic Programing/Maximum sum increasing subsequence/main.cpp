#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int maxSumIS(int arr[], int n)  
{  
    int maxSum = 0;
    int dp[n];  
    for (int i = 0; i < n; i++)  
        dp[i] = arr[i];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i]) {
                dp[i] = dp[j] + arr[i];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
        if (maxSum < dp[i])
            maxSum = dp[i];
    }
    cout << endl;
    return maxSum;
} 

int main() {
    int arr[] = {5, 3, 2, 4, 7, 9, 8, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << maxSumIS(arr, n) << endl;
    return 0;
}
