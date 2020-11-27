//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    bool sa, sb;
    vector<string> m, n;
    string a, b, x, y;
    getline(cin, a);
    t = atoi(a.c_str());
    while (t--) {
        x = "";
        y = "";
        m.clear();
        n.clear();
        sa = sb = 0;
        getline(cin, a);
        getline(cin, b);
        for (char c : a) {
            if (c != '<' && c != '>') {
                x += c;
            }
            if (sa && c != '>') {
                m[m.size()-1] += c;
            }
            if (sb && c != '<') {
                n[n.size()-1] += c;
            }
            if (c == '<') {
                sa = 1;
                sb = 0;
                m.push_back("");
            }
            if (c == '>') {
                sa = 0;
                sb = 1;
                n.push_back("");
            }
        }
        for (char c : b) {
            if (c != '.') {
                y += c;
            }
        }
        cout << x << "\n" << y << m[1] << n[0] << m[0] << n[1] << "\n";
    }
    return 0;
}
