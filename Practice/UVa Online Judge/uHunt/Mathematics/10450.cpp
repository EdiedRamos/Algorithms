//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc, v;
    long long int f[55];
    f[0] = 1;
    f[1] = 2;
    for (int i = 2; i < 55; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    cin >> tc;
    for (int _i = 1; _i <= tc; _i++) {
        cin >> v;
        cout << "Scenario #" << _i << ":\n" << f[v] << "\n\n";
    }
    return 0;
}
