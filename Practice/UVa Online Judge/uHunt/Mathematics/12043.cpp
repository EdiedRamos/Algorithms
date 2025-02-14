// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define MN 100005

typedef long long ll;

int d[MN], o[MN];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, a, b, k;
  ll g, h;
  for (int i = 1; i < MN; i++) {
    for (int j = i; j < MN; j += i) {
      d[j]++;
      o[j] += i;
    }
  }
  cin >> t;
  while (t--) {
    cin >> a >> b >> k;
    g = h = 0;
    if (a % k != 0) {
      a = k * (a / k + 1);
    }
    for (int i = a; i <= b; i += k) {
      g += d[i];
      h += o[i];
    }
    cout << g << " " << h << "\n";
  }
  return 0;
}