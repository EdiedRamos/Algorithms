//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 105

struct Edge {
    int a, b, c;
};

int ds[MN], _r[MN], n, v;
vector<Edge> edgel, mst;

bool cmp(Edge a, Edge b) {
    return a.c > b.c;
}

int Find(int x) {
    return ds[x] = ds[x] == x ? x : Find(ds[x]);
}

void Union(int a, int b) {
    if (_r[a] < _r[b]) swap(a, b);
    ds[b] = a;
    _r[a] += _r[b];
}

void Kruskall() {
    sort(edgel.begin(), edgel.end(), cmp);
    int i = 0, c = 0, A, B;
    while (i < edgel.size() && c < n - 1) {
        A = Find(edgel[i].a);
        B = Find(edgel[i].b);
        if (A != B) {
            Union(A, B);
            mst.push_back(edgel[i]);
            c++;
        }
        i++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc, res;
    Edge act;
    cin >> tc;
    for (int _i = 1; _i <= tc; _i++) {
        cin >> n >> v;
        for (int i = 0; i < n; i++) {
            ds[i] = i;
            _r[i] = 1;
        }
        res = 1e9;
        edgel.clear();
        mst.clear();
        while (v--) {
            cin >> act.a >> act.b >> act.c;
            edgel.push_back(act);
        }
        Kruskall();
        for (auto i : mst) {
            res = min(res, i.c);
        }
        cout << "Case #" << _i << ": " << res << "\n";
    }
    return 0;
}
