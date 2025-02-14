//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 505

struct Edge {
    int a, b;
    long p;
};

int ds[MN], _r[MN], n, m, res, A, B;
long mx;
vector<Edge> edgel;

int Find(int v) {
    return ds[v] = ds[v] == v ? v : Find(ds[v]);
}

void Union(int a, int b) {
    if (_r[a] < _r[b]) swap(a, b);
    ds[b] = a;
    _r[a] += _r[b];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Edge tmp;
    while (cin >> n >> m && n || m) {
        edgel.clear();
        mx = -9999999999;
        res = 0;
        for (int i = 0; i < n; i++) {
            ds[i] = i;
            _r[i] = 1;
        }
        while (m--) {
            cin >> tmp.a >> tmp.b >> tmp.p;
            tmp.a--, tmp.b--;
            edgel.push_back(tmp);
            mx = max(mx, tmp.p);
        }
        for (auto i : edgel) {
            if (i.p == mx) {
                A = Find(i.a);
                B = Find(i.b);
                if (A != B) {
                    Union(A, B);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            res = max(res, _r[i]);
        }
        cout << res << "\n";
    }
    return 0;
}
