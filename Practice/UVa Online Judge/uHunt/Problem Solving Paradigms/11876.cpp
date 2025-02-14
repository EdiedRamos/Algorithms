// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define MN 64730

vector<int> pre(MN);

int nod(int n) {
  int r = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      if (i * i == n) {
        r++;
      } else {
        r += 2;
      }
    }
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, a, b, x, y;
  pre[0] = 1;
  for (int i = 1; i < MN; i++) {
    pre[i] = pre[i - 1] + nod(pre[i - 1]);
  }
  cin >> t;
  for (int it = 1; it <= t; it++) {
    cin >> a >> b;
    x = lower_bound(pre.begin(), pre.end(), a) - pre.begin();
    y = upper_bound(pre.begin(), pre.end(), b) - pre.begin();
    cout << "Case " << it << ": ";
    if (y < x) {
      cout << "0\n";
    } else {
      cout << y - x << "\n";
    }
  }
  return 0;
}