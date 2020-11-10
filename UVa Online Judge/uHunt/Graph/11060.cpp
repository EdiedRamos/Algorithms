//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _n, _v, _tc = 1;
    string a, b;
    while (cin >> _n) {
        int _in[_n];
        priority_queue<int,vector<int>,greater<int>> ts;
        memset(_in, 0, sizeof _in);
        map<string, int> _rel;
        map<int, string> _rel2;
        vector<int> l_ad[_n];
        for (int i = 0; i < _n; i++) {
            cin >> a;
            _rel[a] = _rel.size();
            _rel2[_rel.size()-1] = a;
        }
        cin >> _v;
        while (_v--) {
            cin >> a >> b;
            _in[_rel[b]]++;
            l_ad[_rel[a]].push_back(_rel[b]);
        }
        cout << "Case #" << _tc++ << ": Dilbert should drink beverages in this order:";
        for (int i = 0; i < _n; i++) {
            if (_in[i] == 0) {
                ts.push(i);
            }
        }
        while (!ts.empty()) {
            int _cu = ts.top();
            ts.pop();
            cout << " " << _rel2[_cu];
            for (int v : l_ad[_cu]) {
                _in[v]--;
                if (_in[v] == 0) {
                    ts.push(v);
                }
            }
        }
        cout << ".\n\n";
    }
    return 0;
}
