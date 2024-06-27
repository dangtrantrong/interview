#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0) {
            result.push_back(index + 1);
        }
        nums[index] = -nums[index];
    }
    return result;
}

int main() {
    vector<int> input = {4,3,2,7,8,2,3,1};
    vector<int> result = findDuplicates(input);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}