// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define MN 18409999

pair<int, int> twin[100003];
bool prime[MN];

void criba() {
  memset(prime, 1, sizeof prime);
  int c = 0;
  for (int i = 2; i < MN; i++) {
    if (prime[i]) {
      if (prime[i - 2]) {
        twin[c++] = {i - 2, i};
      }
      for (int j = i + i; j < MN; j += i) {
        prime[j] = 0;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  criba();
  int pos;
  while (cin >> pos) {
    cout << "(" << twin[pos + 1].first << ", " << twin[pos + 1].second << ")\n";
  }
  return 0;
}