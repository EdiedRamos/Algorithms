//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 105

struct Arco {
    int a, b, p;  
};

int ds[MN], _rank[MN], n, p, q, x, y;
bool vis[MN];
vector<pair<int,int>> l_ad[MN];
vector<Arco> l_ar;
priority_queue<int> path[MN];

bool cmp(Arco a, Arco b) {
    return a.p < b.p;
}

int Find(int v) {
    return ds[v] = ds[v] == v ? v : Find(ds[v]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    if (_rank[a] < _rank[b]) swap(a, b);
    ds[b] = a;
    _rank[a] += _rank[b];
}

void Kruskall() {
    sort(l_ar.begin(), l_ar.end(), cmp);
    int i = 0, c = 0, A, B;
    while (i < l_ar.size() && c < n - 1) {
        A = Find(l_ar[i].a);
        B = Find(l_ar[i].b);
        if (A != B) {
            c++;
            l_ad[l_ar[i].a].push_back({l_ar[i].b, l_ar[i].p});
            l_ad[l_ar[i].b].push_back({l_ar[i].a, l_ar[i].p});
            Union(A, B);
        }
        i++;
    }
}

void DFS(int a, int b) {
    vis[a] = 1;
    for (auto v : l_ad[a]) {
        if (!vis[v.first]) {
            path[v.first].push(path[a].top());
            path[v.first].push(v.second);
            if (v.first == b) return;
            DFS(v.first, b);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool _j = 0;
    Arco act;
    int tc = 1;
    priority_queue<int> _e;
    _e.push(0);
    while (cin >> n >> p >> q && n || p || q) {
        l_ar.clear();
        for (int i = 0; i < n; i++) {
            ds[i] = i;
            path[i] = _e;
            _rank[i] = 1;
            l_ad[i].clear();
        }
        for (int i = 0; i < p; i++) {
            cin >> act.a >> act.b >> act.p;
            act.a--;
            act.b--;
            l_ar.push_back(act);
        }
        Kruskall();
        if (_j) cout << "\n";
        _j = 1;
        cout << "Case #" << tc++ << "\n";
        while (q--) {
            cin >> x >> y;
            x--, y--;
            for (int i = 0; i < n; i++) {
                path[i] = _e;
            }
            memset(vis, 0, sizeof vis);
            if (Find(x) != Find(y)) {
                cout << "no path\n";
            } else {
                DFS(x, y);
                cout << path[y].top() << "\n";
            }
        }
    }
    return 0;
}
