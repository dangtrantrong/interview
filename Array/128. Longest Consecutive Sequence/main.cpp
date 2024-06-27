#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <unordered_set>


using namespace std;

int longestConsecutive(vector<int> nums) {
    unordered_set<int> set;
    for (int i = 0; i < nums.size(); i++) {
        set.insert(nums[i]);
    }

    int longestConsecutiveSequence = 0;
    for(int num : nums) {
        if (set.find(num - 1) == set.end()) {
            int currentNumber = num;
            int currentSequence = 1;
            while (set.find(currentNumber + 1) != set.end()) {
                currentNumber++;
                currentSequence++;
            }
            longestConsecutiveSequence = max(longestConsecutiveSequence, currentSequence);
        }
    }

    return longestConsecutiveSequence;
}

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if(n == 0){
        return 0;
    }
    sort(nums.begin(), nums.end());
    int currentConsecutiveSequence = 1;
    int longestConsecutiveSequence = 0;
    for(int i=1; i<n; i++){
        if(nums[i] != nums[i-1]){
            if(nums[i] == nums[i-1] + 1){
                currentConsecutiveSequence++;
            }
            else{
                longestConsecutiveSequence = max(longestConsecutiveSequence, currentConsecutiveSequence);
                currentConsecutiveSequence = 1;
            }
        }
    }
    return max(longestConsecutiveSequence, currentConsecutiveSequence);
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums) << endl;
    return 0;
}