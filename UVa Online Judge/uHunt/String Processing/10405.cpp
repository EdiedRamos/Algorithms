//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
    int r;
    while (getline(cin, a) && getline(cin, b)) {
        vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));
        for (int i = 1; i <= a.size(); i++) {
            for (int j = 1; j <= b.size(); j++) {
                if (a[i-1] == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        cout << dp[a.size()][b.size()] << "\n";
    }
	return 0;
}
