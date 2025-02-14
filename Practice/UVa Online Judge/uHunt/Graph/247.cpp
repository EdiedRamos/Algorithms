//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 30

vector<int> lad[MN], _low(MN), _num(MN), _vis(MN);
int _counter, aux;
stack<int> scc;
map<string, int> _getId;
map<int, string> _getName;

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
        bool sp = 0;
        while (1) {
            aux = scc.top(), scc.pop();
            _vis[aux] = 0;
            if (sp) cout << ", ";
            cout << _getName[aux];
            if (aux == current) break;
            sp = 1;
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool _j = 0;
    int n, m, tc = 1;
    string a, b;
    while (cin >> n >> m && n || m) {
        for (int i = 0; i < n; i++) {
            lad[i].clear();
            _low[i] = 0;
            _num[i] = -1;
            _vis[i] = 0;
        }
        _counter = 0;
        _getId.clear(), _getName.clear();
        while (m--) {
            cin >> a >> b;
            if (_getId.find(a) == _getId.end()) _getId[a] = _getId.size();
            if (_getId.find(b) == _getId.end()) _getId[b] = _getId.size();
            if (_getName.find(_getId[a]) == _getName.end()) _getName[_getId[a]] = a;
            if (_getName.find(_getId[b]) == _getName.end()) _getName[_getId[b]] = b;
            lad[_getId[a]].emplace_back(_getId[b]);
        }
        if (_j) cout << "\n";
        cout << "Calling circles for data set " << tc++ << ":\n";
        for (int i = 0; i < n; i++) {
            if (_num[i] == -1) {
                Tarjan(i);
            }
        }
        _j = 1;
    }
    return 0;
}
