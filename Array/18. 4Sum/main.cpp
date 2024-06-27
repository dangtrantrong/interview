#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    set<vector<int>> set;
    vector<vector<int>> output;
    for(int i = 0; i < n - 3; i++){
        for(int j = i + 1; j < n - 2; j++){
            int newTarget = target - nums[i] - nums[j];
            int low = j + 1, high = n - 1;
            while(low < high){
                if(nums[low] + nums[high] < newTarget){
                    low++;
                }
                else if(nums[low] + nums[high] > newTarget){
                    high--;
                }
                else{
                    set.insert({nums[i], nums[j], nums[low], nums[high]});
                    low++; high--;
                }
            }
        }
    }

    for(auto it : set){
        output.push_back(it);
    }
    return output;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> output = fourSum(nums, target);
    for(auto it : output){
        cout << it[0] << " " << it[1] << " " << it[2] << " " << it[3] << endl;
    }
    return 0;
}