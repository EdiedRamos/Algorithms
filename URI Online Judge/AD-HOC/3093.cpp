//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    string s;
    set<char> d;
    cin >> t;
    while (t--) {
        d.clear();
        cin >> s;
        for (char c : s) {
            if (c == 'Q' || c == 'J' || c == 'K' || c == 'A') {
                d.insert(c);
            }
        }
        cout << (d.size() == 4 ? "Aaah muleke" : "Ooo raca viu") << "\n";
    }
    return 0;
}
