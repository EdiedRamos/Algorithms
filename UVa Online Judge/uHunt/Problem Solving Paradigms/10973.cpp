// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc, n, m, a, b, ans;
  cin >> tc;
  while (tc--) {
    cin >> n >> m;
    ans = 0;
    map<int, set<int>> lad;
    for (int i = 0; i < m; i++) {
      cin >> a >> b;
      if (a > b) swap(a, b);
      lad[a].insert(b);
    }
    for (auto i : lad) {
      for (auto j : i.second) {
        for (auto k : lad[j]) {
          if (i.second.count(k)) {
            ans++;
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
