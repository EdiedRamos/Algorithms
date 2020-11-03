//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 1005

int P[MN];

int F(int x, int y) {
    return P[x] == y ? 0 : F(P[x], y) + 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q, t, a, b;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        P[i] = i;
    }
    cin >> q;
    while (q--) {
        cin >> t;
        if (t < 2) {
            cin >> a >> b;
            swap(P[a], P[b]);
        } else {
            cin >> a;
            cout << F(a, a) << "\n";
        }
    }
    return 0;
}
