//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

bool win(char a, char b) {
    return a == 'r' && b == 's' || a == 's' && b == 'p' || a == 'p' && b == 'r';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, c, a, b;
    bool _j = 0;
    string x, y;
    while (cin >> n && n) {
        cin >> k;
        vector<pair<int,int>> player(n, {0,0});
        c = (k * n * (n-1)) >> 1;
        while (c--) {
            cin >> a >> x >> b  >> y;
            if (x != y) if (win(x[0], y[0])) player[a-1].first++, player[b-1].second++; else player[a-1].second++, player[b-1].first++;
        }
        if (_j) cout << "\n";
        for (auto i : player) {
            if (i.first + i.second == 0) cout << "-\n";
            else cout << fixed << setprecision(3) << ((i.first * 1.0) / (i.first * 1.0 + i.second * 1.0)) << "\n";
        }
        _j = 1;
    }
    return 0;
}
