#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        map<int,int> mymap;

        for(int i = 0;i < n ;i++){
            int curr = nums[i];
            std::cout << "mymap[curr]: " << mymap[curr] << std::endl;
            if(mymap[curr]){
                count += mymap[curr];
            }
            mymap[curr]++;
            std::cout << "nums[i]: " <<  nums[i] << ", count: " << count << std::endl;
        }

        for (auto x : mymap)
        {
            std::cout << "mymap element: \n";
            std::cout << "key: " << x.first << ", value: " << x.second << std::endl;
        }
        
        return count;
}

int main() {
    vector<int> nums = {1,2,3,4};
    cout << numIdenticalPairs(nums) << endl;
    return 0;
}