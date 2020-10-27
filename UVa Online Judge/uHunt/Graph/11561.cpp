//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 55

int _f, _c, _x, _y, _g;

char _map[MN][MN];

void FF(int _i, int _j) {
    if (_i < 0 || _j < 0 || _i == _f || _j == _c || _map[_i][_j] == '#') return;
    if (_map[_i][_j] == 'G') _g++;
    _map[_i][_j] = '#';
    if (_map[_i+1][_j] == 'T' || _map[_i-1][_j] == 'T' || _map[_i][_j+1] == 'T' || _map[_i][_j-1] == 'T') return;
    FF(_i+1,_j);
    FF(_i-1,_j);
    FF(_i,_j+1);
    FF(_i,_j-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> _c >> _f) {
        for (int i = 0; i < _f; i++)
            for (int j = 0; j < _c; j++) {
                cin >> _map[i][j];
                if (_map[i][j] == 'P') _x = i, _y = j;
            }
        _g = 0;
        FF(_x, _y);
        cout << _g << "\n";
    }
    return 0;
}
