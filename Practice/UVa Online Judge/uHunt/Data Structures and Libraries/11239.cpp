//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string,int> a, pair<string, int> b) {
    return a.second == b.second ? a.first < b.first : a.second > b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string _w, _s;
    while (getline(cin, _w) && _w[0] != '0') {
        map<string, set<string>> _d;
        vector<pair<string, int>> _r;
        map<string, vector<string>> _f;
        _d[_w];
        while (getline(cin, _s) && _s[0] != '1') {
            if (_s[0] == (_s[0] & 95)) {
                _w = _s;
                _d[_w];
            } else {
                _d[_w].insert(_s);
            }
        }
        for (auto i : _d) {
            for (auto j : i.second) {
                _f[j].emplace_back(i.first);
            }
        }
        for (auto i : _f) {
            if (i.second.size() > 1) {
                for (auto j : i.second) {
                    _d[j].erase(i.first);
                }
            }
        }
        for (auto i : _d) {
            _r.push_back({i.first, i.second.size()});
        }
        sort(_r.begin(), _r.end(), cmp);
        for (auto i : _r) {
            cout << i.first << " " << i.second << "\n";
        }
    }
    return 0;
}
