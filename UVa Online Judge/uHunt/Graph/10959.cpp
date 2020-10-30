//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool j = 0;
    int _t, _n, _r, _a, _b;
    cin >> _t;
    while (_t--) {
        cin >> _n >> _r;
        vector<int> l_a[_n];
        vector<int> _dt(_n, -1);
        while (_r--) {
            cin >> _a >> _b;
            l_a[_a].emplace_back(_b);
            l_a[_b].emplace_back(_a);
        }
        _dt[0] = 0;
        queue<int> _q;
        _q.push(0);
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
        for (int i = 1; i < _n; i++) cout << _dt[i] << "\n";
    }
    return 0;
}
