// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, first, second;
	string plate;
	cin >> t;
	while (t--) {
		cin >> plate;
		first = ((plate[0] - 'A') * 26 * 26) + ((plate[1] - 'A') * 26) + (plate[2] - 'A');
		second = 0;
		for (int i = 4; i < 8; i++) second = second * 10 + (plate[i] - '0');
		cout << (abs(first - second) < 101 ? "nice" : "not nice") << endl;
	}
	return 0;
}
