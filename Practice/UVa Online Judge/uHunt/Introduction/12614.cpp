//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    unsigned int x, m;
    cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        m = 0;
        cin >> n;
        while (n--) {
            cin >> x;
            m = max(m, x);
        }
        cout << "Case " << _i << ": " << m << "\n";
    }
    return 0;
}
