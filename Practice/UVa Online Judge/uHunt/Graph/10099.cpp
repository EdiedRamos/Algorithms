//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 105

struct Edge {
    int a, b, w;
};

bool cmp(Edge a, Edge b) {
    return a.w > b.w;
}

bool vis[MN];
int n, v, ds[MN], _r[MN], rta[MN];
vector<Edge> edgel;
vector<pair<int,int>> lad[MN];

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
            lad[edgel[i].a].push_back({edgel[i].b, edgel[i].w});
            lad[edgel[i].b].push_back({edgel[i].a, edgel[i].w});
            c++;
        }
        i++;
    }
}

void DFS(int a) {
    vis[a] = 1;
    for (auto i : lad[a]) {
        if (!vis[i.first]) {
            rta[i.first] = min(rta[a], i.second);
            DFS(i.first);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1, a, b, d, r;
    while (cin >> n >> v && n || v) {
        edgel.clear();
        for (int i = 0; i < n; i++) {
            ds[i] = i;
            _r[i] = 1;
            vis[i] = 0;
            lad[i].clear();
        }
        while (v--) {
            cin >> a >> b >> d;
            a--, b--, d--;
            edgel.push_back({a, b, d});
        }
        cin >> a >> b >> d;
        a--, b--;
        Kruskall();
        rta[a] = 1e9;
        DFS(a);
        cout << "Scenario #" << tc++ << "\nMinimum Number of Trips = " << (d / rta[b]) + (d % rta[b] != 0) << "\n\n";
    }
    return 0;
}
