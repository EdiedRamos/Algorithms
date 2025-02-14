//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _n;
    bool _j = 0;
    string _a, _b;
    while (cin >> _n) {
        map<string, vector<string>> _g;
        map<string, int> _vi;
        map<string, vector<string>> _r;
        while (_n--) {
            cin >> _a >> _b;
            _g[_a].eb(_b);
            _g[_b].eb(_a);
        }
        for (auto i : _g) _vi[i.first] = -1;
        cin >> _a >> _b;
        _vi[_a] = 0;
        _r[_a].eb(_a);
        queue<string> _q;
        _q.push(_a);
        while (!_q.empty()) {
            string _act = _q.front();
            _q.pop();
            for (string _v : _g[_act]) {
                if (_vi[_v] == -1) {
                    _r[_v] = _r[_act];
                    _r[_v].eb(_v);
                    _q.push(_v);
                    _vi[_v] = _vi[_act] + 1;
                }
            }
        }
        if (_j) cout << "\n";
        if (_vi.find(_b) == _vi.end() || _vi[_b] == -1) cout << "No route\n";
        else for (int i = 0; i < _r[_b].size() - 1; i++) cout << _r[_b][i] << " " << _r[_b][i+1] << "\n";
        _j = 1;
    }
    return 0;
}
