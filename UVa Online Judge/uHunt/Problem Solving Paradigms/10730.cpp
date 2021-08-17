// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &v, vector<int> &p) {
  int next;
  for (int i = 0; i < v.size() - 2; i++) {
    for (int j = i + 1; j < v.size(); j++) {
      next = (v[j] << 1) - v[i];
      if (next >= 0 && next < v.size() && p[next] > j) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  string trash;
  while (cin >> n && n) {
    cin >> trash;
    vector<int> d(n), pos(n);
    for (int i = 0; i < n; i++) {
      cin >> d[i];
      pos[d[i]] = i;
    }
    cout << (solve(d, pos) ? "yes\n" : "no\n");
  }
  return 0;
}