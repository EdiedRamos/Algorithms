//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int _x, _y, _c;

typedef vector<string> vs;

vector<string> _map;

vs split(string s) {
    vs r;
    string _c = "";
    for (char c : s) {
        if (c == ' ') {
            if (!_c.empty()) {
                r.emplace_back(_c);
                _c = "";
            }
        } _c += c;
    }
    if (!_c.empty()) r.emplace_back(_c);
    return r;
}

void FF(int _i, int _j) {
    if (_i < 0 || _j < 0 || _i == _map.size() || _j == _map[0].size() || _map[_i][_j] == '1') return;
    _map[_i][_j] = '1';
    _c++;
    FF(_i+1,_j);
    FF(_i-1,_j);
    FF(_i,_j+1);
    FF(_i,_j-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string _s;
    bool _j = 0;
    int _t;
    getline(cin, _s);
    _t = atoi(_s.c_str());
    getline(cin, _s);
    while (_t--) {
        _map.clear();
        getline(cin, _s);
        vs pr = split(_s);
        _x = atoi(pr[0].c_str());
        _y = atoi(pr[1].c_str());
        while (getline(cin, _s) && !_s.empty()) {
            _map.emplace_back(_s);
        }
        _c = 0;
        FF(_x-1, _y-1);
        if (_j) cout << "\n";
        cout << _c << "\n";
        _j = 1;
    }
    return 0;
}
