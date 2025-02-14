// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, degree, jump, d, k, aux;
  ll value;
  cin >> t;
  while (t--) {
    cin >> degree;
    vector<int> polynomial(degree + 1);
    for (int &i : polynomial) {
      cin >> i;
    }
    cin >> d >> k;
    jump = d;
    aux = 0;
    for (int i = 1; ; i++) {
      if (jump + aux >= k) {
        d = i;
        break;
      }
      aux += jump;
      jump += d;
    }
    value = 0;
    for (int i = 0; i < polynomial.size(); i++) {
      value += pow(d, i) * polynomial[i];
    }
    cout << value << "\n";
  }
  return 0;
}