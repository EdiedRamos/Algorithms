// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define MN 27

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll cat[MN], scat[MN];
  int n;
  cat[0] = 1;
  scat[1] = scat[2] = 1;
  for (int i = 1; i < MN; i++) {
    cat[i] = ((2 * i * (2 * i - 1)) * cat[i - 1]) / ((i + 1) * i);
  }
  for (int i = 3; i < MN; i++) {
    scat[i] = (3 * (2 * i - 3) * scat[i - 1] - (i - 3) * scat[i - 2]) / i;
  }
  while (cin >> n) {
    cout << scat[n] - cat[n - 1] << "\n";
  }
  return 0;
}