// Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 60

int dsu[MN], _rank[MN];

int Find(int v) {
  return dsu[v] = dsu[v] == v ? v : Find(dsu[v]);
}

void Union(int a, int b) {
  a = Find(a);
  b = Find(b);
  if (a == b) return;
  if (_rank[a] < _rank[b]) swap(a, b);
  dsu[b] = a;
  _rank[a] += _rank[b];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, code, r;
  char n1, n2;
  while (cin >> n >> m) {
    code = r = 0;
    for (int i = 0; i < n; i++) {
      dsu[i] = i;
      _rank[i] = 1;
    }
    map<char, int> ci;
    while (m--) {
      cin >> n1 >> n2;
      if (ci.find(n1) == ci.end()) {
        ci[n1] = code++;
      }
      if (ci.find(n2) == ci.end()) {
        ci[n2] = code++;
      }
      if (Find(ci[n1]) == Find(ci[n2])) {
        r++;
      } else {
        Union(ci[n1], ci[n2]);
      }
    }
    cout << r + 1 << "\n";
  }
  return 0;
}
