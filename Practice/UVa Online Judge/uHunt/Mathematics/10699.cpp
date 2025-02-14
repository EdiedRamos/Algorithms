// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define MN 1000005

int factors[MN];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  for (int i = 2; i < MN; i++) {
    if (!factors[i]) {
      for (int j = i; j < MN; j += i) {
        factors[j]++;
      }
    }
  }
  while (cin >> n && n) {
    cout << n << " : " << factors[n] << "\n";
  }
  return 0;
}