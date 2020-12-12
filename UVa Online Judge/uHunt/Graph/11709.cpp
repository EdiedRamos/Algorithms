//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;

map<string, vector<string>> lad;
map<string, int> _low, _num;
map<string, bool> _vis;
int _count, _res;
string act;
stack<string> scc;

void Tarjan(string current) {
    _low[current] = _num[current] = _count++;
    _vis[current] = 1;
    scc.push(current);
    for (string v : lad[current]) {
        if (_num[v] == -1) {
            Tarjan(v);
        }
        if (_vis[v]) {
            _low[current] = min(_low[current], _low[v]);
        }
    }
    if (_low[current] == _num[current]) {
        _res++;
        while (1) {
            act = scc.top();
            scc.pop();
            _vis[act] = 0;
            if (act == current) break;
        }
    }
}

vs split(string s) {
    vs r;
    string _c = "";
    for (char c : s) {
        if (c == ' ') {
            if (!_c.empty()) {
                r.emplace_back(_c);
                _c = "";
            }
        } else _c += c;
    }
    if (!_c.empty()) r.emplace_back(_c);
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string input, inp;
    vs names;
    int n, m;
    while (getline(cin, input) && input != "0 0") {
        vs prt = split(input);
        n = atoi(prt[0].c_str());
        m = atoi(prt[1].c_str());
        _vis.clear(), _low.clear(), _num.clear(), lad.clear(), names.clear();
        _res = 0;
        while (n--) {
            getline(cin, input);
            names.emplace_back(input);
            _num[input] = -1;
        }
        while (m--) {
            getline(cin, input);
            getline(cin, inp);
            lad[input].emplace_back(inp);
        }
        for (string s : names) {
            if (_num[s] == -1) {
                Tarjan(s);
            }
        }
        cout << _res << "\n";
    }
    return 0;
}
