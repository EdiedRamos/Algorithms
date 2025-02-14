// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, a, b;
  string s;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    cin >> a >> b;
    unordered_set<string> ans;
    vector<string> va(a), vb(b);
    cin.ignore();
    for (string &i : va) {
      getline(cin, i);
    }
    for (string &i : vb) {
      getline(cin, i);
    }
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        ans.insert(va[i] + vb[j]);
      }
    }
    cout << "Case " << it << ": " << ans.size() << "\n";
  }
  return 0;
}