// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string n;
	int ans;
	while (cin >> n && n != "0") {
		ans = 0;
		for (int i = 0; i < n.size(); i++) {
			ans += (n[i] - '0') * ((1 << (n.size() - i)) - 1);
		}
		cout << ans << endl;
	}
	return 0;
}
