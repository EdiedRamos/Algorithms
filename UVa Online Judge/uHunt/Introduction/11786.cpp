// coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, r;
  string s;
  cin >> t;
  while (t--) {
    cin >> s;
    r = 0;
    stack<int> si;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '\\') {
        si.push(i);
      } else if (s[i] == '/' && !si.empty()) {
        r += i - si.top();
        si.pop();
      }
    }
    cout << r << "\n";
  }
  return 0;
}
