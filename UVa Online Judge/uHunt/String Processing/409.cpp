// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m;
string w, text;

string toLower(string s) {
    for (char &c : s) c &= 95;
    return s;
}

bool check(char c) {
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

int count(string xxx) {
    if (xxx.size() > text.size()) return 0;
    int c = 0;
    bool flag;
    for (int i = 0; i <= text.size() - xxx.size(); i++) {
        flag = 1;
        if ((i > 0 && check(text[i - 1])) || (i < text.size() - 1 && check(text[xxx.size() + i ]))) flag = 0;
        c += toLower(text.substr(i, xxx.size())) == toLower(xxx) && flag;
    }
    return c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int it = 1;
    while (cin >> n >> m) {
        vector<string> kw(n);
        vector<string> answer;
        int _max = 0, ans;
        for (string &s : kw) cin >> s;
        cin.ignore();
        for (int i = 0; i < m; i++) {
            getline(cin, text);
            ans = 0;
            for (string s : kw) ans += count(s);
            if (ans > _max) {
                answer.clear();
                answer.push_back(text);
                _max = ans;
            } else if (ans == _max) {
                answer.push_back(text);
            }
        }
        cout << "Excuse Set #" << it << endl;
        for (string s : answer) cout << s << endl;
        cout << endl;
        it++;
    }
    return 0;
}
