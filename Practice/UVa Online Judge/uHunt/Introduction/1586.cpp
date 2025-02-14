//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    string f;
    char c;
    double p;
    map<char, double> val = {{'C', 12.01}, {'H', 1.008}, {'O', 16.0}, {'N', 14.01}};
    cin >> t;
    while (t--) {
        cin >> f;
        map<char, int> cnt;
        p = 0.0;
        for (int i = 0; f[i]; i++) {
            n = 0;
            c = f[i];
            for (int j = i + 1; f[j] && isdigit(f[j]); j++) {
                n *= 10;
                n += f[j]-'0';
                i++;
            }
            if (!n) {
                cnt[c]++;
            } else {
                cnt[c] += n;
            }
        }
        for (auto i : cnt) {
            p += val[i.first] * i.second;
        }
        cout << fixed << setprecision(3) << p << "\n";
    }
    return 0;
}
