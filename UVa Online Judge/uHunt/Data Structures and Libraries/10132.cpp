//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string _s;
    vector<string> _f;
    int _t, _n;
    bool _j = 0;
    map<string, int> _cont;
    getline(cin, _s);
    _t = atoi(_s.c_str());
    getline(cin, _s);
    while (_t--) {
        _f.clear();
        _cont.clear();
        _n = 0;
        while (getline(cin, _s) && !_s.empty()) {
            _f.emplace_back(_s);
            _n += _s.size();
        }
        _n /= (_f.size() >> 1);
        for (int i = 0; i < _f.size(); i++) {
            for (int j = i + 1; j < _f.size(); j++) {
                _cont[_f[i]+_f[j]]++;
                _cont[_f[j]+_f[i]]++;
            }
        }
        string R;
        int M = 0;
        for (auto i : _cont) {
            if (i.second > M && i.first.size() == _n) {
                M = i.second;
                R = i.first;
            }
        }
        if (_j) cout << "\n";
        _j = 1;
        cout << R << "\n";
    }
    return 0;
}
