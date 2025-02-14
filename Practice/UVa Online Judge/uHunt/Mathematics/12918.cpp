// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	long n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		m--;
		n = m - n;
		cout << (m * (m + 1) >> 1) - (n * (n + 1) >> 1) << endl;
	}
	return 0;
}
