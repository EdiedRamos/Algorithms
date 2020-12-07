//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 105

typedef vector<int> vi;

vi lad[MN], _num(MN), _low(MN), _parent(MN);
vector<bool> _artver(MN);
int _counter, _root, _rootch;

vi split(string s) {
    vi r;
    string _c = "";
    for (char c : s) {
        if (c == ' ') {
            if (!_c.empty()) {
                r.emplace_back(atoi(_c.c_str()));
                _c = "";
            }
        } else _c += c;
    }
    if (!_c.empty()) r.emplace_back(atoi(_c.c_str()));
    return r;
}

void ArticulationP(int act) {
    _low[act] = _num[act] = _counter++;
    for (int v : lad[act]) {
        if (_num[v] == -1) {
            _parent[v] = act;
            if (act == _root) _rootch++;
            ArticulationP(v);
            if (_low[v] >= _num[act]) _artver[act] = 1;
            _low[act] = min(_low[act], _low[v]);
        } else if (v != _parent[act]){
            _low[act] = min(_low[act], _num[v]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, _i, res;
    vi prt;
    string s;
    while (getline(cin, s) && s != "0") {
        n = atoi(s.c_str());
        _counter = res = 0;
        for (int i = 1; i <= n; i++) {
            lad[i].clear();
            _num[i] = -1;
            _low[i] = 0;
            _artver[i] = 0;
            _parent[i] = 0;
        }
        while (getline(cin, s) && s != "0") {
            prt = split(s);
            for (int i = 1; i < prt.size(); i++) {
                lad[prt[0]].emplace_back(prt[i]);
                lad[prt[i]].emplace_back(prt[0]);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (_num[i] == -1) {
                _root = i;
                _rootch = 0;
                ArticulationP(i);
                _artver[i] = (_rootch > 1);
            }
        }
        for (int i = 1; i <= n; i++) res += _artver[i];
        cout << res << "\n";
    }
    return 0;
}
