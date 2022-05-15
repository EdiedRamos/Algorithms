// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

typedef vector<int> vi;

int type(vi &d) {
	set<int> si;
	for (int i : d) si.insert(i);
	return si.size();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vi d(3);
	while (cin >> d[0] >> d[1] >> d[2] && d[0] || d[1] || d[2]) {
		sort(d.begin(), d.end());
		int tt = type(d);
		if (tt == 3) {
			cout << "1 1 2" << endl;
		} else if (tt == 1) {
			if (d[0] < 13) {
				cout << d[0] + 1 << " " << d[0] + 1 << " " << d[0] + 1 << endl;
			} else {
				cout << "*" << endl;
			}
		} else {
			int a = d[1];
			int b = d[0] == a ? d[2] : d[0];
			b += b + 1 == a ? 2 : 1;
			if (b == 14) {
				b = 1;
				a++;
				if (a == 14) a = 1;
			}
			if (a < b)
				cout << a << " " << a << " " << b << endl;
			else
				cout << b << " " << a << " " << a << endl;
		}
	}	
	return 0;
}
