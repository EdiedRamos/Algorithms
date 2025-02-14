//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _n, _x, _y, a, b;
    cin >> _n;
    vector<int> _g[_n];
    int vi[_n], _boom[_n];
    for (int i = 0; i < _n; i++) {
        cin >> _x;
        while (_x--) {
            cin >> _y;
            _g[i].emplace_back(_y);
        }
    }
    cin >> _x;
    while (_x--) {
        cin >> _y;
        memset(vi, -1, sizeof vi);
        vi[_y] = 0;
        queue<int> _q;
        _q.push(_y);
        while (!_q.empty()) {
            int _t = _q.front();
            _q.pop();
            for (int v : _g[_t]) {
                if (vi[v] == -1) {
                    vi[v] = vi[_t] + 1;
                    _q.push(v);
                }
            }
        }
        memset(_boom, 0, sizeof _boom);
        for (int i = 0; i < _n; i++) {
            _boom[vi[i]]++;
        }
        a = -1e9, b = 0;
        for (int i = 1; i < _n; i++) {
            if (_boom[i] > a) {
                a = _boom[i];
                b = i;
            }
        }
        if (!a) cout << "0\n";
        else cout << a << " " << b << "\n";
    }
    return 0;
}
