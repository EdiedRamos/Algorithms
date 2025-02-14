// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, r, d;
  while (cin >> n) {
    r = 1;
    d = 1;
    while (d % n != 0) {
      r++;
      d = d * 10 + 1;
      d %= n;
    }
    cout << r << "\n";
  }
  return 0;
}