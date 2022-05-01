// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, sol[] = {76, 16, 56, 96, 36};
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		if (s == "0") cout << "1" << endl;
		else if (s == "1") cout << "66" << endl;
		else cout << sol[(s[s.size() - 1] - '0') % 5] << endl;
	}
	return 0;
}
