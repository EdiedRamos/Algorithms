//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a = 0, b = 0;
    vector<int> p(6);
    for (int &i : p) cin >> i;
    a = (p[0] * 3) + p[1];
    b = (p[3] * 3) + p[4];
    if (a == b) {
        if (p[2] == p[5]) cout << "=";
        else cout << (p[2] > p[5] ? "C" : "F");
    } else cout << (a > b ? "C" : "F");
    cout << "\n";
    return 0;
}
