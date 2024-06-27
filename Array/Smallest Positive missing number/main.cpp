#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>

using namespace std;

int firstMissingPositive(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int ans = 1;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == ans) {
            ans++;
        }
    }
    return ans;
}

int firstMissingPos(int A[], int n)
{
 
    // To mark the occurrence of elements
    bool present[n + 1] = { false };
 
    // Mark the occurrences
    for (int i = 0; i < n; i++) {
 
        // Only mark the required elements
        // All non-positive elements and the elements
        // greater n + 1 will never be the answer
        // For example, the array will be {1, 2, 3} in the
        // worst case and the result will be 4 which is n +
        // 1
        if (A[i] > 0 && A[i] <= n)
            present[A[i]] = true;
    }
 
    // Find the first element which didn't appear in the
    // original array
    for (int i = 1; i <= n; i++)
        if (!present[i])
            return i;
 
    // If the original array was of the type {1, 2, 3} in
    // its sorted form
    return n + 1;
}
 
// Driver code
int main()
{
    vector<int> arr = { 0, 10, 2, -10, -20 };
    // Function call
    cout << firstMissingPositive(arr);
    return 0;
}