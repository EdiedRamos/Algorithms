//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _t, _s, _k;
    string _a, _b;
    bool _j = 0;
    cin >> _t;
    while (_t--) {
        if (_j) cout << "\n";
        _j = 1;
        map<string, vector<string>> _g;
        map<string, int> _v;
        map<string, vector<string>> _r;
        cin >> _s >> _k;
        for (int i = 0; i < _s; i++) {
            cin >> _a >> _b;
            _g[_a].emplace_back(_b);
            _g[_b].emplace_back(_a);
        }
        while (_k--) {
            cin >> _a >> _b;
            for (auto i : _g) {
                _v[i.first] = -1;
                _r[i.first].clear();
            }
            _v[_a] = 0;
            _r[_a].emplace_back(_a);
            queue<string> _q;
            _q.push(_a);
            while (!_q.empty()) {
                string _act = _q.front();
                _q.pop();
                for (string _x : _g[_act]) {
                    if (_v[_x] == -1) {
                        _r[_x] = _r[_act];
                        _r[_x].emplace_back(_x);
                        _v[_x] = _v[_act] + 1;
                        _q.push(_x);
                    }
                }
            }
            for (string _s : _r[_b]) cout << _s[0];
            cout << "\n";
        }
    }
    return 0;
}
