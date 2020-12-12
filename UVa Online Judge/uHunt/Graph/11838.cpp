//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 2005

vector<int> lad[MN], _low(MN), _num(MN);
vector<bool> _vis(MN);
stack<int> scc;
int _counter, dscc, aux;

void Tarjan(int current) {
    _low[current] = _num[current] = _counter++;
    scc.push(current);
    _vis[current] = 1;
    for (int v : lad[current]) {
        if (_num[v] == -1) {
            Tarjan(v);
        }
        if (_vis[v]) {
            _low[current] = min(_low[current], _low[v]);
        }
    }
    if (_num[current] == _low[current]) {
        dscc++;
        while (1) {
            aux = scc.top();
            scc.pop();
            _vis[aux] = 0;
            if (aux == current) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b, c;
    while (cin >> n >> m && n || m) {
        for (int i = 1; i <= n; i++) {
            _low[i] = 0;
            lad[i].clear();
            _num[i] = -1;
            _vis[i] = 0;
        }
        while (m--) {
            cin >> a >> b >> c;
            lad[a].push_back(b);
            if (c > 1) lad[b].push_back(a);
        }
        while (!scc.empty()) {
            scc.pop();
        }
        _counter = dscc = 0;
        for (int i = 1; i <= n; i++) {
            if (_num[i] == -1) {
                Tarjan(i);
            }
        }
        cout << (dscc == 1 ? 1 : 0) << "\n";
    }
    return 0;
}
