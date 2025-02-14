//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string _s, _u;
    int _t, _n, _r, _k, _p;
    cin >> _t;
    cout << "SHIPPING ROUTES OUTPUT\n";
    for (int _i = 1; _i <= _t; _i++) {
        cout << "\nDATA SET  " << _i << "\n\n";
        cin >> _n >> _r >> _k;
        map<string, vector<string>> _map;
        map<string, int> _dt;
        for (int i = 0; i < _n; i++) {
            cin >> _s;
            _dt[_s] = -1;
            _map[_s] = {};
        }
        for (int i = 0; i < _r; i++) {
            cin >> _s >> _u;
            _map[_s].emplace_back(_u);
            _map[_u].emplace_back(_s);
        }
        for (int i = 0; i < _k; i++) {
            cin >> _p >> _s >> _u;
            for (auto &j : _dt) {
                j.second = -1;
            }
            _dt[_s] = 0;
            queue<string> _q;
            _q.push(_s);
            while (!_q.empty()) {
                string _act = _q.front();
                _q.pop();
                for (string _x : _map[_act]) {
                    if (_dt[_x] == -1) {
                        _dt[_x] = _dt[_act] + 1;
                        _q.push(_x);
                    }
                }
            }
            if (_dt[_u] == -1) cout << "NO SHIPMENT POSSIBLE\n";
            else cout << "$" << 100 * _dt[_u] * _p << "\n";
        }
    }
    cout << "\nEND OF OUTPUT\n";
    return 0;
}
