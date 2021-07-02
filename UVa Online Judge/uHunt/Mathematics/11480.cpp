// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, mid, tc = 1;
  long long res;
  while (cin >> n && n) {
    res = 0;
    for (int r = 1; (n - (r + (r + 1))) > r + 1; r++) {
      mid = (n - r) / 2;
      mid = mid + (mid + 1) == n - r ? mid : mid - 1;
      res += mid - r;
    }
    cout << "Case " << tc++ << ": " << res << "\n";
  }
  return 0;
}