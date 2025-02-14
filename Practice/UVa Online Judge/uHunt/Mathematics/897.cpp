// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define MN 10000

bool prime[MN];

bool anagram(int n) {
  if (n == 2) return 1;
  int aux = n;
  while (aux) {
    if (!((aux % 10) & 1)) return 0;
    aux /= 10;
  }
  string s = to_string(n);
  sort(s.begin(), s.end());
  do {
    n = atoi(s.c_str());
    if (prime[n]) return 0;
  } while(next_permutation(s.begin(), s.end()));
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 2; i < MN; i++) {
    if (!prime[i]) {
      for (int j = i + i; j < MN; j += i) {
        prime[j] = 1;
      }
    }
  }
  int n, power, res;
  while (cin >> n && n) {
    if (n > 1000) {
      cout << "0\n";
      continue;
    }
    power = pow(10, int(log10(n)) + 1);
    if (n > 2 && !(n & 1) || n < 3) {
      n++;
    } else {
      n += 2;
    }
    res = 0;
    for (int i = n; i < power && !res; i += 2) {
      if (anagram(i)) {
        res = i;
      }
    }
    cout << res << "\n";
  }
  return 0;
}