/*
  █   █ █▀▀▀ █▀▀▀█ █  █ █▀▀█ █   █ █▀▀█ █  █
  █▄▄▄█ █▀▀▀ ▀▀▀▄▄ █▀▀█ █▄▄█ █▄▄▄█ █▄▄█ █▀▀█
    █   █▄▄▄ █▄▄▄█ █  █ █  █   █   █  █ █  █
*/
#include <bits/stdc++.h>
using namespace std;

#define MN 30

struct edge {int a, b, w;};

bool cmp(edge a, edge b) {
  return a.w == b.w ? a.a == b.a ? a.b < b.b : a.a < b.a : a.w < b.w;
}

vector<edge> _lar;
int _dsu[MN], _rank[MN], t, n, c;

int find(int v) {return _dsu[v] = _dsu[v] == v ? v : find(_dsu[v]);}

void _union(int x, int y) {
  if (_rank[x] < _rank[y]) swap(x, y);
  _dsu[y] = x;
  _rank[x] += _rank[y];
}

void kruskall() {
  int j = 0, i = 0, A, B;
  sort(_lar.begin(), _lar.end(), cmp);
  while (i < _lar.size() && j < n - 1) {
    A = find(_lar[i].a);
    B = find(_lar[i].b);
    if (A != B) {
      cout << char(_lar[i].a + 65) << "-" << char(_lar[i].b + 65) << " " << _lar[i].w << "\n";
      j++;
      _union(A, B);
    }
    i++;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  char ch;
  cin >> t;
  for (int _i = 1; _i <= t; _i++) {
    cin >> n;
    _lar.clear();
    for (int i = 0; i < n; i++) {_dsu[i] = i, _rank[i] = 1;}
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> c;
        if (c) _lar.push_back({i, j, c});
        if (j < n - 1) cin >> ch;
      }
    }
    cout << "Case " << _i << ":\n";
    kruskall();
  }
  return 0;
}
