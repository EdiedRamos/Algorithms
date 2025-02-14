// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, n, m, r;
	cin >> a;
	while (a--) {
		cin >> n >> m;
		m += n;
		r = ((m * (m + 1)) >> 1) + 1;
		cout << r + n << endl;
	}
	return 0;
}
