// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll dp[7500];
  int coins[] = {1, 5, 10, 25, 50};
  int n;
  memset(dp, 0, sizeof dp);
  dp[0] = 1;
  for (int i = 0; i < 5; i++) {
    for (int j = 1; j < 7500; j++) {
      if (j - coins[i] >= 0) {
        dp[j] += dp[j - coins[i]];
      }
    }
  }
  while (cin >> n) {
    cout << dp[n] << "\n";
  }
  return 0;
}