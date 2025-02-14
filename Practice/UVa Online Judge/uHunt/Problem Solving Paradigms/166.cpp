// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
  // ios::sync_with_stdio(0);
  // cin.tie(0);
  string total;
  int n_total, rta;
  vector<int> ava(6);
  int coins[] = {5, 10, 20, 50, 100, 200};
  vector<int> dp_base(1000, INF);
  dp_base[0] = 0;
  for (int i : coins) {
    for (int j = 1; j < 1000; j++) {
      if (j - i >= 0) {
        dp_base[j] = min(dp_base[j], 1 + dp_base[j - i]);
      }
    }
  }
  bool zero;
  while (1) {
    vector<int> all_coins;
    vector<int> dp(1000, INF);
    dp[0] = 0;
    zero = 1;
    for (int &i : ava) {
      cin >> i;
      zero &= !i;
    }
    if (zero) {
      break;
    }
    cin >> total;
    n_total = 0;
    for (char c : total) {
      if (c != '.') {
        n_total = n_total * 10 + (c - '0');
      }
    }
    for (int i = 0; i < 6; i++) {
      while (ava[i]--) {
        all_coins.emplace_back(coins[i]);
      }
    }
    for (int i : all_coins) {
      for (int j = 1000; j >= 0; j--) {
        if (j + i < 1000) {
          dp[j + i] = min(dp[j + i], 1 + dp[j]);
        }
      }
    }
    rta = INF;
    for (int i = n_total; i < 1000; i++) {
      if (dp[i] != INF) {
        rta = min(rta, dp[i] + dp_base[i - n_total]);
      }
    }
    printf("%3d\n", rta);
  }
  return 0;
}