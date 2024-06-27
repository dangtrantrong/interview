#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

int longestMountain(vector<int>& nums) {
    int longest = 0;
    
    for (int i = 1, up = 0, down = 0; i < nums.size(); i++)
    {
        if (down && nums[i - 1] < nums[i] || nums[i - 1] == nums[i]) {
            up = 0;
            down = 0;
        }

        up += nums[i - 1] < nums[i];
        down += nums[i - 1] > nums[i];

        if (up && down) {
            longest = max(longest, up + down + 1);
        }
    }
    return longest;
}

int main() {
    vector<int> nums = {2, 1, 4, 7, 3, 2, 5};
    cout << longestMountain(nums) << endl;
    return 0;
}