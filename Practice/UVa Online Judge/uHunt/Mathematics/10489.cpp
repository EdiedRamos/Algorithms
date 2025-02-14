/*
  ░█──░█ ░█▀▀▀ ░█▀▀▀█ ░█─░█ ─█▀▀█ ░█──░█ ─█▀▀█ ░█─░█ 
  ░█▄▄▄█ ░█▀▀▀ ─▀▀▀▄▄ ░█▀▀█ ░█▄▄█ ░█▄▄▄█ ░█▄▄█ ░█▀▀█ 
  ──░█── ░█▄▄▄ ░█▄▄▄█ ░█─░█ ░█─░█ ──░█── ░█─░█ ░█─░█
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n, b, k, v, rta, sm;
  cin >> t;
  while (t--) {
    cin >> n >> b;
      sm = 0;
    while (b--) {
      cin >> k;
      rta = 1;
      while (k--) {
        cin >> v;
        rta = (rta % n * v % n) % n;
      }
      sm = (sm % n + rta % n) % n;
    }
    cout << sm << "\n";
  }
  return 0;
}
