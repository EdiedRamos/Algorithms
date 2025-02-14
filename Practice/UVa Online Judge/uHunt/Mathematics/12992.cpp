// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		cout << "Case #" << i << ": " << (n * 2 - 1) << endl;
	}
	return 0;
}
