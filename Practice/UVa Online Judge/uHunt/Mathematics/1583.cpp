// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

int generator(int n) {
  int r = n;
  while (n) {
    r += n % 10;
    n /= 10;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n, gen, memo[100001];
  memset(memo, 0, sizeof memo);
  for (int i = 100000; i >= 0; i--) {
    gen = generator(i);
    if (gen > 100000) continue;
    memo[gen] = i;
  }
  cin >> t;
  while (t--) {
    cin >> n;
    cout << memo[n] << "\n";
  }
  return 0;
}