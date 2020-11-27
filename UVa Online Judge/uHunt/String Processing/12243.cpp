//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    bool sp;
    set<char> sc;
    while (getline(cin, s) && s != "*") {
        sc.clear();
        sp = 1;
        for (char c : s) {
            if (sp && sp != ' ') {
                sc.insert(c & 95);
                sp = 0;
            }
            if (c == ' ') {
                sp = 1;
            }
        }
        cout << (sc.size() == 1 ? "Y\n" : "N\n");
    }
    return 0;
}
