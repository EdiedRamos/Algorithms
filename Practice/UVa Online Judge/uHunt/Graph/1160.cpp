//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 100005

int ds[MN], _r[MN], a, b, r;

void Init() {
    for (int i = 0; i < MN; i++) {
        ds[i] = i;
        _r[i] = 1;
    }
}

int Find(int x) {
    return ds[x] = ds[x] == x ? x : Find(ds[x]);
}

void Solve() {
    int A = Find(a);
    int B = Find(b);
    if (A == B) {
        r++;
        return;
    }
    if (_r[A] < _r[B]) swap(A, B);
    ds[B] = A;
    _r[A] += _r[B];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Init();
    while (cin >> a) {
        if (a == -1) {
            cout << r << "\n";
            r = 0;
            Init();
        } else {
            cin >> b;
            Solve();
        }
    }
    return 0;
}
