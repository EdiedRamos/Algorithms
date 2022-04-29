// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int sz;
	while (cin >> s && s != "0") {
		sz = s.size();
		cout << int(sqrt(sz > 1 && !(sz & 1) ? (s[0] - '0') * 10 + s[1] - '0' : s[0] - '0'));
		for (int i = 0; i < (sz - 1) >> 1; i++) cout << "0";
		cout << endl;
	}
	return 0;
}
