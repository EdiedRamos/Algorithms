// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pb push_back

typedef vector<string> vs;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, dif, sa, sb;
	bool between = 0, contain;
	string word;
	vs dictionary, queries, ans;
	cin >> n;
	while (n--) {
		dictionary.clear();
		while (cin >> word && word != "#") dictionary.pb(word);
		if (between) cout << endl;
		between = 1;
		while (cin >> word && word != "#") {
			sa = word.size();
			contain = 0;
			ans.clear();
			for (string s : dictionary) {
				sb = s.size();
				dif = 0;
				if (word == s) {
					contain = 1;
					break;
				}
				if (sa == sb) {
					for (int x = 0; x < sb; x++) dif += s[x] != word[x];
					if (dif == 1) ans.pb(s);
				}
				if (sa + 1 == sb || sa - 1 == sb) { 
					int idxA = 0, idxB = 0;
					while (idxA < sa && idxB < sb) {
						if (word[idxA] == s[idxB]) idxA++, idxB++;
						else {
							if (sa + 1 == sb) idxB++;
							else idxA++;
							dif++;
						}
					}
					if (dif < 2) ans.pb(s);
				}
			}
			if (contain) cout << word << " is correct" << endl;
			else {
				cout << word << ":";
				for (int i = 0; i < ans.size(); i++) cout << " " << ans[i];
				cout << endl;
			}
		}
	}
	return 0;
}
