//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

struct H {
    int h, m;
};

bool Igual(H a, H b) {
    return a.h == b.h && a.m == b.m;
}

bool CC(H a, H b, H c, H d) {
    if (Igual(a, c) || Igual(a, d) || Igual(b, c) || Igual(b, d)) {
        return 1;
    }
    while (1) {
        if (c.h == a.h && c.m == a.m || d.h == a.h && d.m == a.m) {
            return 1;
        }
        if (a.h == b.h && a.m == b.m) {
            break;
        }
        a.m++;
        if (a.m > 59) {
            a.m = 0;
            a.h++;
        }
        if (a.h > 23) {
            a.h = 0;
        }
        
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    string s;
    vector<H> _t(4);
    cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        for (int i = 0; i < 4; i++) {
            cin >> s;
            _t[i].h = atoi(s.substr(0, 2).c_str());
            _t[i].m = atoi(s.substr(3, 2).c_str());
        }
        cout << "Case " << _i << ": ";
        if (CC(_t[0], _t[1], _t[2], _t[3]) || CC(_t[2], _t[3], _t[0], _t[1])) {
            cout << "Mrs Meeting\n";
        } else {
            cout << "Hits Meeting\n";
        }
    }
    return 0;
}
