#include <iostream>
#include <memory>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <climits>

using namespace std;

/*Leetcode - 268. Missing number*/
int missingNumber(vector<int> nums) {
	int sum = nums.size();
	for (int i = 0; i < nums.size(); i++)
	{
		sum += i - nums[i];
	}
	return sum;
}

int missingNumberXORSolution(vector<int> nums) {
	int sum = nums.size();
	for (int i = 0; i < nums.size(); i++)
	{
		sum ^= i ^ nums[i];
		cout << "sum: " << sum << "\n";
	}
	return sum;
}