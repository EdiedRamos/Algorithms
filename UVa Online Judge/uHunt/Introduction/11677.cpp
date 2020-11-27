//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int h1, h2, m1, m2, t;
    while (cin >> h1 >> m1 >> h2 >> m2 && h1 || m1 || h2 || m2) {
        t = (h2 - h1) * 60 + m2 - m1;
        cout << t + (t < 0 ? 1440 : 0) << "\n";
    }
    return 0;
}
