//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

bool Anagram(string a, string b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a == b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _t, _s;
	vector<string> _vs;
	string _w;
	bool _j = 0;
	cin >> _t;
	while (_t--) {
		cin >> _s;
		vector<string> _d(_s);
		for (string &s : _d) cin >> s;
		if (_j) cout << "\n";
		_j = 1;
		while (cin >> _w && _w != "END") {
			cout << "Anagrams for: " << _w << "\n";
			_vs.clear();
			for (string s : _d) {
				if (Anagram(s, _w)) {
					_vs.emplace_back(s);
				}
			}
			if (_vs.empty()) {
				cout << "No anagrams for: " << _w << "\n";
			} else {
				for (int i = 1; i <= _vs.size(); i++) {
					cout << "  " << i << ") " << _vs[i-1] << "\n";
				}
			}
		}
	}
    return 0;
}
