//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 105
typedef vector<int> vi;

vi l_a[MN];
bool vis[MN], vis2[MN];

void DFS(int x, int T) {
    if (x == T) return;
    vis[x] = 1;
    for (int v : l_a[x]) if (!vis[v] && v != T) DFS(v, T);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc, n, st;
    cin >> tc;
    for (int _i = 1; _i <= tc; _i++) {
        cin >> n;
        int _dom[n][n];
        memset(_dom, 0, sizeof _dom);
        for (int i = 0; i < n; i++) l_a[i].clear();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cin >> st;
                if (st) l_a[i].emplace_back(j);
            }
        memset(vis, 0, sizeof vis);
        DFS(0, -1);
        for (int i = 0; i < n; i++) vis2[i] = vis[i];
        for (int i = 0; i < n; i++) {
            memset(vis, 0, sizeof vis);
            DFS(0, i);
            for (int j = 0; j < n; j++)
                if (vis[j] != vis2[j])
                    _dom[i][j] = 1;
        }
        cout << "Case " << _i << ":\n";
        for (int i = 0; i < n; i++) {
            cout << "+";
            for (int j = 0; j < (n << 1) - 1; j++) cout << "-";
            cout << "+\n";
            for (int j = 0; j < n; j++) {
                cout << "|" << (_dom[i][j]?"Y":"N");
            }
            cout << "|\n";
        }
        cout << "+";
        for (int j = 0; j < (n << 1) - 1; j++) cout << "-";
        cout << "+\n";
    }
    return 0;
}
