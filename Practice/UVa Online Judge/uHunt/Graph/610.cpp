//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 1005

vector<int> lad[MN], _parent(MN), _num(MN), _low(MN);
int _cont;

void Bridges(int cur) {
    _num[cur] = _low[cur] = _cont++;
    for (int v : lad[cur]) {
        if (_num[v] == -1) {
            _parent[v] = cur;
            Bridges(v);
            cout << cur << " " << v << "\n";
            if (_low[v] > _num[cur]) {
                cout << v << " " << cur << "\n";
            }
            _low[cur] = min(_low[cur], _low[v]);
        } else if (v != _parent[cur]) {
            if (_num[v] < _num[cur]) {
                cout << cur << " " << v << "\n";
            }
            _low[cur] = min(_low[cur], _num[v]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b, tc = 1;
    while (cin >> n >> m && n || m) {
        _cont = 0;
        for (int i = 1; i <= n; i++) {
            _parent[i] = _low[i] = 0;
            _num[i] = -1;
            lad[i].clear();
        }
        while (m--) {
            cin >> a >> b;
            lad[a].emplace_back(b);
            lad[b].emplace_back(a);
        }
        cout << tc++ << "\n\n";
        for (int i = 1; i <= n; i++) {
            if (_num[i] == -1) {
                Bridges(i);
            }
        }
        cout << "#\n";
    }
    return 0;
}
