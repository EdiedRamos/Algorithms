//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long int f[50];
    f[0] = 1, f[1] = 2;
    for (int i = 2; i < 50; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    while (cin >> n && n != -1) {
        cout << f[n]-1 << " " << f[n+1]-1 << "\n";
    }
    return 0;
}
