// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, _max;
  bool f = 0;
  while (cin >> n >> m) {
    map<int, int> sum;
    _max = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        sum[i + j]++;
        _max = max(_max, sum[i + j]);
      }
    }
    if (f) cout << endl;
    f = 1;
    for (auto i : sum) {
      if (_max == i.second) {
        cout << i.first << endl;
      }
    }
  }
  return 0;
}
