//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

map<char, bool> vis;
map<char, vector<char>> lad;
vector<char> letters;

bool Check(char c) {
    for (char i : lad[c]) {
        if (vis[i]) {
            return 0;
        }
    }
    return 1;
}

void Back(string s) {
    if (s.size() == letters.size()) cout << s << "\n";
    for (char c : letters) {
        if (!vis[c]) {
            vis[c] = 1;
            if (Check(c)) {
                Back(s + c);
            }
            vis[c] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string st;
    bool jm = 0;
    while (getline(cin, st)) {
        vis.clear();
        lad.clear();
        letters.clear();
        for (char c : st) {
            if (c != ' ') {
                letters.push_back(c);
                vis[c] = 0;
            }
        }
        getline(cin, st);
        for (int i = 0; i < st.size(); i += 4) {
            lad[st[i]].push_back(st[i+2]);
        }
        if (jm) cout << "\n";
        sort(letters.begin(), letters.end());
        Back("");
        jm = 1;
    }
    return 0;
}
