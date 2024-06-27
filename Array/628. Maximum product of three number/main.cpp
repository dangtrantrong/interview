#include <iostream>
#include <memory>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <climits>

using namespace std;

/*Leetcode 628 - Maximum product of three number*/
int maximumProduct(vector<int> nums) {
	// find out the min1 , min2, max1, max2, max3
	int min1 = INT_MAX;
	int min2= min1;
	
	int max1 = INT_MIN;
	int max2 = max1; 
	int max3 = max1;
	for(int i = 0; i < nums.size(); i++){
		
		int val = nums[i];
		// check for maximum 
		if(val >= max1){
			max3 = max2; 
			max2 = max1;
			max1 = val;
		}
		else if( val >= max2){ // there is a possibilty where val can be smaller than max1 and greater than or equal to max2 
			max3 = max2;
			max2 = val;
		}
		else if(val >= max3){ // there is a possibilty that the val can be smaller than max1 & max2 but greater than or equal to max3
			max3 = val;
		}
		
		// check for minimum 
		if(val <= min1){
			min2 = min1;
			min1 = val;
		}else if(val <= min2) {
			min2 = val;

		}
		cout << "max1: " << max1 << "\n";
		cout << "max2: " << max2 << "\n";
		cout << "max3: " << max3 << "\n";
		cout << "min1: " << min1 << "\n";
		cout << "min2: " << min2 << "\n";
		cout << "--------------------------\n";
	}

	int max_product = max((min1 * min2 * max1),(max1 * max2 * max3));
	
	return max_product;
}