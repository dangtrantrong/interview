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
	int max_so_far = INT_MIN;
	for (int i = 0; i < nums.size(); i++) {
		max_sum_end_i = max(nums[i], max_sum_end_i + nums[i]);
		max_so_far = max(max_so_far, max_sum_end_i);
		cout << "max_sum_end_i: " << max_sum_end_i << "\n";
		cout << "max_so_far: " << max_so_far << "\n";
		cout << "-----------------------\n";
	}

	return max_so_far;
}

void maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0,
        start = 0, end = 0, s = 0;

    for (int i = 0; i < size; i++) {
        max_ending_here += a[i];

        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0) {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    cout << "Maximum contiguous sum is " << max_so_far
         << endl;
    cout << "Starting index " << start << endl
         << "Ending index " << end << endl;
}


int minSubArray(vector<int> nums) {
	int min_sum_end_i = 0;
	int min_so_far = INT_MAX;
	for (int i = 0; i < nums.size(); i++) {
		min_sum_end_i = min(nums[i], min_sum_end_i + nums[i]);
		min_so_far = min(min_so_far, min_sum_end_i);
		cout << "min_sum_end_i: " << min_sum_end_i << "\n";
		cout << "min_so_far: " << min_so_far << "\n";
		cout << "-----------------------\n";
	}

	return min_so_far;
}