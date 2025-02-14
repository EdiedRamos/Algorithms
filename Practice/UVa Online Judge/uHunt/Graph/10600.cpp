//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 105

struct Arco {
    int a, b, w;
};

bool cmp(Arco a, Arco b) {
    return a.w < b.w;
}

bool _igual(Arco a, Arco b) {
    return a.a == b.a && a.b == b.b && a.w == b.w;
}

int ds[MN], _rank[MN], n, m;
vector<Arco> arcos, mst;

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

void Ini() {
    for (int i = 0; i < n; i++) {
        ds[i] = i;
        _rank[i] = 1;
    }
}

int Kruskall(Arco tmp, bool memo) {
    Ini();
    int r = 0, i = 0, c = 0, A, B;
    while (i < arcos.size() && c < n - 1) {
        if (!_igual(tmp, arcos[i])) {
            A = Find(arcos[i].a);
            B = Find(arcos[i].b);
            if (A != B) {
                r += arcos[i].w;
                Union(A, B);
                if (memo) mst.push_back(arcos[i]);
                c++;
            }
        }
        i++;
    }
    return c == n - 1 ? r : 1e9;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, res;
    Arco act;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        arcos.clear();
        mst.clear();
        while (m--) {
            cin >> act.a >> act.b >> act.w;
            act.a--, act.b--;
            arcos.push_back(act);
        }
        sort(arcos.begin(), arcos.end(), cmp);
        res = Kruskall({-1, -1, -1}, 1);
        cout << res << " ";
        res = 1e9;
        for (auto i : mst) {
            res = min(res, Kruskall(i, 0));
        }
        cout << res << "\n";
    }
    return 0;
}
