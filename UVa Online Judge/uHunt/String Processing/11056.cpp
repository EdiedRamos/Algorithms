// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

struct Info {
	string name;
	int time;
};

bool cmp(Info a, Info b) {
	for (char &c : a.name) c |= 32;
	for (char &c : b.name) c |= 32;
	return a.time == b.time ? a.name < b.name : a.time < b.time;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, min, sec, ms;
	string trash;
	while (cin >> n) {
		vector<Info> info(n);
		for (auto &i : info) {
			cin >> i.name >> trash >> min >> trash >> sec >> trash >> ms >> trash;
			min *= 60000;
			sec *= 1000;
			i.time = min + sec + ms;
		}
		sort(info.begin(), info.end(), cmp);
		for (int i = 1; i <= n; i++) {
			if (i & 1) cout << "Row " << i / 2 + 1 << endl;
			cout << info[i - 1].name << endl;
		}
		cout << endl;
	}
	return 0;
}
