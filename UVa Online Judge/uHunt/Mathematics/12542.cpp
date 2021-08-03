// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  bool check[100005];
  int res, cur;
  memset(check, 1, sizeof check);
  check[1] = 0;
  for (int i = 2; i < 100005; i++) {
    if (check[i]) {
      for (int j = i + i; j < 100005; j += i) {
        check[j] = 0;
      }
    }
  }
  while (cin >> s && s != "0") {
    res = 0;
    for (int i = 0; i < s.size(); i++) {
      for (int j = 1; j < 7 && i + j <= s.size(); j++) {
        cur = atoi(s.substr(i, j).c_str());
        if (cur > 100000) {
          continue;
        }
        if (check[cur]) {
          res = max(res, cur);
        }
      }
    }
    cout << res << "\n";
  }
  return 0;
}