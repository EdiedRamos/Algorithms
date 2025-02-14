//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;

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

bool Check(string a, string b) {
    if (a.size() != b.size()) return 0;
    int d = 0;
    for (int i = 0; i < a.size(); i++) if (a[i] != b[i]) d++;
    return d == 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string _s;
    int _t;
    bool _j = 0;
    getline(cin, _s);
    _t = atoi(_s.c_str());
    getline(cin, _s);
    while (_t--) {
        map<string, vector<string>> _g;
        vector<string> _vs;
        while (getline(cin, _s) && _s != "*") {
            _vs.emplace_back(_s);
        }
        for (int i = 0; i < _vs.size(); i++) {
            for (int j = i + 1; j < _vs.size(); j++) {
                if (Check(_vs[i], _vs[j])) {
                    _g[_vs[i]].emplace_back(_vs[j]);
                    _g[_vs[j]].emplace_back(_vs[i]);
                }
            }
        }
        if (_j) cout << "\n";
        _j = 1;
        while (getline(cin, _s) && !_s.empty()) {
            vs prt = split(_s);
            queue<string> _q;
            _q.push(prt[0]);
            map<string, int> _vis;
            for (auto i : _g) {
                _vis[i.first] = -1;
            }
            _vis[prt[0]] = 0;
            while (!_q.empty()) {
                string _act = _q.front();
                _q.pop();
                for (string _v : _g[_act]) {
                    if (_vis[_v] == -1) {
                        _q.push(_v);
                        _vis[_v] = _vis[_act] + 1;
                    }
                }
            }
            cout << _s << " " << _vis[prt[1]] << "\n";
        }
    }
    return 0;
}
