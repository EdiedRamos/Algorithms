// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

typedef vector<int> vi;

int count_swap(vi a, vi &b, int n) {
  int count = 0, idx;
  bool flag;
  int pre[n + 5];
  for (int i = 0; i < n; i++) {
    pre[b[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    flag = 0;
    for (int j = 0; j < n; j++) {
      if (a[j] != b[j]) {
        swap(a[j], a[pre[a[j]]]);
        count++;
        flag = 1;
        break;
      }
    }
    if (!flag) break;
  }
  return count;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc, n, ans;
  while (cin >> n && n) {
    ans = 1e9;
    vi d(n);
    for (int &i : d) cin >> i;
    for (int i = 1; i <= n; i++) {
      vi pre(n);
      for (int j = 0; j < n; j++) {
        pre[j] = i + j;
        if (i + j > n) {
          pre[j] = (i + j) % n;
        }
      }
      ans = min(ans, count_swap(d, pre, n));
      reverse(pre.begin(), pre.end());
      ans = min(ans, count_swap(d, pre, n));
    }
    cout << ans << endl;
  }
  return 0;
}
