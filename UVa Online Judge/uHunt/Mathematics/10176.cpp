/*
  ░█──░█ ░█▀▀▀ ░█▀▀▀█ ░█─░█ ─█▀▀█ ░█──░█ ─█▀▀█ ░█─░█ 
  ░█▄▄▄█ ░█▀▀▀ ─▀▀▀▄▄ ░█▀▀█ ░█▄▄█ ░█▄▄▄█ ░█▄▄█ ░█▀▀█ 
  ──░█── ░█▄▄▄ ░█▄▄▄█ ░█─░█ ░█─░█ ──░█── ░█─░█ ░█─░█
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 131071;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  char c;
  int z, pot, memo[10005];
  string s = "";
  memo[0] = 1;
  for (int i = 1; i < 10005; i++) {
    memo[i] = (memo[i-1] % MOD * 2 % MOD) % MOD;
  }
  while (cin >> c) {
    if (c == '#') {
      if (s == "0") {
        cout << "YES\n";
        s = "";
        continue;
      }
      z = 0;
      pot = s.size() - 1;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] != '0') {
          z = (z % MOD + memo[pot] % MOD) % MOD;
        }
        pot--;
      }
      cout << (z ? "NO\n" : "YES\n");
      s = "";
    } else {
      s += c;
    }
  }
  return 0;
}
