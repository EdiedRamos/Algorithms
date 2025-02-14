//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool j = 0;
    int _t, _n, _r, _s, _x, _a, _b;
    cin >> _t;
    while (_t--) {
        cin >> _n;
        vector<int> l_a[_n];
        vector<int> _dt(_n, -1);
        for (int i = 0; i < _n; i++) {
            cin >> _s >> _r;
            while (_r--) {
                cin >> _x;
                l_a[_s].emplace_back(_x);
            }
        }
        cin >> _a >> _b;
        _dt[_a] = 0;
        queue<int> _q;
        _q.push(_a);
        while (!_q.empty()) {
            int _act = _q.front();
            _q.pop();
            for (int i : l_a[_act]) {
                if (_dt[i] == -1) {
                    _dt[i] = _dt[_act] + 1;
                    _q.push(i);
                }
            }
        }
        if (j) cout << "\n";
        j = 1;
        cout << _a << " " << _b << " " << _dt[_b] - 1 << "\n";
    }
    return 0;
}
