#include <iostream>
#include <memory>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <climits>

using namespace std;

/*Leetcode - 152. Maximum Product Subarray*/
int maxProduct(vector<int> nums) {
	int n = nums.size(); 
	int prefix = 1;
	int suffix = 1;
	int maxProduct = INT_MIN;
	for(int i = 0; i < n; ++i) {
		if(prefix == 0) 
			prefix = 1; 
		if(suffix == 0) 
			suffix = 1;
		prefix *= nums[i];
		suffix *= nums[n - 1 - i];
		maxProduct = max(maxProduct ,max(prefix,suffix)); 
	}
	return maxProduct;
}

int main()
{
    vector<int> arr = { 1, -2, -3, 0, 7, -8, -2 };
    cout << "Maximum Sub array product is "
         << maxProduct(arr);
    return 0;
}