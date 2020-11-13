//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 105

struct Edge {
    int a, b, cost, pos;
};

int ds[MN], _r[MN], n, v, total;
vector<Edge> edgel, mst;
bool vis[MN];
vector<int> lad[MN];

bool cmp(Edge a, Edge b) {
    return a.cost < b.cost;
}

int Find(int x) {
    return ds[x] = ds[x] == x ? x : Find(ds[x]);
}

void Union(int x, int y) {
    if (_r[x] < _r[y]) swap(x, y);
    ds[y] = x;
    _r[x] += _r[y];
}

void DFS(int x) {
    vis[x] = 1;
    for (int i : lad[x]) {
        if (!vis[i]) {
            DFS(i);
        }
    }
}

void Kruskall(int p, bool f) {
    for (int i = 0; i < n; i++) {
        ds[i] = i;
        _r[i] = 1;
    }
    total = 0;
    int i = 0, c = 0, A, B;
    while (i < edgel.size() && c < n - 1) {
        if (edgel[i].pos != p) {
            A = Find(edgel[i].a);
            B = Find(edgel[i].b);
            if (A != B) {
                Union(A, B);
                if (f) mst.push_back(edgel[i]);
                total += edgel[i].cost;
                c++;
            }
        }
        i++;
    }
    if (c != n - 1) total = 1e9;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc, res;
    bool cc;
    Edge ed;
    cin >> tc;
    for (int _i = 1; _i <= tc; _i++) {
        cin >> n >> v;
        edgel.clear();
        mst.clear();
        for (int i = 0; i < n; i++) {
            lad[i].clear();
            vis[i] = 0;
        }
        while (v--) {
            cin >> ed.a >> ed.b >> ed.cost;
            ed.pos = edgel.size();
            ed.a--, ed.b--;
            edgel.push_back(ed);
            lad[ed.a].push_back(ed.b);
            lad[ed.b].push_back(ed.a);
        }
        DFS(0);
        cc = 1;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cc = 0;
            }
        }
        cout << "Case #" << _i << " : ";
        if (cc) {
            sort(edgel.begin(), edgel.end(), cmp);
            Kruskall(-1, 1);
            res = 1e9;
            for (auto i : mst) {
                Kruskall(i.pos, 0);
                res = min(res, total);
            }
            if (res != 1e9) cout << res << "\n";
            else cout << "No second way\n";
        } else cout << "No way\n";
    }
    return 0;
}
