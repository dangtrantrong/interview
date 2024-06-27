#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
// #include <bits/stdc++.h>


using namespace std;

int main() {

    int n, a[1005], dp[10] = {1}, res = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        // dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }

    for (int i = 0; i< 6; i++) {
        cout << dp[i] << " ";
    }

    cout << "\n" << res << endl;

    return 0;
}