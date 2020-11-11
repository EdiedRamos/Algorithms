#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int numero;
	cin >> numero;
	if (numero & 1) {
		cout << "El numero es impar\n";
	} else  {
		cout << "El numero es par\n";
	}
	return 0;
}
