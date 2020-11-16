//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
vs data;
vector<vector<bool>> vis;
vector<vector<int>> mapa;
int filas, columnas;
int dx[] = {1, 0, 1, -1, 1, 0, -1, -1}, 
    dy[] = {0, 1, 1, 1, -1, -1, 0, -1};

void filtrar() {
   vs r;
   string s = "";
   for (string i : data) {
       for (char c : i) {
           if (c != ' ') {
               s += c;
           }
       }
       r.push_back(s);
       s = "";
   }
   data = r;
}

void FF(int i, int j, int t, char act) {
    if (i < 0 || j < 0 || i == filas || j == columnas || vis[i][j] || data[i][j] != act) return;
    mapa[i][j] = t;
    vis[i][j] = 1;
    for (int _i = 0; _i < 8; _i++) {
        FF(i + dx[_i], j + dy[_i], t, act);
    }
}

int Digitos(int n) {
    return (int)(log10(n));
}

void solve() {
    filtrar();
    filas = data.size();
    columnas = data[0].size();
    vis.assign(filas, vector<bool>(columnas, 0));
    mapa.assign(filas, vector<int>(columnas, 0));
    vector<int> mx(columnas);
    int start = 1;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (!vis[i][j]) {
                FF(i, j, start++, data[i][j]);
            }
        }
    }
    for (auto s : mapa) {
        for (int i = 0; i < s.size(); i++) {
            mx[i] = max(mx[i], s[i]);
        }
    }
    for (auto s : mapa) {
        for (int i = 0; i < s.size(); i++) {
            if (i) cout << " ";
            for (int j = 0; j < Digitos(mx[i]) - Digitos(s[i]); j++) cout << " ";
            cout << s[i];
        }
        cout << "\n";
    }
    cout << "%\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while (getline(cin, s)) {
        if  (s == "%") {
            solve();
            data.clear();
        } else {
            data.push_back(s);
        }
    }
    solve();
    return 0;
}
