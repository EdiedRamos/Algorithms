#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int solve(int n, int i, int j, int left, int right) {
	if ((i & 1) && i + 1 == j) {
		return 1;
	}
	int half = (left + right) >> 1;
	if (i <= half && j > half) {
		return n;
	}
	return i <= half ? solve(n - 1, i, j, left, half) : solve(n - 1, i, j, half, right);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, i, j;
	while (cin >> n >> i >> j) {
		int round = 1;
		int power = 1;
		for (int x = 1; x <= n; x++) power <<= 1;
		int aux = i;
		i = min(i, j);
		j = max(aux, j);
		cout << solve(n, i, j, 1, power) << endl;
	}
	return 0;
}
