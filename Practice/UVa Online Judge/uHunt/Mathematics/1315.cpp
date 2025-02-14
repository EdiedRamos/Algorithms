#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MN 32770

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n;
  int dp[MN];
  dp[1] = dp[2] = 0;
  for (int i = 3; i < MN; i++) {
    dp[i] = dp[i - 1] + ((i - 1) >> 1);
  }
  cin >> t;
  while (t--) {
    cin >> n; 
    cout << dp[n] << endl;
  }
  return 0;
}
