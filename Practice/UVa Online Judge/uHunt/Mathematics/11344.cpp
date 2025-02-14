// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, q, mods[13];
  string n;
  bool sol;
  cin >> t;
  while (t--) {
    cin >> n >> q;
    vector<int> mod(q);
    memset(mods, 0, sizeof mods);
    for (int &i : mod) cin >> i;
    for (char c : n) {
      for (int i : mod) {
        mods[i] = (mods[i] * 10 + (c - '0')) % i;
      }
    }
    sol = 1;
    for (int i : mod) {
      if (mods[i]) {
        sol = 0;
        break;
      }
    }
    cout << n << " - " << (sol ? "Wonderful" : "Simple") << ".\n";
  }
  return 0;
}