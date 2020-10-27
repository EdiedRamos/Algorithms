//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 105

typedef vector<string> vs;

int _a, _b, _n, _map[MN][MN], _c, _act;
bool used[MN];

void FF(int _x, int _y) {
    if (_x < 0 || _y < 0 || _x == _n || _y == _n || _map[_x][_y] == -1 || _map[_x][_y] != _act) return;
    _c++;
    _map[_x][_y] = -1;
    FF(_x+1,_y);
    FF(_x-1,_y);
    FF(_x,_y+1);
    FF(_x,_y-1);
}

vs split(string s) {
    vs r;
    string _c = "";
    for (char c : s) {
        if (c == ' ') {
            if (!_c.empty()) {
                r.emplace_back(_c);
                _c = "";
            }
        } else _c += c;
    }
    if (!_c.empty()) r.emplace_back(_c);
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool _s;
    string _ss;
    while (getline(cin, _ss) && _ss != "0") {
        _n = atoi(_ss.c_str());
        for (int i = 0; i < _n; i++)
            for (int j = 0; j < _n; j++)
                _map[i][j] = _n;
        for (int i = 1; i < _n; i++) {
            getline(cin, _ss);
            if (_ss.empty()) continue;
            vs parts = split(_ss);
            for (int j = 0; j < parts.size() - 1; j += 2) {
                _map[atoi(parts[j].c_str())-1][atoi(parts[j+1].c_str())-1] = i;
            }
        }
        _s = 1;
        memset(used, 0, sizeof used);
        for (int i = 0; i < _n && _s; i++) {
            for (int j = 0; j < _n && _s; j++) {
                if (_map[i][j] != -1) {
                    if (used[_map[i][j]]) {
                        _s = 0;
                        break;
                    }
                    _act = _map[i][j];
                    used[_map[i][j]] = 1;
                    _c = 0;
                    FF(i, j);
                    if (_c != _n) _s = 0;
                }
            }
        }
        cout << (_s ? "good" : "wrong") << "\n";
    }
    return 0;
}
