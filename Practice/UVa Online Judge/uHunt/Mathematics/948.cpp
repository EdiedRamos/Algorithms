//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 39

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string r;
    int t, n, aux, f[MN];
    f[0] = 1, f[1] = 2;
    for (int i = 2; i < MN; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    cin >> t;
    while (t--) {
        r = "";
        cin >> n;
        aux = n;
        if (!n) {
            r = "0";
        } else {
            for (int i = MN - 1; i >= 0; i--) {
                if (f[i] <= n) {
                    for (int j = i; j >= 0; j--) {
                        if (f[j] <= n) {
                            r += "1";
                            n -= f[j];
                        } else {
                            r += "0";
                        }
                    }
                    break;
                }
            }
        }
        cout << aux << " = " << r << " (fib)\n";
    }
    return 0;
}
