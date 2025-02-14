//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, _a, _b, _sc, _tc = 1;
    while (cin >> n && n) {
        map<int,vector<int>> _map;
        map<int,int> _vis;
        while (n--) {
            cin >> _a >> _b;
            _vis[_a] = -1;
            _vis[_b] = -1;
            _map[_a].emplace_back(_b);
            _map[_b].emplace_back(_a);
        }
        while (cin >> _a >> _b && _a || _b) {
            for (auto &i : _vis) i.second = -1;
            queue<int> _q;
            _q.push(_a);
            _vis[_a] = _vis[_a] + 1;
            while (!_q.empty()) {
                int _act = _q.front();
                _q.pop();
                for (int _v : _map[_act]) {
                    if (_vis[_v] == -1) {
                        _vis[_v] = _vis[_act] + 1;
                        _q.push(_v);
                    }
                }
            }
            _sc = 0;
            for (auto i : _vis)
                if (i.second == -1 || i.second > _b) _sc++;
            cout << "Case " << _tc++ << ": " << _sc << " nodes not reachable from node " << _a << " with TTL = " << _b << ".\n";
        }
    }
    return 0;
}
