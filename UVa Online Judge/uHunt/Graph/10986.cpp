//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 20005
#define INF 1e9

typedef pair<int,int> pii;

vector<bool> vis;
vector<pii> lad[MN];
vector<int> dt;

int n, m, S, T, a, b, w;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        cin >> n >> m >> S >> T;
        vis.assign(n, 0);
        dt.assign(n, INF);
        for (int i = 0; i < n; i++) lad[i].clear();
        while (m--) {
            cin >> a >> b >> w;
            lad[a].push_back({b, w});
            lad[b].push_back({a, w});
        }
        dt[S] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> cola;
        cola.push({0, S});
        while (!cola.empty()) {
            auto act = cola.top();
            cola.pop();
            if (!vis[act.second]) {
                vis[act.second] = 1;
                for (auto vec : lad[act.second]) {
                    dt[vec.first] = min(dt[vec.first], dt[act.second] + vec.second);
                    if (!vis[vec.first]) {
                        cola.push({dt[vec.first], vec.first});
                    }
                }
            }
        }
        cout << "Case #" << _i << ": ";
        if (dt[T] == INF) {
            cout << "unreachable\n";
        } else {
            cout << dt[T] << "\n";
        }
    }
    return 0;
}
