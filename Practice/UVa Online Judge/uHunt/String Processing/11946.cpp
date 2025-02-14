//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    bool j = 0;
    map<char, char> rel = {{'0', 'O'},{'1','I'},{'2','Z'},{'3','E'},{'4','A'},
                            {'5','S'},{'6','G'},{'7','T'},{'8','B'},{'9','P'}};
    string s;
    vector<string> vs;
    getline(cin, s);
    t = atoi(s.c_str());
    while (t--) {
        vs.clear();
        while (getline(cin, s) && !s.empty()) {
            vs.push_back(s);
        }
        if (j) {
            cout << "\n";
        }
        for (string _s : vs) {
            for (char _c : _s) {
                if (isdigit(_c)) {
                    cout << rel[_c];
                } else {
                    cout << _c;
                }
            }
            cout << "\n";
        }
        j = 1;
    }
    return 0;
}
