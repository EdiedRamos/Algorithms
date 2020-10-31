//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _t, _l, _n, _w, _r, _x;
    string _s;
    bool _side;
    cin >> _t;
    while (_t--) {
        cin >> _l >> _n;
        queue<int> _left, _right;
        _l *= 100;
        _side = 1;
        for (int i = 0; i < _n; i++) {
            cin >> _w >> _s;
            if (_s[0] == 'l') {
                _left.push(_w);
            } else {
                _right.push(_w);
            }
        }
        _r = 0;
        while (!_left.empty() || !_right.empty()) {
            _x = 0;
            if (_side) {
                while (!_left.empty() && _x + _left.front() <= _l) {
                    _x += _left.front();
                    _left.pop();
                }
            } else {
                while (!_right.empty() && _x + _right.front() <= _l) {
                    _x += _right.front();
                    _right.pop();
                }
            }
            _r++;
            _side = !_side;
        }
        cout << _r << "\n";
    }
    return 0;
}
