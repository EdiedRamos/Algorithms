//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 305

bool vis[MN], color[MN], can;
vector<int> la[MN];

void DFS(int n) {
    vis[n] = 1;
    for (int v : la[n]) {
        if (!vis[v]) {
            color[v] = !color[n];
            DFS(v);
        } else if (color[v] == color[n]) can = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int v, a, b;
    while (cin >> v && v) {
        for (int i = 0; i < v; i++) {
            la[i].clear();
            vis[i] = 0;
            color[i] = 0;
        }
        while (cin >> a >> b && a || b) {
            a--, b--;
            la[a].push_back(b);
            la[b].push_back(a);
        }
        can = 1;
        DFS(0);
        cout << (can ? "YES\n" : "NO\n");
    }
    return 0;
}
