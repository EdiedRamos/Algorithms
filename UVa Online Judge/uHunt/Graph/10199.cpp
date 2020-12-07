//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 105

vector<int> lad[MN], _num(MN), _low(MN), _ap(MN), _parent(MN);
int _cont, _root, _rootch;

void Articulation(int act) {
    _num[act] = _low[act] = _cont++;
    for (int v : lad[act]) {
        if (_num[v] == -1) {
            _parent[v] = act;
            if (act == _root) _rootch++;
            Articulation(v);
            if (_low[v] >= _num[act]) _ap[act] = 1;
            _low[act] = min(_low[act], _low[v]);
        } else if (v != _parent[act]) {
            _low[act] = min(_low[act], _num[v]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, tc = 1;
    bool _j = 0;
    string city, city2;
    while (cin >> n && n) {
        map<string, int> rel;
        map<int, string> rel2;
        vector<string> sol;
        for (int i = 0; i < n; i++) {
            lad[i].clear();
            _num[i] = -1;
            _low[i] = 0;
            _ap[i] = 0;
            _parent[i] = 0;
            cin >> city;
            rel2[rel2.size()] = city;
            rel[city] = rel.size();
        }
        _cont = 0;
        cin >> m;
        while (m--) {
            cin >> city >> city2;
            lad[rel[city]].emplace_back(rel[city2]);
            lad[rel[city2]].emplace_back(rel[city]);
        }
        for (int i = 0; i < n; i++) {
            if (_num[i] == -1) {
                _root = i;
                _rootch = 0;
                Articulation(i);
                _ap[i] = _rootch > 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (_ap[i]) {
                sol.push_back(rel2[i]);
            }
        }
        if (_j) cout << "\n";
        _j = 1;
        cout << "City map #" << tc++ << ": " << sol.size() << " camera(s) found\n";
        sort(sol.begin(), sol.end());
        for (string i : sol) cout << i << "\n";
    }
    return 0;
}
