// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  unsigned int a, b, n;
  bool turn;
  while (cin >> n && n) {
    a = b = turn = 0;
    for (int i = 0; i < 32; i++) {
      if (n & (1 << i)) {
        if (turn) {
          b |= (1 << i);
        } else {
          a |= (1 << i);
        }
        turn = !turn;
      }
    }
    cout << a << " " << b << "\n";
  }
  return 0;
}