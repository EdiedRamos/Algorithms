//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 205
#define pb push_back

int v, e, W, B;
bool vis[MN], color[MN], can;
vector<int> la[MN];

void Pintar(int n) {
    vis[n] = 1;
    for (int v : la[n]) {
        if (!vis[v]) {
            color[v] = !color[n];
            Pintar(v);
        } else if (color[v] == color[n]) can = 0;
    }
}

void DFS(int n) {
    vis[n] = 1;
    for (int v : la[n]) {
        if (!vis[v]) {
            if (color[v]) W++;
            else B++;
            DFS(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, a, b, res;
    cin >> t;
    while (t--) {
        cin >> v >> e;
        for (int i = 0; i < v; i++) {
            la[i].clear();
        }
        while (e--) {
            cin >> a >> b;
            la[a].pb(b);
            la[b].pb(a);
        }
        memset(vis, 0, sizeof vis);
        memset(color, 0, sizeof color);
        can = 1;
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                Pintar(i);
            }
        }
        if (can) {
            memset(vis, 0, sizeof vis);
            res = 0;
            for (int i = 0; i < v; i++) {
                if (!vis[i]) {
                    B = 1;
                    W = 0;
                    DFS(i);
                    if (!B || !W) res += max(B, W);
                    else res += min(B, W);
                }
            }
            cout << res << "\n";
        } else cout << "-1\n";
    }
    return 0;
}
