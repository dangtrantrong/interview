#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int longestCommonSubstr(int a[], int n)
{
    int result = 0;
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        result = max(result, dp[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;

    return result;
}

std::vector<int> longestIncreasingNotConsecutiveSubarray(std::vector<int> input) {
    std::vector<int> lengths(input.size(), 1);
    std::vector<int> output;
    for (int i = 0; i < input.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (input[i] > input[j] && lengths[j] + 1 > lengths[i]) {
                lengths[i] = lengths[j] + 1;
            }
        }
    }

    int maxLength = *std::max_element(lengths.begin(), lengths.end());
    for (int i = lengths.size() - 1; i >= 0; --i) {
        if (lengths[i] == maxLength) {
            output.push_back(input[i]);
            --maxLength;
        }
    }
    
    std::reverse(output.begin(), output.end());

    for (int i = 0; i < lengths.size(); i++) {
        std::cout << lengths[i] << " ";
    }
    std::cout << std::endl;
    return output;
}

vector<int> longestIncreasingConsecutiveSubarray(vector<int> nums) {
    vector<int> result;
    vector<int> lengths(nums.size(), 1); // khởi tạo các phần tử đều có độ dài là 1

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1]) {
            lengths[i] = lengths[i - 1] + 1;
        }
    }

    for (int i = 0; i < lengths.size(); i++) {
        cout << lengths[i] << " ";
    }
    cout << "\n";

    int maxLength = *max_element(lengths.begin(), lengths.end()); // tìm độ dài lớn nhất
    int endIndex = find(lengths.begin(), lengths.end(), maxLength) - lengths.begin(); // tìm chỉ số của phần tử cuối cùng có độ dài lớn nhất 

    cout << "maxLength: " << maxLength << "\n";
    cout << "enIndex: " << endIndex << "\n";
    for (int i = endIndex - maxLength + 1; i <= endIndex; i++) {
        result.push_back(nums[i]);
    }

    return result;
}

int main() {
    int input[] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    int n = sizeof(input) / sizeof(input[0]);
    cout << longestCommonSubstr(input, n) << endl;
    return 0;
}