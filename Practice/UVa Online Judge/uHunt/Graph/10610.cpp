//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
#define eb emplace_back

struct Punto {
    double x, y;
};

vs split(string s) {
    vs r;
    string _c = "";
    for (char c : s) {
        if (c == ' ') {
            if (!_c.empty()) {
                r.eb(_c);
                _c = "";
            }
        } else _c += c;
    }
    if (!_c.empty()) r.eb(_c);
    return r;
}

double Distancia(Punto a, Punto b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vs _prt;
    string _s, _t;
    double v, m;
    Punto _p;
    vector<Punto> _vp;
    while (getline(cin, _s) && _s != "0 0") {
        _vp.clear();
        _prt = split(_s);
        v = stod(_prt[0]);
        m = stod(_prt[1]);
        m *= 60.0;
        while (getline(cin, _t) && !_t.empty()) {
            _prt = split(_t);
            _p.x = stod(_prt[0]);
            _p.y = stod(_prt[1]);
            _vp.eb(_p);
        }
        vector<int> l_a[_vp.size()];
        vector<int> _dt(_vp.size(), -1);
        //generar el grafo
        for (int i = 0; i < _vp.size() - 1; i++) {
            for (int j = i + 1; j < _vp.size(); j++) {
                if (Distancia(_vp[i], _vp[j]) / v <= m) {
                    l_a[i].eb(j);
                    l_a[j].eb(i);
                }
            }
        }
        //
        queue<int> _q;
        _q.push(0);
        _dt[0] = 0;
        while (!_q.empty()) {
            int _act = _q.front();
            _q.pop();
            for (int x : l_a[_act]) {
                if (_dt[x] == -1) {
                    _dt[x] = _dt[_act] + 1;
                    _q.push(x);
                }
            }
        }
        if (_dt[1] == -1) cout << "No.\n";
        else cout << "Yes, visiting " << _dt[1] - 1 << " other holes.\n";
    }
    return 0;
}
