//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 1000005

struct Edge {
    int a, b, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

vector<Edge> edgel;
int ds[MN], _r[MN];

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
    int n, old, k, _new, _a, _b, A, B;
    bool jm = 0;
    Edge act;
    while (cin >> n) {
        old = _new = 0;
        edgel.clear();
        for (int i = 1; i <= n; i++) {
            ds[i] = i;
            _r[i] = 1;
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> act.a >> act.b >> act.w;
            old += act.w;
        }
        for (int i = 0; i < 2; i++) {
            cin >> k;
            while (k--) {
                cin >> act.a >> act.b >> act.w;
                edgel.push_back(act);
            }
        }
        sort(edgel.begin(), edgel.end(), cmp);
        _a = _b = 0;
        while (_a < edgel.size() && _b < n - 1) {
            A = Find(edgel[_a].a);
            B = Find(edgel[_a].b);
            if (A != B) {
                Union(A, B);
                _new += edgel[_a].w;
                _b++;
            }
            _a++;
        }
        if (jm) cout << "\n";
        cout << old << "\n" << _new << "\n";
        jm = 1;
    }
    return 0;
}
