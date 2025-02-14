// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

bool check_eps(double x, double y) {
  return abs(x - y) < 1e-15;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c;
  double eps, op1, op2;
  while (cin >> a >> b >> eps) {
    op1 = 1.0 * a / b;
    for (int d = 1; ; d++) {
      c = 1.0 * d * a / b + 1;
      op2 = 1.0 * c / d;
      if (op2 - op1 < eps || check_eps(op2 - op1, eps)) {
        cout << c << " " << d << "\n";
        break;
      }
    }
  }
  return 0;
}