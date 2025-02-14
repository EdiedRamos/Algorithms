//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, q, w, r;
    cin >> t;
    while (t--) {
        cin >> n;
        int dp[n][31];
        vector<pair<int,int>> ob(n);
        for (auto &i : ob) {
            cin >> i.first >> i.second;
        }
        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i < 31; i++) {
            dp[0][i] = ob[0].second <= i ? ob[0].first : 0;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < 31; j++) {
                dp[i][j] = ob[i].second <= j ? max(dp[i-1][j], ob[i].first + dp[i-1][j-ob[i].second]) : dp[i-1][j];
            }
        }
        r = 0;
        cin >> q;
        while (q--) {
            cin >> w;
            r += dp[n-1][w];
        }
        cout << r << "\n";
    }
    return 0;
}
