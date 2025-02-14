// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n, r;
  ll sum;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<ll> coins(n);
    for (ll &i : coins) {
      cin >> i;
    }
    r = 1;
    sum = 0;
    for (int i = 0; i < n - 1; i++) {
      if (sum + coins[i] < coins[i + 1]) {
        sum += coins[i];
        r++;
      }
    }
    cout << r << "\n";
  }
  return 0;
}