//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, x;
    string s;
    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, s);
        x = sqrt(s.size());
        if (x * x == s.size()) { 
            for (int i = 0; i < x; i++) {
                for (int j = i; j < s.size(); j += x) {
                    cout << s[j];
                }
            }
            cout << "\n";
        } else {
            cout << "INVALID\n";
        }
    }
    return 0;
}
