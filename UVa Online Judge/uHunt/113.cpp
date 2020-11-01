//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    double a, b, l;
    while (cin >> a >> b) {
        cout << fixed << setprecision(0) << pow(b, 1 / a) << "\n";
    }
    return 0;
}
