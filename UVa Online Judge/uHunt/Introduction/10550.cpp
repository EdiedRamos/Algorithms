// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

int f(int a) {
  return a < 0 ? a + 40 : a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c, d;
  while (cin >> a >> b >> c >> d && a || b || c || d) {
    cout << (1080 + 9 * (f(a - b) + f(c - b) + f(c - d))) << "\n";
  }
  return 0;
}