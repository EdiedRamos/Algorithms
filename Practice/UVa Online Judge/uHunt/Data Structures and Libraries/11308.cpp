//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string,int> a, pair<string, int> b) {
    return a.second == b.second ? a.first < b.first : a.second  < b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _t, _ingre, _rece, _fondo, _costo, _v, _total;
    string _carpeta, _ing, _tipo, _nombre_rece;
    cin >> _t;
    while (_t--) {
        map<string, int> _ingre_cost;
        vector<pair<string, int>> _res;
        cin.ignore();
        getline(cin, _carpeta);
        for (char &c : _carpeta) if (isalpha(c)) c &= 95;
        cout << _carpeta << "\n";
        cin >> _ingre >> _rece >> _fondo;
        while (_ingre--) {
            cin >> _ing >> _costo;
            _ingre_cost[_ing] = _costo;
        }
        while (_rece--) {
            cin.ignore();
            getline(cin, _nombre_rece);
            cin >> _ingre;
            _total = 0;
            while (_ingre--) {
                cin >> _tipo >> _v;
                _total += _ingre_cost[_tipo] * _v;
            }
            if (_total <= _fondo) {
                _res.push_back({_nombre_rece, _total});
            }
        }
        if (_res.empty()) {
            cout << "Too expensive!\n";
        } else {
            sort(_res.begin(), _res.end(), cmp);
            for (auto i : _res) {
                cout << i.first << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
