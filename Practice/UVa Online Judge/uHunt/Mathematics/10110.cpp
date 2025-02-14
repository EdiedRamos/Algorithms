//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned int n;
    int s;
    while (cin >> n && n) {
        s = sqrt(n);
        cout << (s * s == n ? "yes\n" : "no\n");
    }
    return 0;
}
