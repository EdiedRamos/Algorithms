//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 10005

vector<int> lad[MN], _parent(MN), _num(MN), _low(MN), _articulationp(MN);
int _cont, _root, _rootch;

void ArticulationP(int current) {
    _num[current] = _low[current] = _cont++;
    for (int neighbour : lad[current]) {
        if (_num[neighbour] == -1) {
            _parent[neighbour] = current;
            if (current == _root) _rootch++;
            ArticulationP(neighbour);
            if (_low[neighbour] >= _num[current]) {
                _articulationp[current]++;
            }
            _low[current] = min(_low[current], _low[neighbour]);
        } else if (_parent[current] != neighbour) {
            _low[current] = min(_low[current], _num[neighbour]);
        }
    }
}

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.second == b.second ? a.first < b.first : a.second > b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    while (cin >> n >> m && n || m) {
        _cont = 0;
        for (int i = 0; i < n; i++) {
            lad[i].clear();
            _parent[i] = _low[i] = 0;
            _articulationp[i] = 0;
            _num[i] = -1;
        }
        while (cin >> a >> b && a > 0 || b > 0) {
            lad[a].emplace_back(b);
            lad[b].emplace_back(a);
        }
        for (int i = 0; i < n; i++) {
            if (_num[i] == -1) {
                _root = i;
                _rootch = 0;
                ArticulationP(i);
                _articulationp[i] = _rootch > 1;
            }
        }
        vector<pair<int,int>> res;
        for (int i = 0; i < n; i++) {
            res.push_back({i, _articulationp[i] + 1});
        }
        sort(res.begin(), res.end(), cmp);
        for (int i = 0; i < n && i < m; i++) {
            cout << res[i].first << " " << res[i].second << "\n";
        }
        cout << "\n";
    }
    return 0;
}
