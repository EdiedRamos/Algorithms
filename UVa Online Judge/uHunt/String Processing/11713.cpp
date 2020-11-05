//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

bool Conso(char c) {
    string r = "aeiou";
    for (char x : r) {
        if (c == x) {
            return 0;
        }
    }
    return 1;
}

bool solve(string a, string b) {
    if (a.size() != b.size()) return 0;
    bool x, y;
    for (int i = 0; i < a.size(); i++) {
        x = Conso(a[i]);
        y = Conso(b[i]);
        if (x && y && a[i] != b[i] || (x ^ y)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    string a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << (solve(a, b) ? "Yes" : "No") << "\n";
    }
    return 0;
}
