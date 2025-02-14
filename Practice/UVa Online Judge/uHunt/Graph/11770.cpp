//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 10005

vector<int> lad[MN], _low(MN), _num(MN), team, _input[MN];
vector<bool> _vis(MN);
stack<int> scc;
bool nice;
int _counter, aux, res;

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
    if (_low[current] == _num[current]) {
        team.clear();
        while (1) {
            aux = scc.top(), scc.pop();
            _vis[aux] = 0;
            team.emplace_back(aux);
            if (aux == current) break;
        }
        sort(team.begin(), team.end());
        for (int i : team) {
            nice = 1;
            for (int x : _input[i]) {
                if (!binary_search(team.begin(), team.end(), x)) {
                    nice = 0;
                    break;
                }
            }
            if (!nice) break;
        }
        res += nice;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, m, a, b;
    cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            lad[i].clear();
            _low[i] = 0;
            _input[i].clear();
            _num[i] = -1;
            _vis[i] = 0;
        }
        _counter = 0;
        res = 0;
        while (m--) {
            cin >> a >> b;
            lad[a].emplace_back(b);
            _input[b].emplace_back(a);
        }
        for (int i = 1; i <= n; i++) {
            if (_num[i] == -1) {
                Tarjan(i);
            }
        }
        cout << "Case " << _i <<": " << res << "\n";
    }
    return 0;
}
