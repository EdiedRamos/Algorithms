// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define MN 1000005

int no_prime[MN];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  no_prime[1] = no_prime[0] = 1;
  for (int i = 2; i < MN; i++) {
    if (!no_prime[i]) {
      for (int j = i + i; j < MN; j += i) {
        no_prime[j] = 1;
      }
    }
  }
  int t, l, u, last, _max, _cnt, _ans;
  bool start;
  cin >> t;
  while (t--) {
    cin >> l >> u;
    map<int, int> cnt;
    start = 0;
    for (int i = l; i <= u; i++) {
      if (!no_prime[i]) {
        if (start) {
          cnt[i - last]++;
        } else {
          start = 1;
        }
        last = i;
      }
    }
    _max = 0;
    for (auto i : cnt) {
      if (i.second > _max) {
        _max = i.second;
        _ans = i.first;
        _cnt = 1;
      } else if (i.second == _max) {
        _cnt++;
      }
    }
    if (_cnt > 1 || !_max) {
      cout << "No jumping champion\n";
    } else {
      cout << "The jumping champion is " << _ans << "\n";
    }
  }
  return 0;
}