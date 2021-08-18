// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

bool solve(int n) {
  vector<int> count(10, 0);
  string s = to_string(n);
  for (char c : s) {
    count[c - '0']++;
    if (count[c - '0'] > 1 || c - '0' == 0) {
      return 0;
    }
  }
  vector<int> vis(s.size());
  int first = s[0] - '0', cur, i = 0;
  cur = first;
  while (1) {
    vis[i]++;
    if (vis[i] > 1) break;
    for (int j = 0; j < cur; j++) {
      i++;
      if (i == s.size()) {
        i = 0;
      }
    }
    cur = s[i] - '0';
  }
  for (int i = 1; i < s.size(); i++) {
    if (vis[i] != 1) {
      return 0;
    }
  }
  return vis[0] == 2;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, cs = 1;
  while (cin >> n && n) {
    for (int i = n; ; i++) {
      if (solve(i)) {
        cout << "Case " << cs++ << ": " << i << "\n";
        break;
      }
    }
  }
  return 0;
}