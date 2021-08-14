// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, value, ava;
  cin >> n;
  while (n--) {
    cin >> value >> ava;
    vector<int> cash(ava);
    vector<int> dp(16000, INF);
    for (int &i : cash) {
      cin >> i;
    }
    dp[0] = 0;
    for (int i : cash) {
      for (int j = 16000; j >= 0; j--) {
        if (j + i < 16000) {
          dp[j + i] = min(dp[j + i], 1 + dp[j]);
        }
      }
    }
    for (int i = value; i < 16000; i++) {
      if (dp[i] != INF) {
        cout << i << " " << dp[i] << "\n";
        break;
      }
    }
  }
  return 0;
}