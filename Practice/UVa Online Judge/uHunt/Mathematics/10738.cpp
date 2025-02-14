// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define MN 1000005

vector<pair<int, int>> check(MN, {1, 0});
int mu[MN], M[MN];

int main() {
  // ios::sync_with_stdio(0);
  // cin.tie(0);
  int n;
  mu[1] = M[1] = 1;
  for (int i = 2; i < MN; i++) {
    if (check[i].first < 2) {
      for (int j = i; j < MN; j += i) {
        check[j].first *= i;
        check[j].second++;
      }
    }
    if (check[i].first == i) {
      mu[i] = (check[i].second & 1) ? -1 : 1;
    } else {
      mu[i] = 0;
    }
    M[i] = M[i - 1] + mu[i];
  }
  while (scanf("%d", &n) && n) {
    printf("%8d%8d%8d\n", n, mu[n], M[n]);
  }
  return 0;
}