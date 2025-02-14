//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

bool Check(int x, int y) {
    return (!(x & 1) && !(y & 1)) || ((x & 1) && (y & 1));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, xi, xj, yi, yj, tc, k;
    cin >> tc;
    while (tc--) {
        cin >> k >> n;
        while (k--) {
            cin >> xi >> xj >> yi >> yj;
            if (Check(xi, yi) == Check(xj, yj)) {
                if (xi == yi && xj == yj) cout << "0\n";
                else if (abs(xi - yi) == abs(xj - yj)) cout << "1\n";
                else cout << "2\n";
            } else cout << "no move\n";
        }
    }
    return 0;
}
