//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 205

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

int Find(int v) {
    return ds[v] = ds[v] == v ? v : Find(ds[v]);
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
    for (auto v : lad[a]) {
        if (!vis[v.first]) {
            rta[v.first] = min(rta[a], v.second);
            DFS(v.first);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1, val;
    string x, y;
    map<string, int> conv;
    while (cin >> n >> v && n || v) {
        edgel.clear();
        conv.clear();
        for (int i = 0; i < n; i++) {
            ds[i] = i;
            _r[i] = 1;
            vis[i] = 0;
            lad[i].clear();
        }
        while (v--) {
            cin >> x >> y >> val;
            conv.insert({x, conv.size()});
            conv.insert({y, conv.size()});
            edgel.push_back({conv[x], conv[y], val});
        }
        cin >> x >> y;
        Kruskall();
        rta[conv[x]] = 1e9;
        DFS(conv[x]);
        cout << "Scenario #" << tc++ << "\n" << rta[conv[y]] << " tons\n\n";
    }
    return 0;
}
