//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    double a, b;
    int _i;
    vector<int> _r;
    bool _j;
    while (cin >> a >> b) {
        _r.clear();
        _j = 0;
        a /= b;
        _i = a;
        _r.push_back(_i);
        a -= _i * 1.0;
        while (a > 0.0) {
            a = 1.0 / a;
            _i = a;
            if (_i < 0) break;
            _r.push_back(_i);
            a -= _i * 1.0;
            _j = 1;
        }
        if (_r.size() == 1) {
            cout << "[" << _r[0] << "]\n";
            continue;
        }
        _r[_r.size()-2] += _r[_r.size()-1] == 1 ? 1 : 0;
        if (_r[_r.size()-1] == 1) _r.erase(_r.end()-1);
        cout << "[";
        for (int i = 0; i < _r.size(); i++) {
            if (i == 1) cout << ";";
            else if (i > 1) cout << ",";
            cout << _r[i];
        }
        cout << "]";
        cout << "\n";
    }
    return 0;
}
