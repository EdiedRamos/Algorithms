//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

struct Dado {
    int x1, x2, y1, y2, z1, z2;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c;
    Dado _aux;
    string op;
    while (cin >> c && c) {
        Dado _d = {5, 2, 1, 6, 4, 3};
        while (c--) {
            cin >> op;
            if (op[0] == 'n') {
                _aux = _d;
                _aux.y1 = _d.x1;
                _aux.x2 = _d.y1;
                _aux.y2 = _d.x2;
                _aux.x1 = _d.y2;
                _d = _aux;
            } else if (op[0] == 's') {
                _aux = _d;
                _aux.y1 = _d.x2;
                _aux.x2 = _d.y2;
                _aux.y2 = _d.x1;
                _aux.x1 = _d.y1;
                _d = _aux;
            } else if (op[0] == 'e') {
                _aux = _d;
                _aux.y1 = _d.z2;
                _aux.z2 = _d.y2;
                _aux.y2 = _d.z1;
                _aux.z1 = _d.y1;
                _d = _aux;
            } else {
                _aux = _d;
                _aux.y1 = _d.z1;
                _aux.z1 = _d.y2;
                _aux.y2 = _d.z2;
                _aux.z2 = _d.y1;
                _d = _aux;
            }
        }
        cout << _d.y1 << "\n";
    }
    return 0;
}
