// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define MN 35

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int dp[MN][1005], depth[MN], gold[MN], cost[MN];
  int t, w, n, it, jt, aux;
  bool sp = 0;
  stack<int> pos;
  while (cin >> t >> w) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> depth[i] >> gold[i];
      cost[i] = 3 * w * depth[i]; // (w * d[i]) + (2 * w * d[i]) = 3 * w * d[i]
    }
    for (int i = 0; i < n; i++) {
      dp[i][0] = 0;
    }
    for (int i = 0; i < t + 1; i++) {
      dp[0][i] = i < cost[0] ? 0 : gold[0];
    }
    for (int i = 1; i < n; i++) {
      for (int j = 1; j <= t; j++) {
        dp[i][j] = j < cost[i] ? dp[i - 1][j] : max(dp[i - 1][j], dp[i - 1][j - cost[i]] + gold[i]);
      }
    }
    if (sp) {
      cout << "\n";
    }
    sp = 1;
    aux = dp[n - 1][t];
    cout << aux << "\n";
    it = n - 1;
    jt = t;
    while (it) {
      if (dp[it][jt] != dp[it - 1][jt]) {
        pos.push(it);
        jt -= cost[it];
        aux -= gold[it];
      }
      it--;
    }
    if (aux == dp[0][jt] && aux) {
      pos.push(0);
    }
    cout << pos.size() << "\n";
    while (!pos.empty()) {
      it = pos.top();
      cout << depth[it] << " " << gold[it] << "\n";
      pos.pop();
    }
  }
  return 0;
}