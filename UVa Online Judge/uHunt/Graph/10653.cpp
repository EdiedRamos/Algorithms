//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _f, _c, _bi, _r, _k, _x;
    pii _a, _b;
    while (cin >> _f >> _c && _f || _c) {
        cin >> _bi;
        vector<vector<int>> _map(_f, vector<int>(_c, -1));
        while (_bi--) {
            cin >> _r >> _k;
            while (_k--) {
                cin >> _x;
                _map[_r][_x] = 1e9;
            }
        }
        cin >> _a.first >> _a.second >> _b.first >> _b.second;
        _map[_a.first][_a.second] = 0;
        queue<pii> _q;
        _q.push(_a);
        while (!_q.empty()) {
            pii _act = _q.front();
            _q.pop();
            if (_act.first-1 >= 0 && _map[_act.first-1][_act.second] == -1) {
                _map[_act.first-1][_act.second] = _map[_act.first][_act.second]+1;
                _q.push({_act.first-1,_act.second});
            }
            if (_act.first+1 < _f  && _map[_act.first+1][_act.second] == -1) {
                _map[_act.first+1][_act.second] = _map[_act.first][_act.second]+1;
                _q.push({_act.first+1,_act.second});
            }
            if (_act.second-1 >=0 && _map[_act.first][_act.second-1] == -1) {
                _map[_act.first][_act.second-1] = _map[_act.first][_act.second]+1;
                _q.push({_act.first,_act.second-1});
            }
            if (_act.second+1 < _c && _map[_act.first][_act.second+1] == -1) {
                _map[_act.first][_act.second+1] = _map[_act.first][_act.second]+1;
                _q.push({_act.first,_act.second+1});
            }
        }
        cout << _map[_b.first][_b.second] << "\n";
    }
    return 0;
}
