// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

typedef long long int big;

#define endl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n) {
        big pos = (n + 1) >> 1;
        big factor = (pos * (pos - 1)) + (pos - 1);
        big last = (factor << 1) + 1;
        last = last + (last - 2) + (last - 4);
        cout << last << endl;
    }
    return 0;
}
