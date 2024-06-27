#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;


// Using sliding window
vector<int> subarraySum(vector<int>arr, int n, long long s)
{
    int start = 0, sum = 0;
    vector<int> ouput;
    for (size_t i = 0; i < n; i++)
    {
        sum += arr[i];
        while (sum > s)
        {
            sum -= arr[start];
            ++start;
        }

        if (sum == s) {
            for ( int j = start; j <= i; j++) {
                ouput.push_back(arr[j]);
            }
            return ouput;
        }
    }
    return ouput;
}

// Using Dynamic Programming
std::vector<int> find_subarray_with_given_sum(const std::vector<int>& arr, int sum)
{
    std::unordered_map<int, int> map;
    int curr_sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        curr_sum += arr[i];
        if (curr_sum == sum) {
            return std::vector<int>({0, i});
        }
        if (map.count(curr_sum - sum)) {
            return std::vector<int>({map[curr_sum - sum] + 1, i});
        }
        map[curr_sum] = i;
    }
    return {};
}

int main() {
    vector<int> arr = {1, 2, 4, 7, 8};
    vector<int> ouput = subarraySum(arr, 5, 20);
    for (size_t i = 0; i < ouput.size(); i++)
    {
        cout << ouput[i] << " ";
    }
    cout << endl;
    return 0;
}