#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>


using namespace std;

int main() {
    string s;
    cout << "Nhap String: "; cin >> s;
    int n = s.size();
    s = "x" + s;
    // F[i][j] = F[i + 1][j - 1] && (s[i] == s[j])
    bool F[n +1][n +1];
    for (int i = 1; i <= n; i++) {
        F[i][i] = true; // xau con co do dai la 1
    }

    // Xet cac xau con co do dai tu 2 cho den n
    int ans = 1;
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            if (len == 2 && s[i] == s[j]) {
                F[i][j] = true;
            } else {
                F[i][j] = F[i + 1][j - 1] && (s[i] == s[j]);
            }

            if (F[i][j]) {
                ans = max(ans, len);
            }
        }
    }
    cout << "Xau con dai nhat: " << ans << endl;
}