//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

void QE(string &s) {
    string x = "";
    for (char c : s) {
        if (c != ' ') {
            x += c;
        }
    }
    s = x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    string a, b;
    cin >> t;
    cin.ignore();
    for (int _i = 1; _i <= t; _i++) {
        getline(cin, a);
        getline(cin, b);
        cout << "Case " << _i << ": ";
        if (a == b) {
            cout << "Yes\n";
        } else {
            QE(a);
            QE(b);
            cout << (a == b ? "Output Format Error\n" : "Wrong Answer\n");
        }
    }
    return 0;
}
