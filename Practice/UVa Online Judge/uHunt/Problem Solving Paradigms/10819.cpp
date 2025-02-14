// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define MN 105
#define MM 10005

const int INF = 1e9;

int n, pocket_mon, cost[MN], favour[MN], min_remain;
int dp[MN][MM];

int back(int id, int amount) {
  if (amount < 0) {
    return -INF;
  }
  if (id == n) {
    return amount > min_remain ? -INF : 0;
  }
  int &memo = dp[id][amount];
  if (~memo) {
    return memo;
  }
  return memo = max(back(id + 1, amount), back(id + 1, amount - cost[id]) + favour[id]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int aux;
  while (cin >> pocket_mon >> n) {
    for (int i = 0; i < n; i++) {
      cin >> cost[i] >> favour[i];
    }
    aux = pocket_mon;
    memset(dp, -1, sizeof dp);
    if (pocket_mon > 2000 || pocket_mon < 1801) {
      min_remain = INF;
    } else {
      min_remain = pocket_mon + 200 - 2001;
    }
    if (pocket_mon > 1800) {
      pocket_mon += 200;
    }
    int op1 = back(0, pocket_mon);
    min_remain = INF;
    memset(dp, -1, sizeof dp);
    cout << max(op1, back(0, aux)) << "\n";
  }
  return 0;
}