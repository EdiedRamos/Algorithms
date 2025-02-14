//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    double a, b, c, d, p, v, mx, mn;
    while (cin >> p >> a >> b >> c >> d >> n) {
        mx = 0.0;
        mn = 0.0;
        for (int i = 1; i <= n; i++) {
            v = p * (sin(a * double(i) + b) + cos(c * double(i) + d) + 2);
            if (v > mx) {
                mx = v;
            } else {
                mn = max(mn, mx - v);
            }
        }
        cout << fixed << setprecision(6) << mn << "\n";
    }
    return 0;
}
