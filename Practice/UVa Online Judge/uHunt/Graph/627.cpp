//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _n, _k, _a, _b;
    string _s, _c;
    while (cin >> _n) {
        vector<int> l_a[_n], _rt[_n];
        int _dt[_n];
        for (int i = 0; i < _n; i++) {
            cin >> _s;
            int j = 0;
            while (_s[j++] != '-');
            _c = "";
            while (j < _s.size()) {
                if (_s[j] == ',') {
                    l_a[i].emplace_back(atoi(_c.c_str())-1);
                    _c = "";
                } else _c += _s[j];
                j++;
            }
            if (!_c.empty())l_a[i].emplace_back(atoi(_c.c_str())-1);
        }
        cin >> _k;
        cout << "-----\n";
        while (_k--) {
            cin >> _a >> _b;
            _a--, _b--;
            for (int i = 0; i < _n; i++) {
                _dt[i] = -1;
                _rt[i].clear();
            }
            _dt[_a] = 0;
            _rt[_a].emplace_back(_a);
            queue<int> _q;
            _q.push(_a);
            while (!_q.empty()) {
                int _act = _q.front();
                _q.pop();
                for (int _i : l_a[_act]) {
                    if (_dt[_i] == -1) {
                        _dt[_i] = _dt[_act] + 1;
                        _rt[_i] = _rt[_act];
                        _rt[_i].emplace_back(_i);
                        _q.push(_i);
                    }
                }
            }
            if (_rt[_b].empty()) cout << "connection impossible";
            else for (int _i = 0; _i < _rt[_b].size(); _i++) {
                if (_i) cout << " ";
                cout << _rt[_b][_i] + 1;
            }
            cout << "\n";
        }
    }
    return 0;
}
