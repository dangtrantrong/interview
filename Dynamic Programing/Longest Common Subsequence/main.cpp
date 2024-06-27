#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int longestCommonSubsequence (string S1, string S2, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(S1[i - 1] == S2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    return dp[n][m];
}

int main() {
    string S1 = "abcdxyz";
    string S2 = "xyzabcd";
    int n = S1.length();
    int m = S2.length();
    cout << longestCommonSubsequence(S1, S2, n, m) << endl;
    return 0;
}