// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, _max, test = 1;
  vector<int> d, dp;
  while (cin >> n && n != -1) {
    d.clear();
    d.push_back(n);
    while (cin >> n && n != -1) {
      d.push_back(n);
    }
    dp.clear();
    dp.resize(d.size(), 1);
    _max = 1;
    for (int i = d.size() - 2; i >= 0; i--) {
      for (int j = d.size() - 1; j > i; j--) {
        if (d[j] <= d[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
          _max = max(_max, dp[i]);
        }
      }
    }
    if (test > 1) {
      cout << "\n";
    }
    cout << "Test #" << test++ << ":\n  maximum possible interceptions: " <<_max << "\n";
  }
  return 0;
}