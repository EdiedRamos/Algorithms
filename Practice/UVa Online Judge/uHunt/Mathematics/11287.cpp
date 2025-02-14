// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool prime(ll n) {
  if (!(n & 1)) {
    return 0;
  }
  for (ll i = 3; i * i <= n; i += 2) {
    if (n % i < 1) {
      return 0;
    }
  }
  return 1;
}

ll binpow(ll a, ll b, ll mod) {
  a %= mod;
  ll r = 1;
  while (b > 0) {
    if (b & 1) {
      r = r * a % mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll a, p, m;
  while (cin >> p >> a && p || a) {
    if (prime(p)) {
      cout << "no\n";
    } else {
      m = binpow(a, p, p);
      cout << (m == a ? "yes" : "no") << "\n";
    }
  }
  return 0;
}