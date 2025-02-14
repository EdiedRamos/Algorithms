//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

struct Edge {
    int w, x, y;
};

struct cmp {
    bool operator()(Edge &a, Edge &b){
        return a.w > b.w;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, _f, _c;
    Edge _act;
    cin >> t;
    int movx[] = {-1, 1, 0, 0}, movy[] = {0, 0, -1, 1};
    while (t--) {
        cin >> _f >> _c;
        vector<vector<int>> _tab(_f, vector<int>(_c)), _dt(_f, vector<int>(_c, INF));
        for (auto &i : _tab) for (int &j : i) cin >> j;
        _act = {_tab[0][0], 0, 0};
        _dt[0][0] = _tab[0][0];
        priority_queue<Edge, vector<Edge>, cmp> cola;
        cola.push(_act);
        while (!cola.empty()) {
            Edge _cu = cola.top();
            cola.pop();
            if (_cu.w > _dt[_cu.x][_cu.y]) continue;
            for (int i = 0; i < 4; i++) {
                if (_cu.x + movx[i] >= 0 && _cu.x + movx[i] < _f && _cu.y + movy[i] >= 0 && _cu.y + movy[i] < _c) {
                    if (_dt[_cu.x + movx[i]][_cu.y + movy[i]] > _dt[_cu.x][_cu.y] + _tab[_cu.x + movx[i]][_cu.y + movy[i]]) {
                        _dt[_cu.x + movx[i]][_cu.y + movy[i]] = _dt[_cu.x][_cu.y] + _tab[_cu.x + movx[i]][_cu.y + movy[i]];
                        cola.push({_dt[_cu.x + movx[i]][_cu.y + movy[i]], _cu.x + movx[i], _cu.y + movy[i]});
                    }
                }
            }
        }
        cout << _dt[_f-1][_c-1] << "\n";
    }
    return 0;
}
