//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 305

typedef vector<int> vi;

vi lad[MN], _low(MN), _num(MN), _parent(MN);
vector<pair<int,int>> bridges;
int _cont;

void Bridges(int cur) {
    _low[cur] = _num[cur] = _cont++;
    for (int v : lad[cur]) {
        if (_num[v] == -1) {
            _parent[v] = cur;
            Bridges(v);
            if (_low[v] > _num[cur]) {
                if (cur < v) bridges.push_back({cur, v});
                else bridges.push_back({v, cur});
            }
            _low[cur] = min(_low[cur], _low[v]);
        } else if (v != _parent[cur]){
            _low[cur] = min(_low[cur], _num[v]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, c;
    string s;
    while (cin >> n) {
        _cont = 0;
        bridges.clear();
        for (int i = 0; i < n; i++) {
            lad[i].clear();
            _low[i] = 0;
            _num[i] = -1;
            _parent[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            cin >> a >> s;
            b = atoi(s.substr(1, s.size() - 2).c_str());
            while (b--) {
                cin >> c;
                lad[a].emplace_back(c);
            }
        }
        for (int i = 0; i < n; i++) {
            if (_num[i] == -1) {
                Bridges(i);
            }
        }
        sort(bridges.begin(), bridges.end());
        cout << bridges.size() << " critical links\n";
        for (auto i : bridges) cout << i.first << " - " << i.second << "\n";
        cout << "\n";
    }
    return 0;
}
