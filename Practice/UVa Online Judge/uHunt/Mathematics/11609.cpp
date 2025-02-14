// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;

ll modpow(ll a, ll b) {
  a %= MOD;
  int r = 1;
  while (b) {
    if (b & 1) {
      r = r * a % MOD;
    }
    a = a * a % MOD;
    b >>= 1;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  ll n;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> n;
    n = (n % MOD * modpow(2, n - 1)) % MOD;
    cout << "Case #" << i << ": " << n << "\n";
  }
  return 0;
}