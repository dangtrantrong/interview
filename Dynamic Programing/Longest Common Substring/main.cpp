#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int longestCommonSubstr (string S1, string S2, int n, int m)
{
    int result = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(S1[i - 1] == S2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > result) {
                    result = dp[i][j];
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return result;
}

int main() {
    string S1 = "abcdxyz";
    string S2 = "xyzabcd";
    int n = S1.length();
    int m = S2.length();
    cout << longestCommonSubstr(S1, S2, n, m) << endl;
    return 0;
}