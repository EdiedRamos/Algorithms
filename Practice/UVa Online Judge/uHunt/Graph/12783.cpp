//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 1005

vector<int> lad[MN], _num(MN), _low(MN), _parent(MN);
int _cont;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> bridges;

void Bridges(int current) {
    _num[current] = _low[current] = _cont++;
    for (int v : lad[current]) {
        if (_num[v] == -1) {
            _parent[v] = current;
            Bridges(v);
            if (_low[v] > _num[current]) {
                if (current > v) bridges.push({v, current});
                else bridges.push({current, v});
            }
            _low[current] = min(_low[current], _low[v]);
        } else if (_parent[current] != v) {
            _low[current] = min(_low[current], _num[v]);
        }
    }
}

bool cmp(pair<int,int> A, pair<int,int> B) {
    return A.first == B.first ? A.second < B.second : A.first < B.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    while (cin >> n >> m && n || m) {
        for (int i = 0; i < n; i++) {
            lad[i].clear();
            _num[i] = -1;
            _low[i] = _parent[i] = 0;
        }
        _cont = 0;
        while (m--) {
            cin >> a >> b;
            lad[a].emplace_back(b);
            lad[b].emplace_back(a);
        }
        for (int i = 0; i < n; i++) {
            if (_num[i] == -1) {
                Bridges(i);
            }
        }
        cout << bridges.size();
        while (!bridges.empty()) {
            auto x = bridges.top();
            cout << " " << x.first << " " << x.second;
            bridges.pop();
        }
        cout << "\n";
    }
    return 0;
}
