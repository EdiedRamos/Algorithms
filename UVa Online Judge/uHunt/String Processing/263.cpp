//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l, r, a, b;
    string s;
    set<int> _res;
    while (cin >> n && n) {
        l = 0;
        _res.clear();
        cout << "Original number was " << n << "\n";
        while (1) {
            s = to_string(n);
            sort(s.begin(), s.end(), cmp);
            a = atoi(s.c_str());
            cout << a << " - ";
            sort(s.begin(), s.end());
            b = atoi(s.c_str());
            n = a - b;
            cout << b << " = " << n << "\n";
            l++;
            if (_res.count(n)) {
                break;
            }
            _res.insert(n);
        }
        cout << "Chain length " << l << "\n\n";
    }
    return 0;
}
