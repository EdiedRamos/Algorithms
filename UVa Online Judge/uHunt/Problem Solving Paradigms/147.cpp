// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  // ios::sync_with_stdio(0);
  // cin.tie(0);
  ll dp[30005];
  string a;
  int value;
  int coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
  memset(dp, 0, sizeof dp);
  dp[0] = 1;
  for (int i = 0; i < 11; i++) {
    for (int j = 1; j < 30002; j++) {
      if (j - coins[i] >= 0) {
        dp[j] += dp[j - coins[i]];
      }
    }
  }
  while (cin >> a && a != "0.00") {
    printf("%6s", a.c_str());
    value = 0;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] != '.') {
        value = value * 10 + (a[i] - '0');
      }
    }
    printf("%17lld\n", dp[value]);
  }
  return 0;
}