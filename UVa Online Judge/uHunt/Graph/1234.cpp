//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 10005

struct Arco {
    int a, b, w;
};

bool cmp(Arco a, Arco b) {
    return a.w > b.w;
}

int ds[MN], _rank[MN], _n, _r;
vector<Arco> _lar;
Arco _ar;

int Find(int v) {
    return ds[v] == v ? v : Find(ds[v]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) return;
    if (_rank[x] < _rank[y]) swap(x, y);
    ds[y] = x;
    _rank[x] += _rank[y];
}

int Kruskall() {
    sort(_lar.begin(), _lar.end(), cmp);
    int n = 0, c = 0, i = 0;
    while (i < _lar.size()) {
        Arco tmp = _lar[i];
        tmp.a = Find(tmp.a);
        tmp.b = Find(tmp.b);
        if (tmp.a != tmp.b) {
            Union(tmp.a, tmp.b);
            n++;
        } else c += tmp.w;
        i++;
    }
    return c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _tc;
    cin >> _tc;
    while (_tc--) {
        cin >> _n >> _r;
        _lar.clear();
        for (int i = 0; i < _n; i++) {
            ds[i] = i;
            _rank[i] = 1;
        }
        while (_r--) {
            cin >> _ar.a >> _ar.b >> _ar.w;
            _ar.a--, _ar.b--;
            _lar.emplace_back(_ar);
        }
        cout << Kruskall() << "\n";
    }
    cin >> _n;
    return 0;
}
