// coder: Yeshayah

// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MN  1000002

int dp[MN];

int cycle(int n) {
  if (n < 2) {
    return 1;
  }
  if (n < MN && dp[n]) {
    return dp[n];
  }
  return dp[n < MN ? n : 0] = cycle(n & 1 ? n * 3 + 1 : n >> 1) + 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int r, x, y;
  while (cin >> x >> y) {
    cout << x << " " << y << " ";
    if (x > y) swap(x, y);
    r = 0;
    for (int i = x; i <= y; i++) {
      r = max(r, cycle(i));
    }
    cout << r << "\n";
  }
  return 0;
}
