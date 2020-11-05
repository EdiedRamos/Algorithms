//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

bool pref(string &a, string &b) {
    if (a.size() == b.size()) {
        return a == b;
    }
    if (a.size() < b.size()) {
        return a == b.substr(0, a.size());
    }
    return b == a.substr(0, b.size());
}

bool cmp(vector<string> &vs) {
    for (int i = 0; i < vs.size() - 1; i++) {
        for (int j = i + 1; j < vs.size(); j++) {
            if (pref(vs[i], vs[j])) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int _i = 1;
    vector<string> d;
    while (cin >> s) {
        if (s == "9") {
            cout << "Set " << _i++ << " ";
            if (cmp(d)) {
                cout << "is immediately decodable\n";
            } else {
                cout << "is not immediately decodable\n";
            }
            d.clear();
        } else {
            d.push_back(s);
        }
    }
    return 0;
}
