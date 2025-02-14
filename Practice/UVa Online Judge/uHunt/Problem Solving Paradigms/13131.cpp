// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, k, ans;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		ans = 0;
		for (int i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				if (i % k != 0) ans += i;
				if (i * i < n && (n / i) % k != 0) ans += n / i;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
