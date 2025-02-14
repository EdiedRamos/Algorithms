//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 100005

vector<int> lad[MN], _low(MN), _num(MN), _vis(MN), _act, _in[MN];
int _counter, dscc, aux;
bool opc;
stack<int> scc;

void Tarjan(int current) {
    _low[current] = _num[current] = _counter++;
    _vis[current] = 1;
    scc.push(current);
    for (int v : lad[current]) {
        if (_num[v] == -1) {
            Tarjan(v);
        }
        if (_vis[v]) {
            _low[current] = min(_low[current], _low[v]);
        }
    }
    if (_num[current] == _low[current]) {
        _act.clear();
        while (1) {
            aux = scc.top();
            _act.emplace_back(aux);
            scc.pop();
            _vis[aux] = 0;
            if (aux == current) break;
        }
        sort(_act.begin(), _act.end());
        opc = 1;
        for (int i : _act) {
            for (int x : _in[i]) {
                if (!binary_search(_act.begin(), _act.end(), x)) {
                    opc = 0;
                    break;
                }
            }
            if (!opc) {
                break;
            }
        }
        dscc += opc;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, m, a, b;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            lad[i].clear();
            _low[i] = 0;
            _in[i].clear();
            _num[i] = -1;
            _vis[i] = 0;
        }
        dscc = _counter = 0;
        while (!scc.empty()) {
            scc.pop();
        }
        while (m--) {
            cin >> a >> b;
            lad[a].emplace_back(b);
            _in[b].emplace_back(a);
        }
        for (int i = 1; i <= n; i++) {
            if (_num[i] == -1) {
                Tarjan(i);
            }
        }
        cout << dscc << "\n";
    }
    return 0;
}
