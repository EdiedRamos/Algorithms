// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

bool isSquare(int n) {
	double x = sqrt(n);
	int xx = x;
	return xx * xx == n;
}

int solve(string s) {
	int sz = s.size(), ans = 0;
	set<string> vis = {s};
	string aux;
	for (int i = 0; i < sz; i++) {
		aux = s;
		for (int j = 0; j < 10; j++) {
			if (!j && !i) continue;
			aux[i] = j + '0';
			if (isSquare(atoi(aux.c_str())) && vis.find(aux) == vis.end()) {
				ans++;
				vis.insert(aux);
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	string s;
	cin >> t;
	for (int it = 1; it <= t; it++) {
		cin >> s;
		cout << "Case " << it << ": " << solve(s) << endl;
	}
	return 0;
}
