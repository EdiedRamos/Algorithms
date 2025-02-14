//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, m, r;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        r = 0;
        while (n > 1) {
            if (n > 1 && n < m) {
                r = -1;
                break;
            }
            n -= m - 1;
            r++;
        }
        if (r == -1) {
            cout << "cannot do this\n";
        } else {
            cout << r << "\n";
        }
    }
    return 0;
}
