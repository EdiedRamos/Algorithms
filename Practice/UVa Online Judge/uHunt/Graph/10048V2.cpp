/*
  █   █ █▀▀▀ █▀▀▀█ █  █ █▀▀█ █   █ █▀▀█ █  █
  █▄▄▄█ █▀▀▀ ▀▀▀▄▄ █▀▀█ █▄▄█ █▄▄▄█ █▄▄█ █▀▀█
    █   █▄▄▄ █▄▄▄█ █  █ █  █   █   █  █ █  █
*/
#include <bits/stdc++.h>
using namespace std;

#define MN 105

struct edge {int a, b, w;};

bool cmp(edge a, edge b) {return a.w < b.w;}

vector<edge> ledge;
int _dsu[MN], _rank[MN], c, s, q, a, b, kr, tc = 1;

int find(int v) {return _dsu[v] = _dsu[v] == v ? v : find(_dsu[v]);}

int kruskall(int s, int e) {
  for (int i = 1; i <= c; i++) {
    _dsu[i] = i;
  }
  fill(_rank, _rank + c, 1);
  int a, b;
  for (edge i : ledge) {
    a = find(i.a);
    b = find(i.b);
    if (a != b) {
      if (_rank[a] < _rank[b]) swap(a, b);
      _dsu[b] = a;
      _rank[a] += _rank[b];
      if (find(s) == find(e)) {
        return i.w;
      }
    }
  }
  return -1; // not path found
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  edge ed;
  while (cin >> c >> s >> q && c || c || q) {
    ledge.clear();
    while (s--) {
      cin >> ed.a >> ed.b >> ed.w;
      ledge.push_back(ed);
    }
    if (tc > 1) cout << "\n";
    cout << "Case #" << tc++ << "\n";
    sort(ledge.begin(), ledge.end(), cmp);
    while (q--) {
      cin >> a >> b;
      kr = kruskall(a, b);
      if (kr == -1) {
        cout << "no path\n";
      } else {
        cout << kr << "\n";
      }
    }
  }
  return 0;
}
