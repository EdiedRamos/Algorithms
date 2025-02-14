// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define MN 205

typedef long long ll;

int integers[MN], n, m, d;
ll dp[MN][15][25];

int check(int n) {
  return n + (n < 0 ? d : 0);
}

// i -> indice en el que vamos, t -> tamaño del grupo que llevamos, mod -> residulo de la suma que llevamos
ll solve(int i, int t, int mod) {
  if (t == m) {
    return mod == 0;
  }
  if (i == n) {
    return 0;
  }
  ll &memo = dp[i][t][mod];
  if (memo != -1) {
    return memo;
  }
  return memo = solve(i + 1, t, mod) + solve(i + 1, t + 1, check((mod + integers[i]) % d));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q, set = 1, query;
  while (cin >> n >> q && n || q) {
    for (int i = 0; i < n; i++) {
      cin >> integers[i];
    }
    cout << "SET " << set++ << ":\n";
    query = 1;
    while (q--) {
      cin >> d >> m;
      memset(dp, -1, sizeof dp);
      cout << "QUERY " << query++ << ": " << solve(0, 0, 0) << "\n";
    }
  }
  return 0;
}