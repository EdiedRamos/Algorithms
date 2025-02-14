// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll _reverse(ll a) {
  ll r = 0;
  while (a) {
    r = r * 10 + a % 10;
    a /= 10;
  }
  return r;
}

bool pal(ll a) {
  stack<int> si;
  ll b = a;
  while (b) {
    si.push(b % 10);
    b /= 10;
  }
  while (a) {
    if (a % 10 != si.top()) {
      return 0;
    }
    si.pop();
    a /= 10;
  }
  return 1;
}

void solve(ll n) {
  int it = 1;
  n += _reverse(n);
  while (!pal(n)) {
    n += _reverse(n);
    it++;
  }
  cout << it << " " << n << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  ll n;
  cin >> t;
  while (t--) {
    cin >> n;
    solve(n);
  }
  return 0;
}
