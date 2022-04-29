// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, sz, x, ans;
	while (cin >> n && n) {
		sz = 1;
		x = 1;
		ans = 0;
		while (1) {
			x <<= 1;
			if (x > n) break;
			sz++;
		}
		cout << "The parity of ";
		while (sz--) {
			ans += n & 1 << sz ? 1 : 0;
			cout << (n & 1 << sz ? 1 : 0);
		}
		cout << " is " << ans << " (mod 2)." << endl;
	}
	return 0;
}
