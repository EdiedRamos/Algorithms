// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

int n, w, _max;
string ss;
vector<int> cars_length;
bool vis[205][10005];

void back(int i, int left, int right, string opt) {
  // cout << i << " " << left << " " << right << "\n";
  // cout << i << " " << max(left, right) << "\n";
  // _max = max(_max, i);
  if (i > _max) { // tenemos una mejor opción
    ss = opt;
    _max = i;
  }
  if (i == n || left < 0 || right < 0) {
    return;
  }
  // cout << _max <<endl;
  if (vis[i][max(left, right)]) return;
  vis[i][max(left, right)] = 1;
  // cout << i << " " << left << " " << right << "\n";
  if (cars_length[i] <= left) {
    back(i + 1, left - cars_length[i], right, opt + "p");
  }
  if (cars_length[i] <= right) {
    back(i + 1, left, right - cars_length[i], opt + "s");
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, length;
  cin >> t;
  for (int it = 0; it < t; it++) {
    if (it) {
      cout << "\n";
    }
    cin >> w;
    cars_length.clear();
    while (cin >> length && length) {
      cars_length.emplace_back(length);
    }
    n = cars_length.size();
    _max = 0;
    ss = "";
    memset(vis, 0, sizeof vis);
    back(0, w * 100, w * 100, "");
    cout << _max << "\n";
    for (char c : ss) {
      if (c == 'p') {
        cout << "port\n";
      } else {
        cout << "starboard\n";
      }
    }
  }
  return 0;
}