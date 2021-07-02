// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll ct[20], n;
  ct[0] = 1;
  map<ll, int> pre;
  for (int i = 1; i < 20; i++) {
    ct[i] = ((2 * i * (2 * i - 1)) * ct[i - 1]) / ((i + 1) * i);
    pre[ct[i]] = i;
  }
  while (cin >> n) {
    cout << pre[n] << "\n";
  }
  return 0;
}