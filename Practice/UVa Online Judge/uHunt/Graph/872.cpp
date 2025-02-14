//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

vector<string> all_topo;
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
    if (s.size() == letters.size()) {
        all_topo.push_back(s);
    }
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
    int tc;
    bool jm = 0;
    string st;
    getline(cin, st);
    tc = atoi(st.c_str());
    while (tc--) {
        all_topo.clear();
        lad.clear();
        vis.clear();
        letters.clear();
        getline(cin, st);
        getline(cin, st);
        for (char c : st) {
            if (c != ' ') {
                letters.push_back(c);
            }
        }
        getline(cin, st);
        for (int i = 0; i < st.size(); i += 4) {
            lad[st[i]].push_back(st[i+2]);
        }
        sort(letters.begin(), letters.end());
        Back("");
        if (jm) {
            cout << "\n";
        }
        if (all_topo.empty()) {
            cout << "NO\n";
        } else {
            for (string s : all_topo) {
                for (int i = 0; i < s.size(); i++) {
                    if (i) {
                        cout << " ";
                    }
                    cout << s[i];
                }
                cout << "\n";
            }
        }
        jm = 1;
    }
    return 0;
}
