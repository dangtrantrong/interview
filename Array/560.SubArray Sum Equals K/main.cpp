#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>

using namespace std;
/* Using technical sliding windown*/
int subarraySum1(vector<int>& nums, int k) {
    int start = 0;
    int end = start;
    int count = 0;   
    int sum = nums[0];     
    
    while (start < nums.size()) {

        if (start > end) {
            end = start;
            sum = nums[start];
        }

        if (sum < k)
        {
            ++end;
            if (end == nums.size()) {
                break;
            }
            sum += nums[end];
        } else if (sum > k) {
            sum -= nums[start];
            ++start;
        } else {
            ++count;
            sum -= nums[start];
            ++start;
        }
        cout << "sum: " << sum << endl;
    }

    return count;
}

int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mapNumber;
        int sum = 0, count = 0;
        //mapNumber[sum] = 1;
        for(auto it:nums) {
            sum += it;
            if (sum == k)
                ++count;
            
            int find = sum - k;
            if(mapNumber.find(find) != mapNumber.end()){
                count += mapNumber[find];
            }
            mapNumber[sum]++;
        }
        return count;
}

int main() {
    vector<int> nums = {-1,-1,1};
    int k = 0;
    cout << subarraySum(nums, k) << endl;
    return 0;
}