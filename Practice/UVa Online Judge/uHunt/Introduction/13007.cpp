// coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int f(int n) {
  for (int i = 10; i <= 10000; i *= 10) {
    if (n < i) return i / 10;
  }
  return 10000;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int p, r, b, x, y;
  while (cin >> p >> r) {
    x = y = 0;
    while (r--) {
      cin >> b;
      vector<int> d(p);
      for (int &i : d) cin >> i;
      for (int i = 2; i < p; i++) {
        d[1] += d[i];
      }
      if (p > 1) b -= d[1];
      if (b > 0 && b - d[0] < 0) {
        for (int i = 10000; i > 0; i /= 10) {
          if (b - i >= 0) {
            y += i;
            break;
          }
        }
      }
      if (b - d[0] >= 0) {
        x += d[0];
        y += f(b);
      }
    }
    cout << y - x << "\n";
  }
  return 0;
}
