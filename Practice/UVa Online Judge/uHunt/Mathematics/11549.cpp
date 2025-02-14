// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll n, int k) {
  string aux;
  ll _m = n;
  for (int i = 0; i < 54000; i++) {
    n *= n;
    aux = to_string(n);
    n = 0;
    for (int j = 0; j < k && j < aux.size(); j++) {
      n = n * 10 + (aux[j] - '0');
    }
    _m = max(_m, n);
  }
  return _m;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  int k, t;
  cin >> t;
  while (t--) {
    cin >> k >> n;
    cout << solve(n, k) << "\n";
  }
  return 0;
}