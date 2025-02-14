//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

bool Pal(int h, int m) {
    string s = to_string(h);
    if (m < 10) s += "0";
    s += to_string(m);
    int i = 0;
    for (; i < s.size() && s[i] == '0';  i++);
    s = s.substr(i, s.size() - i);
    for (i = 0; i < s.size() >> 1; i++) if (s[i] != s[s.size() - i - 1]) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, h, m;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        h = atoi(s.substr(0, 2).c_str());
        m = atoi(s.substr(3, 2).c_str());
        while (1) {
            m++;
            if (m > 59) {
                h++;
                m = 0;
            }
            if (h > 23) {
                h = 0;
            }
            if (Pal(h,m)) {
                if (h < 10) cout << "0";
                cout << h << ":";
                if (m < 10) cout << "0";
                cout << m << "\n";
                break;
            }
        }
    }
    return 0;
}
