#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

int main() {
    int n, sum;
    cout << "n: "; cin >> n;
    cout << "sum: "; cin >> sum;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "]: "; cin >> a[i];
    }
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= a[i]; j--) {
            if (dp[j - a[i]] == true) {
                dp[j] = true;
            }
        }
    }

    cout << boolalpha << dp[sum] << endl;

}