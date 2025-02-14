// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n, r;
  string p;
  cin >> t;
  while (t--) {
    cin >> n >> p;
    r = 0;
    for (int i = 0; i < p.size(); i++) {
      r = r * 10 + (p[i] - '0');
      r %= n;
    }
    cout << r << "\n";
  }
  return 0;
}