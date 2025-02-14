//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;

vs split(string s, char x, bool f) {
    vs r;
    if (f) s = s.substr(1, s.size() - 2);
    string _c = "";
    for (char c : s) {
        if (c == x) {
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
    int _t;
    string _s;
    vs _xx, _new, _remove, _change;
    cin >> _t;
    while (_t--) {
        map<string, string> _a, _b;
        _new.clear();
        _remove.clear();
        _change.clear();
        cin >> _s;
        vs pr = split(_s, ',', 1);
        for (string i : pr) {
            _xx = split(i, ':', 0);
            _a[_xx[0]] = _xx[1];
        }
        cin >> _s;
        pr = split(_s, ',', 1);
        for (string i : pr) {
            _xx = split(i, ':', 0);
            _b[_xx[0]] = _xx[1];
        }
        for (auto i : _a) {
            if (_b.find(i.first) != _b.end()) {
                if (i.second != _b[i.first]) {
                    _change.push_back(i.first);
                }
            } else {
                _remove.push_back(i.first);
            }
        }
        for (auto i : _b) {
            if (_a.find(i.first) == _a.end()) {
                _new.push_back(i.first);
            }
        }
        sort(_new.begin(), _new.end());
        sort(_remove.begin(), _remove.end());
        sort(_change.begin(), _change.end());
        if (_new.empty() && _remove.empty() && _change.empty()) {
            cout << "No changes\n";
        } else {
            if (!_new.empty()) {
                cout << "+";
                for (int i = 0; i < _new.size(); i++) {
                    if (i) {
                        cout << ",";
                    }
                    cout << _new[i];
                }
                cout << "\n";
            }
            if (!_remove.empty()) {
                cout << "-";
                for (int i = 0; i < _remove.size(); i++) {
                    if (i) {
                        cout << ",";
                    }
                    cout << _remove[i];
                }
                cout << "\n";
            }
            if (!_change.empty()) {
                cout << "*";
                for (int i = 0; i < _change.size(); i++) {
                    if (i) {
                        cout << ",";
                    }
                    cout << _change[i];
                }
                cout << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
