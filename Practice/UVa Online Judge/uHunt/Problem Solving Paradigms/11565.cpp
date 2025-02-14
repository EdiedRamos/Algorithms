// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int tc, a, b, c;

void solve() {
  for (int i = -100; i < 100; i++) {
    for (int j = i + 1; j < 100; j++) {
      for (int k = j + 1; k < 100; k++) {
        if (i + j + k == a && i * j * k == b && i * i + j * j + k * k == c) {
          cout << i << " " << j << " " << k << endl;
          return;
        }
      }
    }
  }
  cout << "No solution." << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> tc;
  while (tc--) {
    cin >> a >> b >> c;
    solve();
  }
  return 0;
}
