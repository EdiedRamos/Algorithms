// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define MN 105
#define MM 500 * 100 + 5
#define INF 1000000000

int n, value[MN], rta, sum;
bool vis[MN][MM];

void back(int i, int s) {
  if (i == n) {
    return;
  }
  if (vis[i][s]) {
    return;
  }
  vis[i][s] = 1;
  if (s != sum) {
    rta = min(rta, abs(s - (sum - s)));
  }
  back(i + 1, s);
  back(i + 1, s - value[i]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> value[i];
      sum += value[i];
    }
    memset(vis, 0, sizeof vis);
    rta = INF;
    back(0, sum);
    cout << min(rta, sum) << "\n";
  }
  return 0;
}