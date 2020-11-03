//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 1005

int f[MN];
int R(int v, int m) {
	if (f[v] == m) return 0;
	return R(f[v], m) + 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q, t, a, b;
	cin >> n;
    for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	cin >> q;
	while (q--) {
		cin >> t;
		if (t < 2) {
			cin >> a >> b;
			swap(f[a], f[b]);
		} else {
			cin >> a;
			cout << R(a, a) << "\n";
		}
	}
    return 0;
}
