//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 105
#define INF 1e9

int n, m, _max, x, r;

vector<pair<int,int>> lad[MN];

int Dijkstra(int A, int B) {
    if (A == B) return 0;
    vector<int> dt(n+1, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> cola;
    cola.push({0, A});
    dt[A] = 0;
    while (!cola.empty()) {
        pair<int,int> act = cola.top();
        cola.pop();
        if (act.first > dt[act.second]) continue;
        for (auto i : lad[act.second]) {
            if (dt[i.first] > dt[act.second] + i.second) {
                dt[i.first] = dt[act.second] + i.second;
                cola.push({dt[i.first], i.first});
            }
        }
    }
    return dt[B];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, _a, _b, _c;
    bool _j = 0;
    cin >> t;
    while (t--) {
        cin >> n >> x >> _max >> m;
        for (int i = 1; i <= n; i++)
            lad[i].clear();
        r = 0;
        while (m--) {
            cin >> _a >> _b >> _c;
            lad[_a].push_back({_b, _c});
        }
        for (int i = 1; i <= n; i++)
            r += Dijkstra(i, x) <= _max;
        if (_j) cout << "\n";
        cout << r << "\n";
        _j = 1;
    }
    return 0;
}
