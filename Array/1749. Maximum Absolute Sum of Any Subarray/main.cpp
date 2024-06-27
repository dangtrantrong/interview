#include <iostream>
#include <memory>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <climits>

using namespace std;

int maxSubArray(vector<int> nums) {
	int max_sum_end_i = 0;
	int max_so_far = 0;
	for (int i = 0; i < nums.size(); i++) {
		max_sum_end_i = max(nums[i], max_sum_end_i + nums[i]);
		max_so_far = (i == 0) ? max_sum_end_i : max(max_so_far, max_sum_end_i);
		cout << "max_sum_end_i: " << max_sum_end_i << "\n";
		cout << "max_so_far: " << max_so_far << "\n";
		cout << "-----------------------\n";
	}

	return max_so_far;
}

int minSubArray(vector<int> nums) {
	int min_sum_end_i = 0;
	int min_so_far = 0;
	for (int i = 0; i < nums.size(); i++) {
		min_sum_end_i = min(nums[i], min_sum_end_i + nums[i]);
		min_so_far = (i == 0) ? min_sum_end_i : min(min_so_far, min_sum_end_i);
		cout << "min_sum_end_i: " << min_sum_end_i << "\n";
		cout << "min_so_far: " << min_so_far << "\n";
		cout << "-----------------------\n";
	}

	return min_so_far;
}

/*Leetcode 1749 - Maximum Absolute Sum of Any Subarray*/
int maxAbsoluteSum1(vector<int> nums) {
	return max(abs(maxSubArray(nums)), abs(minSubArray(nums)));
}

int maxAbsoluteSum(vector<int> nums) {
	int sum = 0, minPrefixSum = 0, maxPrefixSum = 0;
	for (auto &it : nums)
	{
		sum += it;
		minPrefixSum = min(minPrefixSum, sum);
		maxPrefixSum = max(maxPrefixSum, sum);
		cout << "minPrefixSum: " << minPrefixSum << "\n";
		cout << "maxPrefixSum: " << maxPrefixSum << "\n";
	}
	return maxPrefixSum - minPrefixSum;
}