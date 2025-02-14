// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll dp[10005];
  memset(dp, 0, sizeof dp);
  dp[0] = 1;
  for (int i = 1; i < 22; i++) {
    for (int j = 1; j < 10003; j++) {
      if (j - (i * i * i) >= 0) {
        dp[j] += dp[j - (i * i * i)];
      }
    }
  }
  int value;
  while (cin >> value) {
    cout << dp[value] << "\n";
  }
  return 0;
}