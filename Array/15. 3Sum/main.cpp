#include <iostream>
#include <memory>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <climits>

using namespace std;

/*Leetcode 15 - 3Sum*/
vector<vector<int>> threeSum(vector<int> nums) {
	int n = nums.size();
	sort(nums.begin(), nums.end());
	set<vector<int>> numberSet;	
	vector<vector<int>> output;
	for (int i = 0; i < n - 2; i++)
	{
		int low = i + 1;
		int high = n - 1;
		int sum = 0;
		while (low < high)
		{
			sum = nums[i] +  nums[low] + nums[high];
			if (sum > 0) {
				--high;
			} else if (sum < 0) {
				++low;
			} else {
				numberSet.insert({nums[i], nums[low], nums[high]});
				++low;
				--high;
			}
		}
	}

	for (auto it : numberSet)
	{
		output.push_back(it);
	}
	
	return output;
}