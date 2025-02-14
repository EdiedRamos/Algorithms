// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int f, r;
  double ans;
  while (cin >> f && f) {
    cin >> r;
    vector<double> f_cluster(f), r_cluster(r);
    vector<double> ratio;
    for (double &i : f_cluster) {
      cin >> i;
    }
    for (double &i : r_cluster) {
      cin >> i;
    }
    for (int i = 0; i < f; i++) {
      for (int j = 0; j < r; j++) {
        ratio.push_back(f_cluster[i] / r_cluster[j]);
      }
    }
    sort(ratio.begin(), ratio.end());
    ans = 0.0;
    for (int i = 0; i < ratio.size() - 1; i++) {
      ans = max(ans, ratio[i + 1] /  ratio[i]);
    }
    cout << fixed << setprecision(2) << ans << "\n";
  }
  return 0;
}