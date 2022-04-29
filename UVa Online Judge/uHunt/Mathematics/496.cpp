// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

typedef vector<string> vs;

vs split(string s) {
	vs r;
	s += " ";
	string aux = "";
	for (char c : s) {
		if (c == ' ' && aux != "") {
			r.push_back(aux);
			aux = "";
		} else aux += c;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	int lA, lB;
	vs A, B;
	while (getline(cin, a)) {
		getline(cin, b);
		A = split(a);
		B = split(b);
		set<string> sA;
		set<string> sB;
		lA = A.size(), lB = B.size();
		for (string i : A) sA.insert(i);
		for (string i : B) sB.insert(i);
		for (string i : A) if (sB.find(i) != sB.end()) lA--;
		for (string i : B) if (sA.find(i) != sA.end()) lB--;
		if (!lA && !lB) cout << "A equals B" << endl;
		else if (lA && !lB) cout << "B is a proper subset of A" << endl;
		else if (!lA && lB) cout << "A is a proper subset of B" << endl;
		else if (lA == A.size() && lB == B.size()) cout << "A and B are disjoint" << endl;
		else cout << "I'm confused!" << endl;
	}
	return 0;
}
