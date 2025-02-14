//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 205

int n, B, W;
vector<int> lad[MN];
bool valido;
bool vis[MN];
bool color[MN];

void DFS(int v) {
    vis[v] = 1;
    if (color[v]) {
        W++;
    } else {
        B++;
    }
    for (int i : lad[v]) {
        if (!vis[i]) {
            color[i] = !color[v];
            DFS(i);
        } else {
            if (color[i] == color[v]) {
                valido = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, v, x, res;
    cin >> t;
    while (t--) {
        cin >> n;
        res = 0;
        for (int i = 1; i <= n; i++) {
            lad[i].clear();
            vis[i] = 0;
            color[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cin >> v;
            while (v--) {
                cin >> x;
                if (x > n) continue;
                lad[i].push_back(x);
                lad[x].push_back(i);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                B = W = 0;
                valido = 1;
                DFS(i);
                if (valido) {
                    res += max(B, W);
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
