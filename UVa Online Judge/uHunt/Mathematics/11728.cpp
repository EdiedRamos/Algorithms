// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define MN 1005

int sum[MN];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 1; i < MN; i++) {
    for (int j = i; j < MN; j += i) {
      sum[j] += i;
    }
  }
  int n, x, it = 1;
  while (cin >> n && n) {
    x = -1;
    for (int i = 1000; i > 0; i--) {
      if (sum[i] == n) {
        x = i;
        break;
      }
    }
    cout << "Case " << it++ << ": " << x << "\n";
  }
  return 0;
}