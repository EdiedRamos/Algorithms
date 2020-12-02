//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

bool war(char a, char b) {
    return a == 'R' && b == 'S' || a == 'S' && b == 'P' || a == 'P' && b == 'R';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, f, c, d;
    bool _j = 0;
    cin >> t;
    while (t--) {
        cin >> f >> c >> d;
        vector<vector<char>> w(f, vector<char>(c)), n(f, vector<char>(c));
        for (auto &i : w) for (char &j : i) cin >> j;
        while (d--) {
            n = w;
            for (int i = 0; i < f; i++)
                for (int j = 0; j < c; j++) {
                    if (i > 0 && war(w[i][j], w[i-1][j])) n[i-1][j] = w[i][j];
                    if (i < f - 1 && war(w[i][j], w[i+1][j])) n[i+1][j] = w[i][j];
                    if (j > 0 && war(w[i][j], w[i][j-1])) n[i][j-1] = w[i][j];
                    if (j < c - 1 && war(w[i][j], w[i][j+1])) n[i][j+1] = w[i][j];
                }
            w = n;
        }
        if (_j) cout << "\n";
        for (auto i : w) {
            for (char j : i) cout << j;
            cout << "\n";
        }
        _j = 1;
    }
    return 0;
}
